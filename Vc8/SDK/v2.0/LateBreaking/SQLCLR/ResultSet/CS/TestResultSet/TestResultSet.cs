#region Using directives

using System;
using System.Collections.Generic;
using System.Text;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using Microsoft.SqlServer.Server;

#endregion

/*=====================================================================

  File:      TestResulSet.cs for Result Set Sample
  Summary:   Main application which increases the prices for the most popular
             bikes in order to demonstrate using server side cursors to browser
             results and update in parallel.
  Date:	     November 18, 2004

---------------------------------------------------------------------

  This file is part of the Microsoft SQL Server Code Samples.
  Copyright (C) Microsoft Corporation.  All rights reserved.

This source code is intended only as a supplement to Microsoft
Development Tools and/or on-line documentation.  See these other
materials for detailed information regarding Microsoft code samples.

THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

======================================================= */

namespace Microsoft.Samples.SqlServer
{
    public sealed class TestResultSet
    {
        //The factor to mulitply by the current price to get the new price for each color
        private const String priceIncreases = "Black, 1.02, Silver, 1.01, Red, 1.05, Yellow, 1.02, Green, 1.03";
        //Given the name of a color, return the price increase factor as a SqlMoney object.
        private static readonly Dictionary<String, SqlMoney> increaseDictionary
            = new Dictionary<String, SqlMoney>(priceIncreases.Length);

        //Don't allow construction of instances since the public portion of this class 
        //is only used to contain static methods.
        private TestResultSet()
        {
        }

        /// <summary>
        ///     The Adventure Works Cycles corporation needs to increase the standard costs and list price
        ///     for its most popular bikes due to price increases for the paint used on those bikes.  This 
        ///     program demonstrates browsing popular bikes and updating prices in parallel using 
        ///     the result set sample to implement that scenario.  Note that programmers 
        ///     should always consider whether using a JOIN in a server side query or 
        ///     update would be more efficient that using this style of programming.
        /// </summary>
        /// <param name="args">Not used</param>
        public static void Test()
        {
            //Use the priceIncreases constant to initialize entries in the increaseDictionary collection.
            InitializeIncreaseDictionary();

            SqlConnection myConnection = null;
            bool isRSOpened = false;

            //Initialize the command to get most popular bikes
			myConnection = new SqlConnection("context connection=true");
			ResultSet rs = null;
			try
			{
				myConnection.Open();
				rs = new ResultSet(myConnection,
					"SELECT TOP 10 P.ProductID, P.Name, P.Color, P.StandardCost, P.ListPrice, "
					+ "sum(SOD.OrderQty) FROM Production.Product AS P "
					+ "JOIN Sales.SalesOrderDetail AS SOD ON P.ProductID = SOD.ProductID "
					+ "JOIN Production.ProductSubcategory AS PSC "
					+ "ON P.ProductSubcategoryID = PSC.ProductSubcategoryID "
					+ "JOIN Production.ProductCategory AS PC "
					+ "ON PSC.ProductCategoryID = PC.ProductCategoryID "
					+ "WHERE PC.Name = 'Bikes' "
					+ "GROUP BY P.ProductID, P.Name, P.Color, P.StandardCost, P.ListPrice "
					+ "ORDER BY sum(SOD.OrderQty) desc;");

				//Initialize the command to update the price of a product
				SqlCommand updateCommand = myConnection.CreateCommand();
				updateCommand.CommandText = "usp_UpdateProductPrice";
				updateCommand.CommandType = CommandType.StoredProcedure;

				SqlParameter productIDParameter = new SqlParameter("@ProductID", SqlDbType.Int);
				updateCommand.Parameters.Add(productIDParameter);
				SqlParameter standardCostParameter = new SqlParameter("@StandardCost", SqlDbType.Money);
				updateCommand.Parameters.Add(standardCostParameter);
				SqlParameter listPriceParameter = new SqlParameter("@ListPrice", SqlDbType.Money);
				updateCommand.Parameters.Add(listPriceParameter);

				rs.Open();
				isRSOpened = true;

				while (rs.Read())
				{
					//Column two in the result set contains the color of the bike
					SqlMoney rateOfIncrease = increaseDictionary[rs.GetString(2)];
					//Column zero in the result set contains the product ID
					productIDParameter.Value = rs.GetInt32(0);
					//Column three in the result set contains the current standard cost
					standardCostParameter.Value = rs.GetSqlMoney(3) * rateOfIncrease;
					//Column four in the result set contains the current list price
					listPriceParameter.Value = rs.GetSqlMoney(4) * rateOfIncrease;
					//Update the prices of one of the popular bikes based 
					//on its color and current prices.  
					updateCommand.ExecuteNonQuery();
				}
			}
			finally
			{
				if (myConnection != null)
				{

					if (isRSOpened)
						rs.Close();

					myConnection.Close();
				}
			}
        }

        /// <summary>
        /// Helper function which fills the dictonary containing the price increases for each color
        /// </summary>
        static void InitializeIncreaseDictionary()
        {
            //Initialize a dictionary which contains the price increase factors for each color
            String[] splitIncreases = priceIncreases.Split(new Char[] { ',' });
            for (int i = 0; i < splitIncreases.Length - 1; i += 2)
            {
                increaseDictionary[splitIncreases[i].Trim()] = SqlMoney.Parse(splitIncreases[i + 1].Trim());
            }
        }
    }
}
