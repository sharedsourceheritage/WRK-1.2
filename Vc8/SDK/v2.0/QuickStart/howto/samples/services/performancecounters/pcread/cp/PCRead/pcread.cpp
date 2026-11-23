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

// pcread.cpp

#using <mscorlib.dll>
using namespace System;
using namespace System::Threading;

#using <System.dll>
using namespace System::Diagnostics;
using namespace System::Timers;

public ref class PCRead
{
private:
	String^ m_instanceName;
	PerformanceCounter^ m_theCounter;

public:
	PCRead(String^ objectName, String^ counterName, String^ instanceName)
	{
		m_instanceName = instanceName;

		if ( !PerformanceCounterCategory::Exists(objectName) )
		{
			Console::WriteLine(String::Concat("Object ", objectName, " does not exists!"));
			return;
		}

		if ( !PerformanceCounterCategory::CounterExists(counterName, objectName) )
		{
			Console::WriteLine(String::Concat("Counter ", counterName, " does not exists!"));
			return;
		}

		m_theCounter = gcnew PerformanceCounter(objectName, counterName, m_instanceName);

		System::Timers::Timer^ aTimer = gcnew System::Timers::Timer();
		aTimer->Elapsed += gcnew ElapsedEventHandler(this, &PCRead::OnTimer);

		aTimer->Interval = 500;
		aTimer->Enabled = true;
		aTimer->AutoReset = false;

		Console::WriteLine("Press \'q\' and hit Enter to quit the sample");
		while ( Console::Read() != 'q' ) 
		{
			Thread::Sleep(500);
		}
	}

	void OnTimer(Object^ source, ElapsedEventArgs^ e)
	{
		try 
		{
			Console::WriteLine(String::Concat("Current value =  ", m_theCounter->NextValue().ToString()));
		} 
		catch(Exception^ e)
		{
			Console::WriteLine(String::Concat("Instance ", m_instanceName, " does not exist!"));
			Console::WriteLine(String::Concat("Exception Message : ", e->Message) );
			return;
		}
		catch (System::Object^){
			Console::WriteLine("An error occurred performing the operation");
		}

		System::Timers::Timer^ theTimer = (System::Timers::Timer^)(source);
		theTimer->Enabled = true;
	}
};

int main(array<String^>^ argv)
{
	if ( argv->Length != 2 && argv->Length != 3 )
	{
		Console::WriteLine(String::Concat("Usage: ", " <object> <counter> [<instance>]"));
		return 0;
	}

	String^ objectName = argv[0];
	String^ counterName = argv[1];
	String^ instanceName = "";
	if ( argv->Length == 3 )
		instanceName = argv[2];

	PCRead^ pcread = gcnew PCRead(objectName, counterName, instanceName);
}







