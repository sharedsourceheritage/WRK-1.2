/*=====================================================================

  File:      Cleanup.sql
  Summary:   Unregisters the assembly, function, and procedures from SQL Server
			 for the InProcessDataAccess sample.
  Date:	     March 30, 2004

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

IF EXISTS (SELECT * FROM sys.procedures WHERE name = N'SendMessage')
DROP PROCEDURE SendMessage;
GO

IF EXISTS (SELECT * FROM sys.procedures WHERE name = N'SendTransientResultSet')
DROP PROCEDURE SendTransientResultSet;
GO

IF EXISTS (SELECT * FROM sys.procedures WHERE name = N'ExecuteToClient')
DROP PROCEDURE ExecuteToClient;
GO

IF EXISTS (SELECT * FROM sys.procedures WHERE name = N'SendReaderToClient')
DROP PROCEDURE SendReaderToClient;
GO

IF EXISTS (SELECT * FROM sys.objects WHERE name = N'ReportSqlVersion' and (type = 'FS' or type = 'FT'))  
DROP FUNCTION [ReportSqlVersion];
GO

IF EXISTS (SELECT * FROM sys.assemblies WHERE name = N'InProcDA') DROP ASSEMBLY InProcDA;
GO