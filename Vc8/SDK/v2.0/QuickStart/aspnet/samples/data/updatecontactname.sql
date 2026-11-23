CREATE PROCEDURE [UpdateContactName] 
  @id int,
  @name  varchar(50)
AS
  UPDATE Contacts SET ContactName = @name WHERE ContactID = @id
