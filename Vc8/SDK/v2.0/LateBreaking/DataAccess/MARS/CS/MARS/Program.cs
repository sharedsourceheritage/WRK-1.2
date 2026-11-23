#region Using directives

using System;
using System.Collections.Generic;
using System.Text;
using System.Configuration;
using System.IO;
using System.Data;
using System.Data.SqlClient;
using System.Data.SqlTypes;

#endregion

/*=====================================================================

  File:      Program.cs for Multiple Active Result Sets (MARS) Sample
  Summary:   Main application which increases the prices for the most popular
             bikes in order to demonstrate using the same connection to process
             two SQL commands in parallel.
  Date:	     September 29, 2004

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
    class Program
    {
        //The factor to mulitply by the current price to get the new price for each color
        private const String priceIncreases = "Black, 1.02, Silver, 1.01, Red, 1.05, Yellow, 1.02, Green, 1.03";
        //Given the name of a color, return the price increase factor as a SqlMoney object.
        private static readonly Dictionary<String, SqlMoney> increaseDictionary 
            = new Dictionary<String,SqlMoney>(priceIncreases.Length);

        /// <summary>
        ///     The Adventure Works Cycles corporation needs to increase the standard costs and list price
        ///     for its most popular bikes due to price increases for the paint used on those bikes.  This 
        ///     program demonstrates executing two commands at once on the same connection using the 
        ///     Multiple Active Result Sets (MARS) technology to implement that scenario.  Note that programmers
        ///     should always consider whether using a JOIN in a server side query or update would be more
        ///     efficient that using this style of programming.
        /// </summary>
        static void Main()
        {
            //Use the priceIncreases constant to initialize entries in the increaseDictionary collection.
            InitializeIncreaseDictionary();

            SqlConnection myConnection = null;
            SqlTransaction myTransaction = null;
            SqlDataReader popularBikesReader = null;
            int errorCount = 0;

            try
            {
                //Initialize the command to get most popular bikes
                myConnection
                    = new SqlConnection(Properties.Settings.Default.ConnectionString);
                SqlCommand popularBikesCommand = myConnection.CreateCommand();
                popularBikesCommand.CommandText = "usp_GetMostPopularBikes";
                popularBikesCommand.CommandType = CommandType.StoredProcedure;
                
                myConnection.Open();
                //Make sure that either all database operations succeed, 
                //or all price increases are reverted to
                //what they were before this program is invoked.
                myTransaction = myConnection.BeginTransaction();
                popularBikesCommand.Transaction = myTransaction;

                //Get the list of the most popular bikes
                popularBikesReader = popularBikesCommand.ExecuteReader();

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

                updateCommand.Transaction = myTransaction;

                while (popularBikesReader.Read())
                {
                    try
                    {
                        //Column two in the result set contains the color of the bike
                        SqlMoney rateOfIncrease = increaseDictionary[popularBikesReader.GetString(2)];
                        //Column zero in the result set contains the product ID
                        productIDParameter.Value = popularBikesReader.GetInt32(0);
                        //Column three in the result set contains the current standard cost
                        standardCostParameter.Value = popularBikesReader.GetSqlMoney(3) * rateOfIncrease;
                        //Column four in the result set contains the current list price
                        listPriceParameter.Value = popularBikesReader.GetSqlMoney(4) * rateOfIncrease;
                        Console.Write("Updating product {0} to have new standard cost of {1} and new " +
                                          "list price of {2}... ", 
                                          //Column 1 in the result set contains the name of the product
                                          popularBikesReader.GetString(1),
                                          standardCostParameter.Value.ToString(),
                                          listPriceParameter.Value.ToString());
                        //On the same connection as the currently executing query for popular bikes, update
                        //the prices of one of the popular bikes based on its color and current prices.  This
                        //would not be possible in ADO.NET 1.0.
                        updateCommand.ExecuteNonQuery();
                        Console.WriteLine("Done.");
                    }
                    catch (SqlException e)
                    {
                        Console.WriteLine("Failed! Exception: {0}", e.ToString());
                        errorCount++;
                        throw;
                    }
                }
            }
            finally
            {
                if (popularBikesReader != null)
                    popularBikesReader.Close();
                if (myConnection != null)
                {
                    if (myTransaction != null)
                    {
                        if (errorCount == 0)
                        {
                            myTransaction.Commit();
                            Console.WriteLine("All updates completed successfully.");
                        }
                        else
                        {
                            myTransaction.Rollback();
                            Console.WriteLine("{0} errors occurred.  All updates reverted.", errorCount);
                        }
                    }
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
