--**************************************************************************************
-- Date:    2/13/2003
--
-- File:    Handling LOB using ADO Net.sql for Handling LOB using ADO Net Example
--
-- Summary: Installs stored procedures for storing and retrieving large binary objects 
--          between the database and filestores.
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

CREATE PROCEDURE [Production].[usp_InsertDocument]
/* **********************************************************************************
   Date:     February 13, 2003
   Purpose:  Show how to insert a record into the database for a table that has a
             column with the new datatype varbinary(max).
   ********************************************************************************** */
     @Title AS NVARCHAR(50)
    ,@FileName AS NVARCHAR(400)
    ,@FileExtension AS NVARCHAR(8)
    ,@Status AS TINYINT
    ,@Document AS VARBINARY (MAX)
    ,@DocumentID AS INT OUTPUT
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @Count AS int;
    DECLARE @Revision AS NCHAR(5) ;
    SET @Revision = 'Rev00' ;

    BEGIN TRY
        INSERT INTO Production.Document (
            Title
            ,FileName
            ,FileExtension
            ,Revision
            ,Status
            ,Document
        ) VALUES (
            @Title
            ,@FileName
            ,@FileExtension
            ,@Revision
            ,@Status
            ,@Document
        ) ;
        
        SET @Count = @@ROWCOUNT;
        SET @DocumentID = @@IDENTITY;
        IF (@Count < 1)
            RAISERROR ('Insert failed.', 16, 1);
    END TRY
    BEGIN CATCH
        SET @DocumentID = -1;
        RETURN(1);
    END CATCH;
END  -- END of usp_InsertDocument
;
GO

CREATE PROCEDURE [Production].[usp_GetDocumentByID]
/* **********************************************************************************
   Date:     February 13, 2003
   Purpose:  Show how to retrieve a record from the database for a table that has a
             column with the new datatype varbinary(max).
   ********************************************************************************** */
    @DocumentID AS INT
AS
BEGIN
    SET NOCOUNT ON;

    SELECT 
        Document
    FROM Production.Document WHERE
        DocumentID = @DocumentID ;
END  -- END of usp_GetDocument
;
GO
