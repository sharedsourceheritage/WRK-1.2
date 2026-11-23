/*=====================================================================

  File:		Test.sql   
  Summary:  Test the CleanupUnusedAssemblies stored procedure.
  Date:	    February 7, 2005

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

PRINT 'Before cleanup...'
SELECT [name] FROM sys.assemblies;
GO

-- pass in false, which means the cleanup will only include invisible assemblies
EXEC dbo.CleanupUnusedAssemblies false;
GO

PRINT 'After cleanup'
SELECT [name] FROM sys.assemblies;
GO

USE master;
GO
