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

// pcdemo.cpp

#using <mscorlib.dll>
using namespace System;
using namespace System::Threading;

#using <System.dll>
using namespace System::Diagnostics;
using namespace System::Timers;

public ref class PCDemo
{
private:
	PerformanceCounter^ m_theCounter;
	static String^ objectName = "ACounterDemo";
	static String^ counterName = "CountPerSecond";
	static String^ instanceName = "_Total";

public:
	PCDemo()
	{
        	if ( (Environment::GetCommandLineArgs()->Length > 1) ) {
	    		if ((Environment::GetCommandLineArgs()[1]->StartsWith("/inst"))){
                		if ( true == InstallCounters() )
                    			return;
                		else
                   		   Console::WriteLine("Continuing with sample...\r\n");
	    		}
	    		else if ((Environment::GetCommandLineArgs()[1]->StartsWith("/del"))){
				PCDemo::DeleteCounters();
				return;
	    		}
	    		else {
				PCDemo::ShowUsage();
				return;
	    		}
		}
		try 
		{
		    m_theCounter = gcnew PerformanceCounter(objectName, counterName, instanceName, false);
		    m_theCounter->RawValue = 0;
		}
		catch(InvalidOperationException^) 
		{
		    
		    Console::WriteLine("The performance counters are not installed.");
		    Console::WriteLine("Please use 'pcdemo.exe /inst' to install them.");
		    return;
		}

		System::Timers::Timer^ aTimer = gcnew System::Timers::Timer();
		aTimer->Elapsed += gcnew ElapsedEventHandler(this, &PCDemo::OnTimer);

		aTimer->Interval = 100;
		aTimer->Enabled = true;
		aTimer->AutoReset = false;

		Console::WriteLine("Press \'+\' to increase the interval");
		Console::WriteLine("Press \'-\' to decrease the interval");
		Console::WriteLine("Press \'q\' to quit the sample");
		Console::WriteLine("Started");

		int command;
		do 
		{
			command = Console::Read();

			if (command == '+')
				aTimer->Interval = Math::Max(1, Convert::ToInt32(aTimer->Interval/2));

			if(command == '-')
				aTimer->Interval *= 2;

			Thread::Sleep(500);
		}
		while(command != 'q');

		
	}

	void OnTimer(Object^ source, ElapsedEventArgs^ e) 
	{
		try 
		{
			m_theCounter->Increment();

			System::Timers::Timer^ theTimer = (System::Timers::Timer^)(source);
			theTimer->Enabled = true;
		} 
		catch(ArgumentNullException^)
		{
		    Console::WriteLine("You must have Administrator privileges to run this sample.");
		}
	}
	
	bool InstallCounters()
	{
		try{
			if(!PerformanceCounterCategory::Exists(objectName)) {
				CounterCreationData^ ccd = gcnew CounterCreationData();
				ccd->CounterName = counterName;
				ccd->CounterType = PerformanceCounterType::RateOfCountsPerSecond32;

				CounterCreationDataCollection^ ccds = gcnew CounterCreationDataCollection();
				ccds->Add(ccd);

				PerformanceCounterCategory::Create(objectName, "Sample Object", PerformanceCounterCategoryType::MultiInstance, ccds);
				Console::WriteLine("Performance Counter Successfully installed.");
				return true;
			}
			else {
				Console::WriteLine("Category already installed!  ");
				return false;
			}	
		}
		catch (System::UnauthorizedAccessException^)
		{
			Console::WriteLine("You must have Administrator privileges to run this sample.");
			return(false);
		}
	}
	void DeleteCounters()
	{
           try{
    	      if(PerformanceCounterCategory::Exists(objectName)) {
				PerformanceCounterCategory::Delete(objectName);
				Console::WriteLine("Category has been successfully deleted!  ");
			  }
		   }
		   catch(System::UnauthorizedAccessException^) {
              Console::WriteLine("You must have Administrator privileges to run this sample.");
		   }
	}
	void ShowUsage()
	{
	    Console::WriteLine("Usage");
	    Console::WriteLine("-----");
            Console::WriteLine("To install perf counter AcounterDemo: pcdemo /inst");
	    Console::WriteLine("To apply changes to perf counter AcounterDemo: pcdemo");
	    Console::WriteLine("To delete perf counter AcounterDemo: pcdemo /del");
	}
};

int main(array<String^>^ argv)
{
	PCDemo^ pcdemo = gcnew PCDemo();
}




