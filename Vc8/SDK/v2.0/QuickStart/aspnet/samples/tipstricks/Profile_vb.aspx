<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs)

    Age.Text = Profile.Age
    ZipCode.Text = Profile.ZipCode
    Gender.Text = Profile.Gender
    Phone.Text = Profile.PhoneNumber

  End Sub
  
</script>
<html>
<head id="Head1" runat="server">
  <title>Untitled Page</title>
</head>
<body>
  <form id="Form1" runat="server">
    <h1>
      Profile Page</h1>
    <p>
      <font size="4">UserName:</font>
      <asp:LoginName ID="LoginName1" runat="server" />
      <font size="4">
        <br />
        Age: </font>
      <asp:Label ID="Age" runat="server">Label</asp:Label><font size="4">
        <br />
        ZipCode: </font>
      <asp:Label ID="ZipCode" runat="server">Label</asp:Label><font size="4">
        <br />
        Gender: </font>
      <asp:Label ID="Gender" runat="server">Label</asp:Label><font size="4">
        <br />
        Phone: </font>
      <asp:Label ID="Phone" runat="server">Label</asp:Label>
    </p>
  </form>
</body>
</html>
