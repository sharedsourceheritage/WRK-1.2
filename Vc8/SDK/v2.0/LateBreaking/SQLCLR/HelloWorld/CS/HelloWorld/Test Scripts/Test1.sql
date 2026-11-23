/*=====================================================================

  File:      Test.sql for HelloWorld CLR integration example
  Summary:   Invokes the usp_HelloWorld stored procedure
  Date:      February 09, 2005

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

USE [AdventureWorks];
--GO

DECLARE @Greeting nvarchar(12);

EXECUTE HelloWorld @Greeting OUTPUT;

SELECT @Greeting AS [OutputParameter];
--GO
