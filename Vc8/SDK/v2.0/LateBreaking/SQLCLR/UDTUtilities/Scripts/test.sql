/*=====================================================================

  File:     Test.sql 
  Summary:  Tests a UDT and the functions which provide metadata about SQLCLR
            user defined types in SQL Server.
  Date:     June 3, 2004

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

-- Get the full CLR name for UDTUtilities
SELECT dbo.GetFullAssemblyName(N'UDTUtilities');
GO

-- Get all the types in this dll
SELECT * FROM dbo.GetTypes(dbo.GetFullAssemblyName(N'UDTUtilities')); 
GO

-- Get the full CLR name for SimpleUdt
SELECT dbo.GetClrTypeName('SimpleUdt');
GO

-- Get the methods on the SimpleUdt type
SELECT * FROM dbo.GetMethods(dbo.GetClrTypeName('SimpleUdt'));
GO

-- More complex query to dump all the methods for all the types in the system
SELECT 
    st.name AS TypeName, 
    methods.Name AS MethodName, 
    methods.Parameters, 
    methods.Type, 
    methods.RoutineProperties 
FROM sys.assembly_types st 
    CROSS APPLY dbo.GetMethods(dbo.GetClrTypeName(st.name)) methods
GO
