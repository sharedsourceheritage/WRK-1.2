/*=====================================================================

  File:     Cleanup.sql    
  Summary:  Unregisters the assembly, aggregate, and function 
            for the string manipulate sample.
  Date:		March 30, 2004

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

IF EXISTS (SELECT * FROM sys.objects WHERE name = N'Split' and (type = 'FS' or type = 'FT'))  
DROP FUNCTION [Split];
GO

IF EXISTS (SELECT * from sys.objects WHERE name = N'Concatenate' and (type = 'AF'))  
DROP AGGREGATE [Concatenate];
GO

IF EXISTS (SELECT * FROM sys.objects WHERE name = N'RegexMatches' and (type = 'FS' or type = 'FT'))
DROP FUNCTION RegexMatches;
GO

IF EXISTS (SELECT * FROM sys.objects WHERE name = N'RegexReplace' and (type = 'FS' or type = 'FT'))
DROP FUNCTION RegexReplace;
GO

IF EXISTS (select * from sys.assemblies where name = N'StringUtilities') 
DROP ASSEMBLY StringUtilities;
GO
