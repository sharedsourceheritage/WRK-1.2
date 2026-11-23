/*=====================================================================

  File:      installCS.sql for Store Survey sample
  Summary:   Places a survey into the Adventure Works databases.
  Date:      May 4, 2004

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

IF EXISTS (SELECT * FROM sys.procedures WHERE name = 'SaveStoreSurvey')
  DROP PROCEDURE SaveStoreSurvey;
GO

CREATE PROCEDURE SaveStoreSurvey @SID int, @Survey XML
AS
SET NOCOUNT ON;

UPDATE Sales.Store 
  SET Demographics = @Survey
  WHERE CustomerID = @SID;
GO

USE master
GO

DECLARE @UserName NVARCHAR(128)
DECLARE @UPID int
SET @UserName = SUSER_SNAME();
SELECT @UPID = principal_id FROM sys.server_principals where name = @UserName;

IF @UPID IS NULL
BEGIN
    EXEC sp_grantlogin @UserName;
END

IF NOT EXISTS(SELECT principal_id from sys.database_principals where name = @UserName)
BEGIN
    EXEC sp_grantdbaccess @UserName;
END

setuser 'dbo'

IF NOT EXISTS(SELECT * from sys.server_permissions where type = 'CRHE' and grantee_principal_id = @UPID)
BEGIN
    EXECUTE('GRANT CREATE ENDPOINT TO [' + @UserName + ']');
END
setuser @UserName

-- Drop old end point if it exists
IF EXISTS (SELECT * FROM sys.http_endpoints WHERE name = 'sql_StoreSurvey')
  DROP ENDPOINT sql_StoreSurvey; -- case sensitive
GO

CREATE ENDPOINT sql_StoreSurvey 
STATE = STARTED
AS HTTP (
      SITE = 'localhost', 
      PATH = '/StoreSurvey', 
      AUTHENTICATION = (INTEGRATED ), 
      PORTS = ( CLEAR )
)    

FOR SOAP (
        WEBMETHOD 'testns'.'SaveStoreSurvey' 
            (NAME='AdventureWorks.dbo.SaveStoreSurvey',
             SCHEMA=NONE, FORMAT=ROWSETS_ONLY ),
           WSDL = DEFAULT,
           BATCHES = ENABLED,
           DATABASE = 'AdventureWorks',
           NAMESPACE = 'myURI'
          ); 

GO


use AdventureWorks

DECLARE @UserName NVARCHAR(128)
DECLARE @UPID int
SET @UserName = SUSER_SNAME();
SELECT @UPID = principal_id FROM sys.server_principals where name = @UserName;

IF NOT EXISTS(SELECT principal_id from sys.database_principals where name = @UserName)
BEGIN
    EXEC sp_grantdbaccess @UserName;
END

EXEC('GRANT EXECUTE ON dbo.SaveStoreSurvey TO [' + @UserName + '];');
GO
