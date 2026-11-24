/***************************************************************************
         Copyright (c) Microsoft CorporationAll rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind
    it is not recommended for use in a production environment.
***************************************************************************/

// Guids.cs
// MUST match guid.h (for the satellite DLL)
using System;

namespace Microsoft.VisualStudio.VSIP.Samples.BasicEditor
{
    class GuidList
    {
        private GuidList(){}

        public static readonly Guid guidBasicEditorPkg =        new Guid("{a4635212-1cf4-4f5d-92ed-74dc17f6f5c8}");
        public static readonly Guid guidBasicEditorMenuGroup =  new Guid("{a1e87b40-293e-4489-b69b-e178fb48fdd4}");
        public static readonly Guid guidBasicEditorCmdSet =     new Guid("{7a77ea8e-ea5a-4491-8288-68dde056b2dd}");

        public static readonly Guid guidEditorFactory =         new Guid("{6bf7764f-d094-45a9-a5e7-86a00e504fa7}");
    };
}