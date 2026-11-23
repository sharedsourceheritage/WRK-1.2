CREATE PROCEDURE [DeleteContact] 
  @original_contactID int,
  @original_contactName varchar(50)
AS
  DELETE FROM Contacts WHERE ContactID = @original_contactID AND ContactName = @original_contactName
