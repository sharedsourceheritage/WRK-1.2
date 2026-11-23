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
#using <Interop.SHDocVw.dll>

ref struct Handlers {
static void OnTitleChange(String^ text)
{
   Console::WriteLine("Title changes to {0}", text);
}
};

void main()
{
   Interop::SHDocVw::InternetExplorer^ explorer = gcnew Interop::SHDocVw::InternetExplorerClass;
   Interop::SHDocVw::IWebBrowserApp^ webBrowser = safe_cast<Interop::SHDocVw::IWebBrowserApp ^>(explorer);
            
   //Title Change event
   Interop::SHDocVw::DWebBrowserEvents2_TitleChangeEventHandler^ dTitleChange
	   = gcnew Interop::SHDocVw::DWebBrowserEvents2_TitleChangeEventHandler(&Handlers::OnTitleChange);
   dynamic_cast<Interop::SHDocVw::InternetExplorerClass ^>(explorer)->TitleChange += dTitleChange;    
                        
   webBrowser->Visible = true;
   webBrowser->GoHome();    
            
   Console::WriteLine("Press Enter to quit");    
   String^ s = Console::ReadLine();    
                   
                
   try 
   {
      webBrowser->Quit();
   }
   catch(COMException ^)    
   {
      Console::WriteLine("Explorer closed");
   }        
}

    
 


  
