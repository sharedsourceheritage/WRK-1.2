CREATE PROCEDURE [UpdateContact] 
  @contactName  varchar(50),
  @original_contactID int,
  @original_contactName varchar(50)
AS
  UPDATE Contacts SET ContactName = @contactName WHERE ContactID = @original_contactID AND ContactName = @original_contactName
