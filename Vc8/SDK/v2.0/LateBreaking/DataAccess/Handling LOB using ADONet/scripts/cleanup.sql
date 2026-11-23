--**************************************************************************************
-- Date:    9/26/2003
--
-- File:    Handling LOB using ADO Net CleanUp.sql for Handling LOB using ADO Net Example
--
-- Summary: Removes stored procedures created for the use with the sample.
--
--**************************************************************************************
--
-- This file is part of the Microsoft SQL Server Code Samples.
-- Copyright (C) Microsoft Corporation.  All rights reserved.
--
-- This source code is intended only as a supplement to Microsoft
-- Development Tools and/or on-line documentation.  See these other
-- materials for detailed information regarding Microsoft code samples.
--
-- THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
-- KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
-- IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
-- PARTICULAR PURPOSE.
--
--**************************************************************************************

Use [AdventureWorks]
Go

IF OBJECT_ID('[Production].[usp_InsertDocument]', 'P') IS NOT NULL
	DROP PROCEDURE [Production].[usp_InsertDocument];
GO

IF OBJECT_ID('[Production].[usp_GetDocumentByID]', 'P') IS NOT NULL
	DROP PROCEDURE [Production].[usp_GetDocumentByID];
GO

DELETE [Production].[Document] WHERE DocumentID > 9
GO
