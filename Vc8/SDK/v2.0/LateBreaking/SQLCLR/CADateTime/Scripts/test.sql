/*=====================================================================

  File:      test.sql for calendar aware date time sample
  Summary:   Demonstrates how to use the CADateTime UDT.
  Date:	     August 4, 2004

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

SELECT CADateTime::CurrentCalendarName;

-- Simple usage, create a new value from a string and print it out
-- We're using ISO 8601 format dates as input, which are YYYY-MM-DD
DECLARE @h CADateTime;
SET @h = '1976-01-02';
SELECT CAST(@h as nvarchar(128)), @h.CalendarName;
GO

-- print it out in "full format"
DECLARE @h CADateTime;
SET @h = '1976-01-02';
SELECT @h.ToGregorianStringUsingFormat('F');
GO

-- print it out in a custom format
DECLARE @h CADateTime;
SET @h = '1976-01-02';
SELECT @h.ToGregorianStringUsingFormat('MMM dd yyyy');
GO

-- convert it to arabic (for testing purposes)
DECLARE @h CADateTime;
SET @h = CADateTime::Parse('1976-01-02');
SELECT @h.ToString(), @h.ToGregorianStringUsingFormat('F');
GO

-- convert sql datetime to CAD and back
DECLARE @h CADateTime;
SET @h = CADateTime::FromSqlDateTime(GetDate());
SELECT @h.ToString(), @h.ToSqlDateTime();
GO

-- get the current CAD, in two ways
SELECT   CADateTime::Now.ToString(), 
    CADateTime::FromSqlDateTime(GetDate()).ToString();
GO

-- do some arithmetic
DECLARE @h CADateTime, @d datetime;
SET @h = CADateTime::Now; -- get the current hijri datetime
SET @h = @h.AddDays(10); -- add ten days to it
SET @d = GetDate(); -- current sql date
SET @d = DateAdd(day, 10, @d); -- add ten days to the sql datetime
-- print 'em both, should be the same
SELECT @h.ToSqlDateTime(), @d;
GO

-- what about datepart
DECLARE @h CADateTime;
SET @h = CADateTime::Now; -- get the current datetime
SELECT @h.Year as year, @h.Month as month, @h.Day as dayofyear, @h.DayOfMonth as dom;
GO

-- print the same date in four different calendars
SELECT 
    CADateTime::FromSqlDateTimeAndCalendar(GetDate(), 'UmAlQuraCalendar').ToString() as Umq,
    CADateTime::FromSqlDateTimeAndCalendar(GetDate(), 'GregorianCalendar').ToString() as Gregorian,
    CADateTime::FromSqlDateTimeAndCalendar(GetDate(), 'JapaneseCalendar').ToString() as Japanese,
    CADateTime::FromSqlDateTimeAndCalendar(GetDate(), 'ChineseLunisolarCalendar').ToString() as ChineseLunisolar;
GO

SELECT CADate::CurrentCalendarName;

-- simple usage, create a new value from a string and print it out
DECLARE @h CADate;
SET @h = '1976-01-02';
SELECT CAST(@h as nvarchar(128)), @h.CalendarName;
GO

-- print it out in "date format"
DECLARE @h CADate;
SET @h = '1976-01-02';
SELECT @h.ToGregorianStringUsingFormat('d');
GO

-- print it out in a custom format
DECLARE @h CADate;
SET @h = '1976-01-02';
SELECT @h.ToGregorianStringUsingFormat('MMM dd yyyy');
GO

-- convert it to arabic (for testing purposes)
DECLARE @h CADate;
SET @h = CADate::Parse('1976-01-02');
SELECT @h.ToString(), @h.ToGregorianStringUsingFormat('d');
GO

-- convert sql datetime to CAD and back
DECLARE @h CADate;
SET @h = CADate::FromSqlDateTime(GetDate());
SELECT @h.ToString(), @h.ToSqlDateTime();
GO

-- get the current CAD, in two ways
SELECT   CADate::Now.ToString(), 
    CADate::FromSqlDateTime(GetDate()).ToString();
GO

-- do some arithmetic
DECLARE @h CADate, @d datetime;
SET @h = CADate::Now; -- get the current hijri datetime
SET @h = @h.AddDays(10); -- add ten days to it
SET @d = GetDate(); -- current sql date
SET @d = DateAdd(day, 10, @d); -- add ten days to the sql datetime
-- print 'em both, should be the same
SELECT @h.ToSqlDateTime(), @d;
GO

-- what about datepart
DECLARE @h CADate;
SET @h = CADate::Now; -- get the current datetime
SELECT @h.Year as year, @h.Month as month, @h.Day as dayofyear, @h.DayOfMonth as dom;
GO

-- print the same date in four different calendars
SELECT 
    CADate::FromSqlDateTimeAndCalendar(GetDate(), 'UmAlQuraCalendar').ToString() as Umq,
    CADate::FromSqlDateTimeAndCalendar(GetDate(), 'GregorianCalendar').ToString() as Gregorian,
    CADate::FromSqlDateTimeAndCalendar(GetDate(), 'JapaneseCalendar').ToString() as Japanese,
    CADate::FromSqlDateTimeAndCalendar(GetDate(), 'ChineseLunisolarCalendar').ToString() as ChineseLunisolar;
GO

-- Show the total sales figures for particular days of the year over a 90 day 
-- range starting with day 90.
SELECT DayOfYear, SUM(TotalDue)
FROM [Sales].[SalesSummary]
WHERE DayOfYear >= 90 AND DayOfYear < 180
GROUP BY DayOfYear
ORDER BY DayOfYear;
GO

-- Show the first day of the year where there is sales between day 90 and day 180.
SELECT TOP 1 DayOfYear 
FROM [Sales].[SalesSummary]
WHERE DayOfYear >= 90 AND DayOfYear < 180 
ORDER BY DayOfYear ASC
GO

SET LANGUAGE French
GO

-- print the same date in four different calendars using the French culture
SELECT 
    CADate::FromSqlDateTimeAndCalendar(GetDate(), 'UmAlQuraCalendar').ToString() as Umq,
    CADate::FromSqlDateTimeAndCalendar(GetDate(), 'GregorianCalendar').ToString() as Gregorian,
    CADate::FromSqlDateTimeAndCalendar(GetDate(), 'JapaneseCalendar').ToString() as Japanese,
    CADate::FromSqlDateTimeAndCalendar(GetDate(), 'ChineseLunisolarCalendar').ToString() as ChineseLunisolar;
GO

SET LANGUAGE us_english
GO
