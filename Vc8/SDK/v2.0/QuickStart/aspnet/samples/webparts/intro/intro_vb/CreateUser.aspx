<%@ Page Language="VB" %>
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
                                        <li><a href="WebParts.aspx">Web Parts and Zones </a></li>
                                        <li><a href="WebPartCatalog.aspx">Web Part Catalogs </a></li>
                                        <li><a href="WebPartEditor.aspx">Web Part Editors </a></li>
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

