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
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.ServiceProcess;
using System.Timers;

namespace Microsoft.Samples
{
	public class SimpleService : System.ServiceProcess.ServiceBase
	{
        private System.Timers.Timer timer;
		/// <summary> 
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public SimpleService()
		{
			// This call is required by the Windows.Forms Component Designer.
			InitializeComponent();

			// TODO: Add any initialization after the InitComponent call
		}

		// The main entry point for the process
		static void Main()
		{
			System.ServiceProcess.ServiceBase[] ServicesToRun;
	
			// More than one user Service may run within the same process. To add
			// another service to this process, change the following line to
			// create a second service object. For example,
			//
			//   ServicesToRun = new System.ServiceProcess.ServiceBase[] {new Service1(), new MySecondUserService()};
			//
			ServicesToRun = new System.ServiceProcess.ServiceBase[] { new SimpleService() };

			System.ServiceProcess.ServiceBase.Run(ServicesToRun);
		}

		/// <summary> 
		/// Required method for Designer support - do not modify 
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
            this.timer = new System.Timers.Timer();
            ((System.ComponentModel.ISupportInitialize)(this.timer)).BeginInit();
            // 
            // timer
            // 
            this.timer.Enabled = true;
            timer.Interval = 1000;
            timer.Elapsed += new ElapsedEventHandler(OnTimer);
            CanPauseAndContinue = true;
            this.ServiceName = "Hello-World Service";
            ((System.ComponentModel.ISupportInitialize)(this.timer)).EndInit();

        }

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

        protected override void OnStart(string[] args)
        {
            EventLog.WriteEntry("Hello-World Service started");
            timer.Enabled = true;
        }

        protected override void OnStop()
        {
            EventLog.WriteEntry("Hello-World Service stopped");
            timer.Enabled = false;
        }

        protected override void OnPause()
        {
            EventLog.WriteEntry("Hello-World Service paused");
            timer.Enabled = false;
        }

        protected override void OnContinue()
        {
            EventLog.WriteEntry("Hello-World Service continued");
            timer.Enabled = true;
        }

        private void OnTimer(Object source, ElapsedEventArgs e)
        {
            EventLog.WriteEntry("Hello World!");
        }
	}
}
