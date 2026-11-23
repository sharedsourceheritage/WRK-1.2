/*=====================================================================

  File:		Test.sql   
  Summary:  Test the CleanupUnusedAssemblies stored procedure.
  Date:	    July 08, 2005

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

PRINT 'Before cleanup...'
SELECT [name] FROM sys.assemblies;

-- pass in false, which means the cleanup will only include invisible assemblies
EXECUTE dbo.CleanupUnusedAssemblies false;

PRINT 'After cleanup'
SELECT [name] FROM sys.assemblies;

USE master;
