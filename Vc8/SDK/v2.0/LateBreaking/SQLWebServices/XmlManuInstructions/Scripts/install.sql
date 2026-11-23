/*=====================================================================

  File:      install.sql for Manufacturing Instructions XML Example
  Summary:   Retrieves manufacturing instructions from the Adventure Works databases.
  Date:      February 11, 2004

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

IF EXISTS (SELECT * FROM sys.procedures WHERE name = 'GetManuInstructions')
  DROP PROCEDURE GetManuInstructions;
GO

CREATE PROCEDURE GetManuInstructions
    @ProductModelID int 
AS  
SET NOCOUNT ON;

DECLARE @x xml;
SELECT @x = Instructions.query('declare namespace x="http://schemas.microsoft.com/sqlserver/2004/07/adventure-works/ProductModelManuInstructions";
    /x:root') 
FROM Production.ProductModel
WHERE ProductModelID = @ProductModelID;

DECLARE @ModelName varchar(40);
SET @ModelName = (SELECT Name
    FROM Production.ProductModel
    WHERE ProductModelID = @ProductModelID);

SET @x.modify('declare namespace AWMI="http://schemas.microsoft.com/sqlserver/2004/07/adventure-works/ProductModelManuInstructions";
    insert attribute ProductModelName { sql:variable("@ModelName") }
    into /AWMI:root[1]');

SET @x.modify('declare namespace AWMI="http://schemas.microsoft.com/sqlserver/2004/07/adventure-works/ProductModelManuInstructions";
    insert attribute ProductModelID { sql:variable("@ProductModelID") }
    into /AWMI:root[1]');

SELECT @x AS x;
GO

USE master;
GO

-- Drop old end point if it exists
IF EXISTS (SELECT * FROM sys.http_endpoints WHERE name = 'sql_AdvWorksEndPointManuInstructions')
    DROP ENDPOINT sql_AdvWorksEndPointManuInstructions -- case sensitive;
GO


-- create end point
CREATE ENDPOINT sql_AdvWorksEndPointManuInstructions
    STATE = STARTED
AS HTTP
(
    SITE = 'localhost', 
    PATH = '/ManuInstructions', 
    AUTHENTICATION = (INTEGRATED ), 
    PORTS = ( CLEAR ) 
)
FOR SOAP (
    WEBMETHOD 'testns'.'GetManuInstructions' 
        (name='AdventureWorks.dbo.GetManuInstructions', schema=STANDARD ),
        WSDL = DEFAULT,
        BATCHES = DISABLED,
        DATABASE = 'AdventureWorks',
        NAMESPACE = 'myURI'
        );
GO

USE AdventureWorks;
GO

-- Capture the OS version in a temp table so that we can pick 
-- the correct windows account to grant access to for the objects 
-- defined in this file.  This enables ASP.NET programs to access 
-- these objects.
CREATE TABLE #GetVersionValues
(
	[Index]	int,
	[Name]	sysname,
	Internal_value	int,
	Character_Value	sysname
);
GO

INSERT #GetVersionValues
EXEC master.dbo.xp_msver 'WindowsVersion';
GO

DECLARE @OSVersion decimal(9, 2);
DECLARE @ASPUserName nvarchar(100);
DECLARE @NetworkService nvarchar(100);

-- For globalization purposes, the sample install script uses a SID to set NT AUTHORITY\NETWORK SERVICE
-- SELECT SUSER_SID('NT AUTHORITY\NETWORK SERVICE') returns the English SID. 
SET @NetworkService = SUSER_SNAME(0x010100000000000514000000);

SELECT @OSVersion = CONVERT(decimal(9, 2), SUBSTRING(Character_Value, 1, CHARINDEX(' ', Character_Value) - 1)) 
FROM #GetVersionValues;

-- IIS6 uses a different account to run web apps under.  II6 first shipped with Windows 2003 (v5.2).
IF (@OSVersion < 5.20) 
	SET @ASPUserName = @@ServerName + N'\ASPNET';
ELSE
	SET @ASPUserName = @NetworkService;

IF NOT EXISTS(SELECT principal_id FROM sys.server_principals where name = @ASPUserName)
BEGIN
    EXEC sp_grantlogin @ASPUserName;
END

IF NOT EXISTS(SELECT principal_id from sys.database_principals where name = @ASPUserName)
BEGIN
    EXEC sp_grantdbaccess @ASPUserName;
END

EXEC ('GRANT SELECT ON Production.Illustration TO [' + @ASPUserName + '];');
GO

DROP TABLE #GetVersionValues;
GO


