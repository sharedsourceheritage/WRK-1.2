/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cs : Implementation of DynamicMenu
//

using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using Microsoft.Win32;
using Microsoft.VisualStudio.Shell.Interop;
using Microsoft.VisualStudio.OLE.Interop;

using System.ComponentModel.Design;
using MSVSIP = Microsoft.VisualStudio.Shell;

namespace Vsip.DynamicMenu
{
    public class MyMenu : MSVSIP.OleMenuCommand
    {
        private int clickCount;
        public MyMenu(CommandID id, string Text) :
            base(null, id, Text)
        {
            clickCount = 0;
        }

        public override string Text
        {
            get
            {
                return string.Format("{0} (clicked {1} times)", base.Text, clickCount);
            }
            set { base.Text = value; }
        }

        public override void Invoke()
        {
            clickCount++;
        }

        public override void Invoke(object args)
        {
            Invoke();
        }

        public override void Invoke(object inArg, IntPtr outArg)
        {
            Invoke();
        }
    }

    /////////////////////////////////////////////////////////////////////////////
    // DynamicMenu
    [MSVSIP.DefaultRegistryRoot("Software\\Microsoft\\VisualStudio\\8.0Exp")]
    [MSVSIP.RegisterLoadKey("Standard", "1.0", "Dynamic Menu Test", "Company", 1)]
    [MSVSIP.ProvideMenuResource(1000, 1)]
    [Guid("ce9cc1aa-4eb1-4068-b584-ffa55d7b10a9")]
    public class DynamicMenu : MSVSIP.Package
    {

        private int menuCounter;
        private const int MaxMenuCount = 10;

        private MSVSIP.OleMenuCommand addCommand;
        private MSVSIP.OleMenuCommand removeCommand;

        public DynamicMenu()
        {
            Trace.WriteLine(string.Format("Entering constructor for: {0}", this.ToString()));

            // Set to 0 the number of the dynamically created menus
            menuCounter = 0;

            // Get the command service
            IMenuCommandService commandService = (IMenuCommandService)GetService(typeof(IMenuCommandService));
            if (null == commandService)
            {
                // The IMenuCommandService is not implemented, so we can not add any command and
                // we can exit now.
                Trace.WriteLine("The base package doesn't implements IMenuCommandService");
                return;
            }

            // Create the menu for the add command
            EventHandler addCallback = new EventHandler( AddMenuCallback );
            CommandID addID = new CommandID(GuidList.guidDynamicMenuCmdSet, PkgCmdIDList.cmdidAddMenu);
            addCommand = new MSVSIP.OleMenuCommand(addCallback, addID, "Add Menu");
            commandService.AddCommand( addCommand );

            // Do the same for the remove command
            EventHandler removeCallback = new EventHandler( RemoveMenuCallback );
            CommandID removeID = new CommandID(GuidList.guidDynamicMenuCmdSet, PkgCmdIDList.cmdidRemoveMenu);
            removeCommand = new MSVSIP.OleMenuCommand(removeCallback, removeID, "No menu to remove");
            commandService.AddCommand( removeCommand );
        }

        private void AddMenuCallback(object source, EventArgs args)
        {
            // The source of the event must be the "Add menu" button.
            MSVSIP.OleMenuCommand sourceMenu = source as MSVSIP.OleMenuCommand;
            if ( (sourceMenu == null) || (sourceMenu.CommandID != addCommand.CommandID) )
                return;
            
            // Get the command service
            IMenuCommandService commandService = (IMenuCommandService)GetService(typeof(IMenuCommandService));
            // Create the ID of the new command
            CommandID newID = new CommandID(GuidList.guidDynamicMenuCmdSet, PkgCmdIDList.cmdidDynamicFirst+menuCounter);
            MyMenu newCommand = new MyMenu(newID, string.Format("Command #{0}", menuCounter+1));
            commandService.AddCommand(newCommand);

            // After adding the new menu, we can increase the counter of the commands and
            // enable the remove command.
            menuCounter++;
            removeCommand.Enabled = true;
            removeCommand.Text = "Remove Menu";

            if (menuCounter >= MaxMenuCount)
            {
                addCommand.Enabled = false;
                addCommand.Text = "Can't add other menus";
            }
        }

        private void RemoveMenuCallback(object source, EventArgs args)
        {
            // The source of the event must be the "Remove menu" button.
            MenuCommand sourceMenu = source as MenuCommand;
            if ( (sourceMenu == null) || (sourceMenu.CommandID != removeCommand.CommandID) )
                return;

            if (menuCounter == 0)
            {
                removeCommand.Enabled = false;
                removeCommand.Text = "No menu to remove";
                addCommand.Enabled = true;
                addCommand.Text = "Add Menu";
                return;
            }
            
            // Get the command service
            IMenuCommandService commandService = (IMenuCommandService)GetService(typeof(IMenuCommandService));
            // Create the ID of the element to delete and serch for it in the command service
            CommandID deleteID = new CommandID(GuidList.guidDynamicMenuCmdSet, PkgCmdIDList.cmdidDynamicFirst+menuCounter-1);
            MenuCommand delendum = commandService.FindCommand( deleteID );
            // if the command is not found exit
            if ( delendum == null )
                return;
            // delete the command
            commandService.RemoveCommand( delendum );

            // Decrease the menu counter and enable the add command
            menuCounter--;
            addCommand.Enabled = true;
            addCommand.Text = "Add Menu";

            if (menuCounter == 0)
            {
                removeCommand.Enabled = false;
                removeCommand.Text = "No menu to remove";
            }
        }

        /////////////////////////////////////////////////////////////////////////////
        // CBscPkgPackage Package Implementation
        #region Package Members

        protected override void Initialize()
        {
            Trace.WriteLine (string.Format("Entering Initialize() of: {0}", this.ToString()));
            base.Initialize();

        }

        protected override void Dispose(bool disposing)
        {
            Trace.WriteLine (string.Format("Entering Dispose() of: {0}", this.ToString()));

            base.Dispose(disposing);
        }

        protected override object GetAutomationObject(
            /*[in] */ string propName)
        {
            Trace.WriteLine (string.Format("Entering GetAutomationObject() of: {0}", this.ToString()));

            throw new NotImplementedException();
        }

        #endregion
    }
}