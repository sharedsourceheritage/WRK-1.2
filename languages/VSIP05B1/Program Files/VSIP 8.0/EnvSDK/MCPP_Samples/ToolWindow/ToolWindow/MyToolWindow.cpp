#include "stdafx.h"
#include "MyToolWindow.h"

using namespace Microsoft::VisualStudio::VSIP::Samples::ToolWindowMCPP;
using namespace Microsoft::VisualStudio::Shell;

/**
*** <summary>
***        Executes a specified command or displays help for a command.
*** </summary>
*** <param name="sender">Object sending the command handling request</param>
*** <param name="e">Arguments if any that were passed</param>
**/
System::Void  MyControl::button1_Click(System::Object *  sender, System::EventArgs *  e)
{
    MessageBox::Show(this, String::Format("We are inside {0}.button1_Click()", this->ToString()), "Managed Tool Window (C++)");
}

