/*=====================================================================

  File:     Cleanup.sql 
  Summary:  Unregisters the assembly, UDT, and functions which provide metadata about SQLCLR
            user defined types in SQL Server.
  Date:		June 3, 2004

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

if exists (select * from sys.procedures where [name] = 'usp_LoadTest')
drop procedure usp_LoadTest;
GO

if exists (select * from sys.objects where name = N'GetTypes' and (type = 'FS' or type = 'FT'))  
drop function [GetTypes];
GO

if exists (select * from sys.objects where name = N'GetFields' and (type = 'FS' or type = 'FT'))  
drop function [GetFields];
GO

if exists (select * from sys.objects where name = N'GetProperties' and (type = 'FS' or type = 'FT'))  
drop function [GetProperties];
GO

if exists (select * from sys.objects where name = N'GetMethods' and (type = 'FS' or type = 'FT'))  
drop function [GetMethods];
GO

if exists (select * from sys.objects where name = N'GetFullAssemblyName' and (type = 'FS' or type = 'FT'))  
drop function [GetFullAssemblyName];
GO

if exists (select * from sys.objects where name = N'GetLoadedAssemblies' and (type = 'FS' or type = 'FT'))  
drop function [GetLoadedAssemblies];
GO

if exists (select * from sys.objects where name = N'GetClrTypeName' and (type = 'FN' or type = 'FS' or type = 'FT'))  
drop function [GetClrTypeName];
GO

if exists (select * from sys.types where name = N'SimpleUdt')
drop type SimpleUdt;
GO

if exists (select * from sys.assemblies where name = N'UDTUtilities') 
drop assembly UDTUtilities;
GO
