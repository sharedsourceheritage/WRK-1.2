/*=====================================================================

  File:		Cleanup.sql   
  Summary:  Unregisters the CleanupUnusedAssemblies stored procedure and 
			the assembly which contains it.
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

IF EXISTS (SELECT * FROM sys.objects WHERE name = N'CleanupUnusedAssemblies')
DROP PROCEDURE CleanupUnusedAssemblies;
GO

IF EXISTS (SELECT * FROM sys.assemblies WHERE name = N'AssemblyCleanupUtils') 
DROP ASSEMBLY AssemblyCleanupUtils;
GO

USE master;
GO
