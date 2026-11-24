/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cs : Implementation of local object
//

using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

using Microsoft.VisualStudio.Shell.Interop;
using Microsoft.VisualStudio.Shell;

namespace Microsoft.VisualStudio.VSIP.Samples.ProvidesObjectPkg
{
    /////////////////////////////////////////////////////////////////////////////

    // This class implements ICodeNavigate - ICodeNavigate was chosen only for simplicity
    // and has nothing to do with the local object VS services.  It is simply an interface
    // the package and the class can use to demonstrate making a call.

    [Guid("3f12db34-7716-45e3-9987-31604118ea97")]
    public class ChildObject : ICodeNavigate
    {
        public ChildObject()
        {
            Trace.WriteLine(string.Format("Entering constructor for: {0}", this.ToString()));
        }

        public int DisplayDefaultEventHandler(string theString)
        {
            Trace.WriteLine(string.Format("In method DisplayDefaultEventHanlder of: {0}\r\nPassed: {1}", this.ToString(), theString));
            return NativeMethods.S_OK;
        }

    }
}