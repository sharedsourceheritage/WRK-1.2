CREATE PROCEDURE [GetContactsRetValAndOutParams] 
  @TimeStamp  datetime OUTPUT
AS
  select ContactID, ContactName from Contacts
  SET @TimeStamp = GetDate()
  RETURN 100
