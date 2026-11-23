//-----------------------------------------------------------------------
//  This file is part of the Microsoft .NET Framework SDK Code Samples.
// 
//  Copyright (C) Microsoft Corporation.  All rights reserved.
// 
//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.
// 
//THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.
//-----------------------------------------------------------------------

using namespace System;
using namespace System::Runtime::InteropServices;



[StructLayout(LayoutKind::Sequential)]
public ref struct SystemTime
{
 unsigned short wYear;
 unsigned short wMonth;
 unsigned short wDayOfWeek;
 unsigned short wDay;
 unsigned short wHour;
 unsigned short wMinute;
 unsigned short wSecond;
 unsigned short wMiliseconds;
};

public ref class Win32 
{
public:
        [DllImport("Kernel32.dll")]
        static void GetSystemTime(SystemTime^ sysTime);
        
	[DllImport("User32.dll", EntryPoint="MessageBox", CharSet=CharSet::Auto)]
        static int MsgBox(int hWnd, String^ text, String^ caption, unsigned int type);
};

void main()
{
	SystemTime^ sysTime = gcnew SystemTime();
	Win32^ w = gcnew Win32;
	w -> GetSystemTime(sysTime);

	String^ date = String::Concat(String::Concat("System time is: \nYear: ", sysTime->wYear.ToString(), 
		"\nMonth: ", sysTime->wMonth.ToString()),
		String::Concat("\nDayOfWeek: ", sysTime->wDayOfWeek.ToString(),
		"\nDay: ", sysTime->wDay.ToString()));

	w -> MsgBox(0, date, "PInvoke Sample", 0);
}
  
