/***************************************************************************
         Copyright (c) Microsoft CorporationAll rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind
    it is not recommended for use in a production environment.
***************************************************************************/

// Guids.cs
// MUST match guid.h (for the satellite DLL)
using System;

namespace Vsip.%ProjectClass%
{
    class GuidList
    {
        private GuidList(){}

        public static readonly Guid guid%ProjectClass%Pkg =        new Guid("{%PackageGuid%}");
        public static readonly Guid guid%ProjectClass%CmdSet =        new Guid("{%CmdSetGuid%}");
%ToolWindowItemStart%
        public static Guid guidToolWindowPersistance =            new Guid("{%ToolGuid%}");
%ToolWindowItemEnd%
%EditorStart%
        public static readonly Guid guidEditorFactory =         new Guid("{%FactoryGuid%}");
%EditorEnd%
    };
}