-- Add your test scenario here --

SELECT dbo.GetFullAssemblyName('UDTUtilities');

SELECT * FROM dbo.GetTypes(dbo.GetFullAssemblyName('UDTUtilities')); 
