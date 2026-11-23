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

using System;
using System.Runtime.InteropServices;

namespace Microsoft.Samples
{
	[CLSCompliant(false)]
	[StructLayout(LayoutKind.Sequential)]
	public struct SystemTime
	{
		private ushort _year;
		private ushort _month;
		private ushort _dayOfWeek;
		private ushort _day;
		private ushort _hour;
		private ushort _minute;
		private ushort _second;
		private ushort _miliseconds;

		public ushort Year { get { return _year; } }
		public ushort Month { get { return _month; } }
		public ushort DayOfWeek { get { return _dayOfWeek; } }
		public ushort Day { get { return _day; } }
		public ushort Hour { get { return _hour; } }
		public ushort Minute { get { return _minute; } }
		public ushort Second { get { return _second; } }
		public ushort Milliseconds { get { return _miliseconds; } }

		public override bool Equals(object obj)
		{
			if (obj is SystemTime)
			{
				SystemTime sysTime = (SystemTime)obj;

				if (sysTime.Year == _year && sysTime.Month == _month && sysTime.DayOfWeek == _dayOfWeek && sysTime.Day == _day && sysTime.Hour == _hour && sysTime.Minute == _minute && sysTime.Second == _second && sysTime.Milliseconds == _miliseconds)
				{
					return true;
				}
			}

			return false;
		}

		public override int GetHashCode()
		{
			return _year ^ _month ^ _dayOfWeek ^ _day ^ _hour ^ _minute ^ _second ^ _miliseconds;
		}

		public static bool operator ==(SystemTime val1, SystemTime val2) {
			return val1.Equals(val2);
		}

		public static bool operator !=(SystemTime val1, SystemTime val2)
		{
			return !(val1.Equals(val2));
		}
	}

	public sealed class NativeMethods
	{
		private NativeMethods() { }

		[DllImport("Kernel32.dll")]
		internal static extern void GetSystemTime(ref SystemTime sysTime);

		[DllImport("User32.dll", EntryPoint = "MessageBox", CharSet = CharSet.Auto)]
		internal static extern int MsgBox(int hWnd, String text, String caption, uint type);
	}

	public sealed class TestPInvoke
	{
		private TestPInvoke() { }

		public static void Main()
		{
			SystemTime sysTime = new SystemTime();

			NativeMethods.GetSystemTime(ref sysTime);

			String date = String.Format("System time is: \nYear: {0}\nMonth: {1}\nDayOfWeek: {2}\nDay: {3}", sysTime.Year, sysTime.Month, sysTime.DayOfWeek, sysTime.Day);

			NativeMethods.MsgBox(0, date, "PInvoke Sample", 0);
		}
	}
}
