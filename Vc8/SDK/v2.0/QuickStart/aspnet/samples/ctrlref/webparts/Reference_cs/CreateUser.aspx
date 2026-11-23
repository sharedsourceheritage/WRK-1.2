<%@ Page Language="C#" %>
<html>
<head id="Head1" runat="server">
    <title>WebPart Create User Page</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:CreateUserWizard ID="CreateUserWizard1" runat="server" ContinueDestinationPageUrl="Login.aspx">
                <WizardSteps>
                    <asp:CreateUserWizardStep ID="CreateUserWizardStep1" EnableViewState="False" runat="server">
                    </asp:CreateUserWizardStep>
                    <asp:WizardStep ID="SelectSample" runat="server" StepType="Complete" Title="Select Sample">
                        <table border="0">
                            <tr>
                                <td align="center" colspan="2">
                                    Complete</td>
                            </tr>
                            <tr>
                                <td>
                                    Your account has been successfully created.</td>
                            </tr>
                            <tr>
                                <td>
                                    Please click the sample that you want to visit
                                    <ul>
                                        <li><a href="WebPartZone_Simple.aspx">WebPartManager </a></li>
                                        <li><a href="ProxyWebPart_Content.aspx">ProxyWebpartmanager </a></li>
                                        <li><a href="WebPartZone_Simple.aspx">WebPartZone</a></li>
                                        <li><a href="CatalogZone_DeclarativeCatalogPart.aspx">CatalogZone </a></li>
                                        <li><a href="CatalogZone_DeclarativeCatalogPart.aspx">DeclarativeCatalogPart  </a></li>
                                        <li><a href="CatalogZone_PageCatalogPart.aspx">PageCatalogPart </a></li>
                                        <li><a href="CatalogZone_ImportCatalogPart.aspx">ImportCatalogPart   </a></li>
                                        <li><a href="EditorZone_AppearanceEditorPart.aspx">EditorZone </a></li>
                                        <li><a href="EditorZone_BehaviorEditorPart.aspx">BehaviorEditorPart  </a></li>
                                        <li><a href="EditorZone_LayoutEditorPart.aspx">LayoutEditorPart </a></li>
                                        <li><a href="EditorZone_PropertyGridEditorPart.aspx">PropertyGridEditorPart  </a></li>
                                        <li><a href="ConnectionZone.aspx">ConnectionZone </a></li>
                                    </ul>
                                </td>
                            </tr>
                        </table>
                    </asp:WizardStep>
                    <asp:CompleteWizardStep ID="CompleteWizardStep1" EnableViewState="False" runat="server">
                    </asp:CompleteWizardStep>
                </WizardSteps>
            </asp:CreateUserWizard>
        </div>
    </form>
</body>
</html>

