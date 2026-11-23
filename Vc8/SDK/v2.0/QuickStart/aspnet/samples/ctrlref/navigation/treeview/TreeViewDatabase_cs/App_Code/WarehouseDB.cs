//-----------------------------------------------------------------------
//  This file is part of the Microsoft .NET SDK Code Samples.
// 
//  Copyright (C) Microsoft Corporation.  All rights reserved.
// 
//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.
// 
//THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.
//-----------------------------------------------------------------------

using System;
using System.Data;
using System.Collections;
using System.Configuration;
using System.Data.SqlClient;
using System.Web.UI;
using System.Web.UI.WebControls;

public class WarehouseDB {

    public static CategoryList GetProductCategories() {
        
        CategoryList categories = new CategoryList();
        
        String connStr = ConfigurationManager.ConnectionStrings["GrocerToGo"].ConnectionString;
        SqlDataSource mySource = new SqlDataSource(connStr, "GetCategories");
        mySource.SelectCommandType = SqlDataSourceCommandType.StoredProcedure;
        IEnumerable result = mySource.Select(DataSourceSelectArguments.Empty);
        
        foreach (DataRowView row in result) {
        
            categories.Add(new Category(
                row["CategoryId"].ToString(), 
                row["CategoryName"].ToString())
            );
        } 
        return categories;
    }

    public static ProductList GetProductsForCategory(String categoryId) {
    
        ProductList products = new ProductList();

        String connStr = ConfigurationManager.ConnectionStrings["GrocerToGo"].ConnectionString;
        SqlDataSource mySource = new SqlDataSource(connStr, "GetProductsForCategory");
        mySource.SelectCommandType = SqlDataSourceCommandType.StoredProcedure;
        mySource.SelectParameters.Add(new Parameter("catId", TypeCode.Int32, categoryId));
        IEnumerable result = mySource.Select(DataSourceSelectArguments.Empty);
        
        foreach (DataRowView row in result) {
        
            products.Add(new Product(
                row["ProductId"].ToString(), 
                row["ProductName"].ToString())
            );
        } 
        return products;
    }

}

public class Category {

    public String Id;
    public String Name;

    public Category (String id, String name) {
        this.Id = id;
        this.Name = name;
    }
}

public class CategoryList : ArrayList {

    public new Category this[int i] { 
        get { 
            return (Category)base[i]; 
        } 
        set { 
          base[i] = value; 
        } 
    }
}

public class Product {

    public String Id;
    public String Name;

    public Product (String id, String name) {
        this.Id = id;
        this.Name = name;
    }
}

public class ProductList : ArrayList {

    public new Product this[int i] { 
        get { 
            return (Product)base[i]; 
        } 
        set { 
          base[i] = value; 
        } 
    }
}

