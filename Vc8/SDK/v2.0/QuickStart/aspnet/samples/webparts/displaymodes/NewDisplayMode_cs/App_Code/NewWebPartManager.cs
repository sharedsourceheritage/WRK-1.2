//-----------------------------------------------------------------------
//  This file is part of the Microsoft .NET SDK Code Samples.
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
using System.Collections.Generic;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

/// <summary>
/// Summary description for NewWebPartManager
/// </summary>
namespace Microsoft.Sample.WebParts {
  public class NewWebPartManager : WebPartManager {
    public NewWebPartManager() {
    }
    public static readonly InlineEditDisplayMode InlineEdit = new InlineEditDisplayMode();
    protected override WebPartDisplayModeCollection CreateDisplayModes() {
      WebPartDisplayModeCollection displayModes = base.CreateDisplayModes();
      displayModes.Add(InlineEdit);
      return displayModes;
   }
  }
}
