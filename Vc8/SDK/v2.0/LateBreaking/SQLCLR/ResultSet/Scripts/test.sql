/*=====================================================================

  File:      test.sql for result set sample
  Summary:   Demonstrates how to use the result set class.
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
USE AdventureWorks
GO

SELECT TOP 10 P.ProductID, P.Name, P.Color, P.StandardCost, P.ListPrice, sum(SOD.OrderQty) FROM Production.Product AS P
JOIN Sales.SalesOrderDetail AS SOD ON P.ProductID = SOD.ProductID
JOIN Production.ProductSubcategory AS PSC ON P.ProductSubcategoryID = PSC.ProductSubcategoryID
JOIN Production.ProductCategory AS PC ON PSC.ProductCategoryID = PC.ProductCategoryID
WHERE PC.Name = 'Bikes'
GROUP BY P.ProductID, P.Name, P.Color, P.StandardCost, P.ListPrice 
ORDER BY sum(SOD.OrderQty) desc;
GO

EXEC usp_RSTest
GO

SELECT TOP 10 P.ProductID, P.Name, P.Color, P.StandardCost, P.ListPrice, sum(SOD.OrderQty) FROM Production.Product AS P
JOIN Sales.SalesOrderDetail AS SOD ON P.ProductID = SOD.ProductID
JOIN Production.ProductSubcategory AS PSC ON P.ProductSubcategoryID = PSC.ProductSubcategoryID
JOIN Production.ProductCategory AS PC ON PSC.ProductCategoryID = PC.ProductCategoryID
WHERE PC.Name = 'Bikes'
GROUP BY P.ProductID, P.Name, P.Color, P.StandardCost, P.ListPrice 
ORDER BY sum(SOD.OrderQty) desc;
GO

