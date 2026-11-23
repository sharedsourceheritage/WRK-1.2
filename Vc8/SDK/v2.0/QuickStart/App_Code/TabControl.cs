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
using System.Collections;
using System.Globalization;
using System.Web;
using System.Web.UI;


namespace Acme
{
    public class TabControlBuilder : ControlBuilder
    {
        public override Type GetChildControlType(String tagName, IDictionary attributes)
        {
            if (String.Compare(tagName, "Tab", true, CultureInfo.InvariantCulture) == 0)
            {
                return typeof(Acme.Tab);
            }
            return null;
        }
    }

    [
       ControlBuilderAttribute(typeof(TabControlBuilder))
    ]
    public class TabControl : Control
    {

        private ArrayList _tabs = new ArrayList();
        private bool _encode = false;

        protected override void AddParsedSubObject(Object obj)
        {
            if (obj is Tab)
            {
                _tabs.Add(obj);
            }
        }

        private String Encode(String text)
        {
            if (!_encode) return text;
            return Page.Server.HtmlEncode(text);
        }

        public bool HtmlEncode
        {
            get
            {
                return _encode;
            }
            set
            {
                _encode = value;
            }
        }

        private void RenderSupportScripts(HtmlTextWriter output)
        {
            int _numTabs = _tabs.Count;

            output.WriteLine("  <script language=\"JavaScript\">");
            output.WriteLine("    function doClick(index, numTabs, id) {");
            output.WriteLine("        document.all(\"tab\" + id, index).className = \"tab\";");
            output.WriteLine("        for (var i=1; i < numTabs; i++) {");
            output.WriteLine("            document.all(\"tab\" + id, (index + i) % numTabs).className = \"backtab\";");
            output.WriteLine("        }");
            output.WriteLine("        document.all(\"code\" + id, index).style.display = \"\";");
            output.WriteLine("        for (var j=1; j < numTabs; j++) {");
            output.WriteLine("          document.all(\"code\" + id, (index + j) % numTabs).style.display = \"none\";");
            output.WriteLine("        }");
            output.WriteLine("    }");
            output.WriteLine("  </script>\n");
            output.WriteLine("  <style>");
            output.WriteLine("    td.code {");
            output.WriteLine("      padding-left:10px;");
            output.WriteLine("      padding-right:10px;");
            output.WriteLine("      padding-top:0px;");
            output.WriteLine("      padding-bottom:0px;");
            output.WriteLine("      border-left: 1px solid #B1B1B1;");
            output.WriteLine("      border-bottom: 1px solid #DADADA;");
            output.WriteLine("      border-top: none;");
            output.WriteLine("      border-right: 1px solid #DADADA;");
//            output.WriteLine("      border-bottom: none;");
//            output.WriteLine("      border-top: none;");
//            output.WriteLine("      border-right: none;");
            output.WriteLine("    }");
            output.WriteLine("    td.tab {");
            output.WriteLine("      text-align:center;");
            output.WriteLine("      font: verdana;");
            output.WriteLine("      width:15%;");
            output.WriteLine("      border-top: 1px solid #B1B1B1;");
            output.WriteLine("      border-bottom: none;");
            output.WriteLine("      border-left: 1px solid #B1B1B1;");
            output.WriteLine("      border-left: 1px solid #B1B1B1;");
            output.WriteLine("      cursor: hand;");
            output.WriteLine("      background: #F0F0F0;");
            output.WriteLine("      padding: 3px;");
            output.WriteLine("    }");
            output.WriteLine("    td.backtab {");
            output.WriteLine("      text-align: center;");
            output.WriteLine("      font: verdana;");
            output.WriteLine("      width: 15%;");
            output.WriteLine("      border-top: 1px solid #B1B1B1;");
            output.WriteLine("      border-right: none;");
            output.WriteLine("      border-bottom: 1px solid #B1B1B1;");
            output.WriteLine("      border-left: 1px solid #B1B1B1;");
            output.WriteLine("      cursor: hand;");
            output.WriteLine("      background: #E3E3E3;");
            output.WriteLine("      padding: 3px;");
            output.WriteLine("    }");
            output.WriteLine("    td.space {");
            output.WriteLine("      width:" + (100 - _numTabs * 15).ToString() + "%;");
            output.WriteLine("      font: x-small verdana;");
            output.WriteLine("      padding: 0px 0px 0px 0px;");
            output.WriteLine("      border-top: none;");
            output.WriteLine("      border-right: none;");
            output.WriteLine("      border-bottom: 1px solid #B1B1B1;");
            output.WriteLine("      border-left: 1px solid #B1B1B1;");
            output.WriteLine("      background: white;");
            output.WriteLine("    }");
            output.WriteLine("  </style>");
        }

        protected override void Render(HtmlTextWriter output)
        {
            bool isUpLevel = (Page.Request.Browser.Browser == "IE");

            if (isUpLevel)
            {

                if (!Page.ClientScript.IsClientScriptBlockRegistered("Acme_TabControl"))
                {
                    Page.ClientScript.RegisterClientScriptBlock(this.GetType(), "Acme_TabControl", "");
                    RenderSupportScripts(output);
                }

                RenderUpLevel(output);
            }
            else
            {
                RenderDownLevel(output);
            }
        }

        private void RenderDownLevel(HtmlTextWriter output)
        {
            int _selectedindex = 0;
            int _numTabs = _tabs.Count;

            //Declare the string for the selected value and set the default.
            String value = "VB";
            //Get the cookie out of the Response (Set during the Header  change event.)
            HttpCookie codeCookie = Page.Response.Cookies["langpref"];
            if (codeCookie != null && codeCookie.Value != null &&codeCookie.Value.Length > 0)
            {
                //if the cookie exists, then use the value.
                value = codeCookie.Value;
            }
            else
            {
                //if the cookie does not exist, then the Session State needs to be checked.
                if (Page.Session["LangSel"] != null)
                {
                    //Set the selected value from the Session state.
                    value = (string)Page.Session["LangSel"];
                }
            }
            for (int i = 0; i < _numTabs; i++)
            {
                //Example of doing the comparison without declaring more memory.
                //if (((Tab)_tabs[i]).Name == value)
                //    _selectedindex = i;
                         
                Tab _tab = (Tab)_tabs[i]; 
                if (_tab.Name == value)
                    _selectedindex = i;
            }

            output.WriteLine("<div class=\"code\"><pre>");
            for (int i = 0; i < _numTabs; i++)
            {
                Tab _tab = (Tab)_tabs[i];

                if (_tab.HasControls() && i == _selectedindex)
                {
                    for (int x = 0; x < _tab.Controls.Count; x++)
                    {
                        if (_tab.Controls[x] is LiteralControl)
                            output.Write(Encode(((LiteralControl)_tab.Controls[x]).Text));
                    }
                    output.WriteLine("</pre></div>");
                    output.WriteLine("<div class=\"langtab\"><b>" + _tab.Name + "</b>");
                }
            }
            output.WriteLine("</div>");
        }

        private void RenderUpLevel(HtmlTextWriter output)
        {
            int _selectedindex = 0;
            int _numTabs = _tabs.Count;

            //Declare the string for the selected value and set the default.
            String value = "VB";
            //Get the cookie out of the Response (Set during the Header  change event.)
            HttpCookie codeCookie = Page.Response.Cookies["langpref"];
            if (codeCookie.Value != null && codeCookie.Value.Length > 0)
            {
                //if the cookie exists, then use the value.
                value = codeCookie.Value;
            }
            else
            {
                //if the cookie does not exist, then the Session State needs to be checked.
                if (Page.Session["LangSel"] != null)
                {
                    //Set the selected value from the Session state.
                    value = (string)Page.Session["LangSel"];
                }
            }
            for (int i = 0; i < _numTabs; i++)
            {
                //Example of doing the comparison without declaring more memory.
                //if (((Tab)_tabs[i]).Name == value)
                //    _selectedindex = i;
                         
                Tab _tab = (Tab)_tabs[i]; 
                if (_tab.Name == value)
                    _selectedindex = i;
            }


            output.WriteLine("    <table cellpadding=0 cellspacing=0 width=\"100%\">"); //  

            output.WriteLine("      <tr>");

            for (int i = 0; i < _numTabs; i++)
            {
                Tab _tab = (Tab)_tabs[i];
                String _className = "backtab";

                if (i == _selectedindex)
                    _className = "tab";

                output.WriteLine("        <td class=\"" + _className + "\" id=\"tab" + this.UniqueID + "\" onclick=\"doClick(" + i.ToString() + ", " + _numTabs.ToString() + ", '" + this.UniqueID + "')\">");
                output.WriteLine("          " + _tab.Name );
                output.WriteLine("        </td>");
            }
            output.WriteLine("        <td class=\"space\">&nbsp;</td>");
            output.WriteLine("      </tr>");



            output.WriteLine("      <tr>");
            output.WriteLine("        <td class=\"code\" colspan=\"" + (_numTabs + 1).ToString() + "\">");

            for (int i = 0; i < _numTabs; i++)
            {
                Tab _tab = (Tab)_tabs[i];
                String _display = "none";

                if (i == _selectedindex)
                    _display = "";

                output.WriteLine("<pre id=\"code" + this.UniqueID + "\" style=\"display:" + _display + "\">");

                if (_tab.HasControls())
                {
                    for (int x = 0; x < _tab.Controls.Count; x++)
                    {
                        if (_tab.Controls[x] is LiteralControl)
                            output.Write(Encode(((LiteralControl)_tab.Controls[x]).Text));
                    }
                }

                output.WriteLine("</pre>");
            }
            output.WriteLine("        </td>");
            output.WriteLine("      </tr>");
            output.WriteLine("    </table>");


        }
    }
}