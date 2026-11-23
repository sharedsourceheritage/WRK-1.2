<%@ Page Language="VB" %>

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
  <title>Sign In Form Validation Sample</title>
</head>
<body>
  <div>
    <h3>
      <font face="Verdana">Sign In Form Validation Sample</font></h3>
    <form action="validationform_vb.aspx" method="post" runat="server">
      <hr width="600" size="1" noshade="noshade" />
      <center>
        <asp:ValidationSummary ID="valSum" runat="server" HeaderText="You must enter a valid value in the following fields:"
          DisplayMode="SingleParagraph" Font-Names="verdana" Font-Size="12" />
        <br />
        <br />
        <!-- sign-in -->
        <table border="0" width="600">
          <tr>
            <td colspan="3">
              <table border="0" cellpadding="0" cellspacing="0" width="100%">
                <tr>
                  <td>
                    <font face="geneva,arial" size="-1"><b>Sign-In Information</b></font>
                  </td>
                </tr>
              </table>
            </td>
          </tr>
          <tr>
            <td align="right">
              <font face="Arial" size="2">Email Address:</font>
            </td>
            <td>
              <asp:TextBox ID="email" Width="200px" MaxLength="60" runat="server" />
            </td>
            <td>
              <asp:RequiredFieldValidator ID="emailReqVal" ControlToValidate="email" ErrorMessage="Email. "
                Display="Dynamic" Font-Names="Verdana" Font-Size="12" runat="server">
            *
              </asp:RequiredFieldValidator>
              <asp:RegularExpressionValidator ID="emailRegexVal" ControlToValidate="email" ErrorMessage="Email. "
                Display="Static" ValidationExpression="^[\w-]+@[\w-]+\.(com|net|org|edu|mil)$"
                Font-Names="Arial" Font-Size="11" runat="server">
            Not a valid e-mail address.  Must follow email@host.domain.
              </asp:RegularExpressionValidator>
            </td>
          </tr>
          <tr>
            <td align="right">
              <font face="Arial" size="2">Password:</font>
            </td>
            <td>
              <asp:TextBox ID="passwd" TextMode="Password" MaxLength="20" runat="server" />
            </td>
            <td>
              <asp:RequiredFieldValidator ID="passwdReqVal" ControlToValidate="passwd" ErrorMessage="Password. "
                Display="Dynamic" Font-Names="Verdana" Font-Size="12" runat="server">
              *
              </asp:RequiredFieldValidator>
              <asp:RegularExpressionValidator ID="passwdRegexBal" ControlToValidate="passwd" ErrorMessage="Password. "
                ValidationExpression=".*[!@#$%^&*+;:].*" Display="Static" Font-Names="Arial" Font-Size="11"
                Width="100%" runat="server">
              Password must include one of these (!@#$%^&amp;*+;:)
              </asp:RegularExpressionValidator>
            </td>
          </tr>
          <tr>
            <td align="right">
              <font face="Arial" size="2">Re-enter Password:</font>
            </td>
            <td>
              <asp:TextBox ID="passwd2" TextMode="Password" MaxLength="20" runat="server" />
            </td>
            <td>
              <asp:RequiredFieldValidator ID="passwd2ReqVal" ControlToValidate="passwd2" ErrorMessage="Re-enter Password. "
                Display="Dynamic" Font-Names="Verdana" Font-Size="12" runat="server">
            *
              </asp:RequiredFieldValidator>
              <asp:CompareValidator ID="CompareValidator1" ControlToValidate="passwd2" ControlToCompare="passwd"
                ErrorMessage="Re-enter Password. " Display="Static" Font-Names="Arial" Font-Size="11"
                runat="server">
            Password fields don't match
              </asp:CompareValidator>
            </td>
          </tr>
          <tr>
            <td colspan="3">
              &nbsp;</td>
          </tr>
          <!-- personalization information -->
          <tr>
            <td colspan="3">
              <table border="0" cellpadding="0" cellspacing="0" width="100%">
                <tr>
                  <td>
                    <font face="geneva,arial" size="-1"><b>Personal Information</b></font>
                  </td>
                </tr>
              </table>
            </td>
          </tr>
          <tr>
            <td align="right">
              <font face="Arial" size="2">First Name:</font>
            </td>
            <td>
              <asp:TextBox ID="fn" MaxLength="20" Width="200px" runat="server" />
            </td>
            <td>
            </td>
          </tr>
          <tr>
            <td align="right">
              <font face="Arial" size="2">Last Name:</font>
            </td>
            <td>
              <asp:TextBox ID="ln" MaxLength="40" Width="200px" runat="server" />
            </td>
            <td>
            </td>
          </tr>
          <tr>
            <td align="right">
              <font face="Arial" size="2">Address:</font>
            </td>
            <td>
              <asp:TextBox ID="address" Width="200px" runat="server" />
            </td>
            <td>
            </td>
          </tr>
          <tr>
            <td align="right">
              <font face="Arial" size="2">State:</font>
            </td>
            <td>
              <asp:TextBox ID="state" Width="30px" MaxLength="2" runat="server" />&nbsp; <font
                face="Arial" size="2">Zip Code:</font>&nbsp;
              <asp:TextBox ID="zip" Width="60px" MaxLength="5" runat="server" />
            </td>
            <td>
              <asp:RegularExpressionValidator ID="RegularExpressionValidator1" ControlToValidate="zip"
                ErrorMessage="Zip Code. " ValidationExpression="^\d{5}$" Display="Static" Font-Names="Arial"
                Font-Size="11" runat="server">
            Zip code must be 5 numeric digits
              </asp:RegularExpressionValidator>
            </td>
          </tr>
          <tr>
            <td align="right">
              <font face="Arial" size="2">Phone:</font>
            </td>
            <td>
              <asp:TextBox ID="phone" MaxLength="20" runat="server" />
            </td>
            <td>
              <asp:RequiredFieldValidator ID="phoneReqVal" ControlToValidate="phone" ErrorMessage="Phone. "
                Display="Dynamic" Font-Names="Verdana" Font-Size="12" runat="server">
            *
              </asp:RequiredFieldValidator>
              <asp:RegularExpressionValidator ID="phoneRegexVal" ControlToValidate="phone" ErrorMessage="Phone. "
                ValidationExpression="(^x\s*[0-9]{5}$)|(^(\([1-9][0-9]{2}\)\s)?[1-9][0-9]{2}-[0-9]{4}(\sx\s*[0-9]{5})?$)"
                Display="Static" Font-Names="Arial" Font-Size="11" runat="server">
            Must be in form: (XXX) XXX-XXXX
              </asp:RegularExpressionValidator>
            </td>
          </tr>
          <tr>
            <td colspan="3">
              &nbsp;</td>
          </tr>
          <!-- Credit Card Info -->
          <tr>
            <td colspan="3">
              <font face="Arial" size="2"><b>Credit Card Information</b></font>
            </td>
          </tr>
          <tr>
            <td align="right">
              <font face="Arial" size="2">Card Type:</font>
            </td>
            <td>
              <asp:RadioButtonList ID="ccType" Font-Names="Arial" RepeatLayout="Flow" runat="server">
                <asp:ListItem>MasterCard</asp:ListItem>
                <asp:ListItem>Visa</asp:ListItem>
              </asp:RadioButtonList>
            </td>
            <td>
              <asp:RequiredFieldValidator ID="ccTypeReqVal" ControlToValidate="ccType" ErrorMessage="Card Type. "
                Display="Static" InitialValue="" Font-Names="Verdana" Font-Size="12" runat="server">
            *
              </asp:RequiredFieldValidator>
            </td>
          </tr>
          <tr>
            <td align="right">
              <font face="Arial" size="2">Card Number:</font>
            </td>
            <td>
              <asp:TextBox ID="ccNum" runat="server" />
            </td>
            <td>
              <asp:RequiredFieldValidator ID="ccNumReqVal" ControlToValidate="ccNum" ErrorMessage="Card Number. "
                Display="Dynamic" Font-Names="Verdana" Font-Size="12" runat="server">
            *
              </asp:RequiredFieldValidator>
              <asp:CustomValidator ID="ccNumCustVal" ControlToValidate="ccNum" ErrorMessage="Card Number. "
                ClientValidationFunction="ccClientValidate" Display="Static" Font-Names="Arial"
                Font-Size="11" runat="server">
            Not a valid credit card number.  Must contain 16 digits.
              </asp:CustomValidator>
            </td>
          </tr>
          <tr>
            <td align="right">
              <font face="Arial" size="2">Expiration Date:</font>
            </td>
            <td>
              <asp:DropDownList ID="expDate" runat="server">
                <asp:ListItem></asp:ListItem>
                <asp:ListItem>06/00</asp:ListItem>
                <asp:ListItem>07/00</asp:ListItem>
                <asp:ListItem>08/00</asp:ListItem>
                <asp:ListItem>09/00</asp:ListItem>
                <asp:ListItem>10/00</asp:ListItem>
                <asp:ListItem>11/00</asp:ListItem>
                <asp:ListItem>01/01</asp:ListItem>
                <asp:ListItem>02/01</asp:ListItem>
                <asp:ListItem>03/01</asp:ListItem>
                <asp:ListItem>04/01</asp:ListItem>
                <asp:ListItem>05/01</asp:ListItem>
                <asp:ListItem>06/01</asp:ListItem>
                <asp:ListItem>07/01</asp:ListItem>
                <asp:ListItem>08/01</asp:ListItem>
                <asp:ListItem>09/01</asp:ListItem>
                <asp:ListItem>10/01</asp:ListItem>
                <asp:ListItem>11/01</asp:ListItem>
                <asp:ListItem>12/01</asp:ListItem>
              </asp:DropDownList>
            </td>
            <td>
              <asp:RequiredFieldValidator ID="expDateReqVal" ControlToValidate="expDate" ErrorMessage="Expiration Date. "
                Display="Static" InitialValue="" Font-Names="Verdana" Font-Size="12" runat="server">
          *
              </asp:RequiredFieldValidator>
            </td>
          </tr>
        </table>
        <br /><br />
          <input runat="server" type="submit" value="Sign In"/>
          <br /><br />
            <hr width="600" size="1" noshade="noshade">

            <script type="text/javascript">

        function ccClientValidate(source, arguments)
        {
            var cc = arguments.Value;
            var ccSansSpace;
            var i, digits, total;

            // SAMPLE ONLY.  Not a real world actual credit card algo.
            // Based on ANSI X4.13, the LUHN formula (also known as the modulus 10 -- or mod 10 -- algorithm )
            // is used to generate and/or validate and verify the accuracy of some credit-card numbers.

            // Get the number, parse out any non digits, should have 16 left
            ccSansSpace = cc.replace(/\D/g, "");
            if(ccSansSpace.length != 16) {
                arguments.IsValid = false;
                return;   // invalid ccn
            }

            // Convert to array of digits
            digits = new Array(16);
            for(i=0; i<16; i++)
                digits[i] = Number(ccSansSpace.charAt(i));

            // Double & sum digits of every other number
            for(i=0; i<16; i+=2) {
                digits[i] *= 2;
                if(digits[i] > 9)   digits[i] -= 9;
            }

            // Sum the numbers
            total = 0;
            for(i=0; i<16; i++)     total += digits[i];

            // Results
            if( total % 10 == 0 )   {
                arguments.IsValid = true;
                return;    // valid ccn
            }
            else  {
                arguments.IsValid = false;
                return;   // invalid ccn
            }
        }

            </script>
      </center>
    </form>
  </div>
</body>
</html>
