CREATE PROCEDURE [InsertContact] 
  @contactName  varchar(50),
  @contactID int OUTPUT
AS
  INSERT INTO Contacts (ContactName) VALUES (@contactName)
  SELECT @contactID = @@IDENTITY