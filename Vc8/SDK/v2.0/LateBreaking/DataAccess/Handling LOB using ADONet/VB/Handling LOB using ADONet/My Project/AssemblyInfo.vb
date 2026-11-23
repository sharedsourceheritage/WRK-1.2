'=====================================================================
'
'  File:     AssemblyInfo.vb for Handling LOB using ADO.Net Example
'  Summary:  The purpose of this sample is to show:'
'                1) how to read binary data from a file and store the 
'                   contents into a database
'                2) how to retrieve binary data stored in the database 
'                   and write the contents to a file
'  Date:        April 14, 2003
'
'---------------------------------------------------------------------
'  This file is part of the Microsoft SQL Server Code Samples.
'  Copyright (C) Microsoft Corporation.  All rights reserved.
'
'  This source code is intended only as a supplement to Microsoft
'  Development Tools and/or on-line documentation.  See these other
'  materials for detailed information regarding Microsoft code samples.
'
'  THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
'  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'  PARTICULAR PURPOSE.
'======================================================================== 

Imports System
Imports System.Runtime.CompilerServices
Imports System.Reflection
Imports System.Runtime.InteropServices
Imports System.Security.Permissions

' General Information about an assembly is controlled through the following 
' set of attributes. Change these attribute values to modify the information
' associated with an assembly.

' Review the values of the assembly attributes

<Assembly: AssemblyTitle("Handling_LOB_using_ADONet")> 
<Assembly: AssemblyDescription("")> 
<Assembly: AssemblyCompany("Microsoft Corporation")> 
<Assembly: AssemblyProduct("Handling_LOB_using_ADONet")> 
<Assembly: AssemblyCopyright("Copyright © Microsoft Corporation 2005")> 
<Assembly: AssemblyTrademark("")> 

<Assembly: ComVisible(False)> 

'The following GUID is for the ID of the typelib if this project is exposed to COM
<Assembly: Guid("b3c12937-2272-467c-8bb4-5cdfcb9645fd")> 

' Version information for an assembly consists of the following four values:
'
'      Major Version
'      Minor Version 
'      Build Number
'      Revision
'
' You can specify all the values or you can default the Build and Revision Numbers 
' by using the '*' as shown below:

<Assembly: AssemblyVersion("1.0.0.0")> 
<Assembly: AssemblyFileVersion("1.0.0.0")> 
<Assembly: FileIOPermissionAttribute(SecurityAction.RequestMinimum, Unrestricted:=True)> 
<Assembly: CLSCompliant(True)> 
