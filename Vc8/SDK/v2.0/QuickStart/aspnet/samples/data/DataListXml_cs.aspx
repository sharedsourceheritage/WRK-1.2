<%@ Page Language="C#" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>DataList Bound to XML</title>
  <link rel="stylesheet" href="style.css" />
</head>
<body>
  <form action="DataListXml_cs.aspx" runat="server">

    <h1>Bookstore: Business</h1>

    <asp:XmlDataSource id="MySource" DataFile="~/App_Data/Bookstore.xml" 
       XPath="Bookstore/genre[@name='Business']/book" runat="server"/>

    <asp:DataList id="MyDataList" DataSourceId="MySource" runat="server">
      <ItemTemplate>
        <table>
          <tr>
            <td>
              <img alt="Cover Image" src='<%#"images/" + Eval("ISBN") + ".gif"%>'>
            </td>
            <td>
              <h4><%# Eval("Title") %></h4>
              <b>ISBN:</b> <%# Eval("ISBN") %><br>
              <b>Price:</b> <%# Eval("Price") %><br>
            </td>
          </tr>
        </table>
      </ItemTemplate>
    </asp:DataList>


  </form>
</body>
</html>
