#include "stdafx.h"
#include "VsPkg.h"
#include "Guids.h"
#include "PkgCmdID.h"
#include "MyToolWindow.h"

using namespace System::ComponentModel::Design;

//VsPackage methods
////////////////////

/**
*** <summary>
***        Closes the VSPackage, releases cached interface pointers, and unadvises event sinks.
*** </summary>
**/
void Microsoft::VisualStudio::VSIP::Samples::ToolWindowMCPP::ToolWindow::Dispose(bool disposing)
{
    Trace::WriteLine ("Entering Dispose() of: {0}", this->ToString());

    if ( disposing && windowFrame )
    {
        windowFrame->CloseFrame(__FRAMECLOSE::FRAMECLOSE_SaveIfDirty);
    }
    VSPackage::Dispose(disposing);
}

/**
*** <summary>
***        Initializes the package.
*** </summary>
**/
void Microsoft::VisualStudio::VSIP::Samples::ToolWindowMCPP::ToolWindow::Initialize()
{
    Trace::WriteLine ("Entering Initialize() of: {0}", this->ToString());
    VSPackage::Initialize();

    // Get a reference to the MenuCommandService.
    OleMenuCommandService __gc* mcs = static_cast<OleMenuCommandService __gc*>(GetService(__typeof(IMenuCommandService)));
    if ( mcs )
    {
        // Add the callback for the menu.
        CommandID __gc* cmdID = new CommandID(GuidList::guidToolWindowCmdSet, PkgCmdIDList::CmdMyTool);
        MenuCommand __gc* command = new MenuCommand(
            new EventHandler(this, &Microsoft::VisualStudio::VSIP::Samples::ToolWindowMCPP::ToolWindow::ShowToolWindow),
            cmdID);
        command->set_Supported(true);
        command->set_Visible(true);
        command->set_Enabled(true);

        mcs->AddCommand( command );
    }
}

/**
***    <summary>
***        Helper method to create the ToolWindow user control and host it in the frame
***    </summary>
**/
void Microsoft::VisualStudio::VSIP::Samples::ToolWindowMCPP::ToolWindow::ShowToolWindow(System::Object *  sender, System::EventArgs *  e)
{
    // Check if the tool windows was created before.
    ToolWindowPane __gc* window = FindToolWindow(__typeof(MyToolWindow), 0, true);
    if ( window && window->Frame )
    {
        // Get a refernce to the previously created pane.
        windowFrame = static_cast<IVsWindowFrame __gc*>(window->Frame);
    }
    // Show the window.
    if ( windowFrame )
    {
        Microsoft::VisualStudio::NativeMethods::ThrowOnFailure( windowFrame->Show() );
    }
}