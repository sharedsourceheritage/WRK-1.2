<%@ Page Language="C#" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>DataList Bound to XML (Nested)</title>
  <link rel="stylesheet" href="style.css" />
</head>
<body>
  <form action="DataListXmlNested_cs.aspx" runat="server">

    <h1>Bookstore: Business</h1>

    <asp:XmlDataSource id="MySource" DataFile="~/App_Data/Bookstore.xml" 
      XPath="Bookstore/genre[@name='Business']/book" runat="server"/>

    <asp:DataList id="MyDataList" DataSourceId="MySource" runat="server">
      <ItemTemplate>

        <table>
          <tr>
            <td>
              <img alt="Cover Image" src='<%# "images/" + XPath("@ISBN") + ".gif" %>'>
            </td>
            <td>
              <h4><%# XPath("@Title") %></h4>
              <b>ISBN:</b> <%# XPath("@ISBN") %><br>
              <b>Price:</b> <%# XPath("@Price") %><br>
            </td>
          </tr>
        </table>

          <asp:DataList id="MyDataList" DataSource='<%# XPathSelect("chapter") %>' runat="server">
            <ItemTemplate>
              <br>
              <u>
                Chapter <%# XPath("@num") %>: 
                <%# XPath("@name") %>
              </u>
              <br>
              <%# XPath(".") %>
            </ItemTemplate>
          </asp:DataList>

      </ItemTemplate>
    </asp:DataList>

  </form>
</body>
</html>
