/*=====================================================================

  File:		test.sql    
  Summary:  Tests the aggregate, and function 
            for the string manipulate sample.
  Date:     June 3, 2004

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

-- Invoke the tvf
SELECT * FROM dbo.Split('will,this,work');
GO

-- Invoke the aggregate over the results of the tvf
SELECT dbo.Concatenate(StringElement) FROM dbo.Split('will,this,also,work');
GO

-- Find two word pairs where the first word contains an 'r'
SELECT MatchID, MatchIndex, MatchValue, 
  GroupID, GroupIndex, GroupValue, 
  CaptureIndex, CaptureValue
FROM dbo.RegexMatches('The quick red fox jumped over the lazy brown dog', '(\w*r\w*)\s(\w+)');
GO

-- A variant of the above with no backtracking
SELECT MatchID, MatchIndex, MatchValue, 
  GroupID, GroupIndex, GroupValue, 
  CaptureIndex, CaptureValue
FROM dbo.RegexMatches('The quick red fox jumped over the lazy brown dog', '(?>\w*r\w*)\s(?>\w+)');
GO

-- Swap the subject of the sentence with the object of the sentence.
SELECT dbo.RegexReplace('The quick red fox jumped over the lazy brown dog', 
						'^The (?<fox>(?:[\w]+\s){3})jumped over the (?<dog>(?:[\w]+\s){2}(?:[\w]+))$',
						'The ${dog} jumped over the ${fox}');


						 

