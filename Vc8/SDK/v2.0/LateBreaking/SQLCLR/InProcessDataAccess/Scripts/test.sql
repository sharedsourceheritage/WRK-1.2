/*=====================================================================

  File:      test.sql
  Summary:   Tests the function and procedures 
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

USE AdventureWorks;
GO

-- send a message to the client
EXEC SendMessage 'This is a test message.';

-- exec a function that does data access
SELECT dbo.ReportSqlVersion();

-- exec the proc that sends a result set to the client
EXEC SendTransientResultSet;

EXEC ExecuteToClient;

EXEC SendReaderToClient;

USE master;
GO
