<%@ Import Namespace="System.IO" %>
<%@ Import Namespace="System.Data" %>

<html>

<script language="VB" runat="server">

    Sub Page_Load(ByVal Src As Object, ByVal E As EventArgs)
        If Not IsPostBack Then
            LoadData()
        End If
    End Sub

    Sub NewAuthorBtn_Click(ByVal Src As Object, ByVal E As EventArgs)
        If Not Page.IsValid Then
            AuthorMsg.Text = "Some required fields are missing"
        Else
            Dim fs As FileStream
            Dim reader As StreamReader
            Dim ds As DataSet
            Dim newAuthor As DataRow
            Dim writer As TextWriter
            Dim authorsFile As String

            ' open the file and read the current authors
            ds = New DataSet
     
            authorsFile = getAuthorsFile()

            fs = New FileStream(authorsFile, FileMode.Open, FileAccess.Read, FileShare.ReadWrite)
            reader = New StreamReader(fs)
            ds.ReadXml(reader)
            fs.Close()

            ' append a row
            Try
                newAuthor = ds.Tables(0).NewRow()
                newAuthor("au_id") = AuthorId.Text
                newAuthor("au_lname") = LastName.Text
                newAuthor("au_fname") = FirstName.Text
                newAuthor("phone") = Phone.Text
                newAuthor("address") = Address.Text
                newAuthor("city") = City.Text
                newAuthor("state") = State.Text
                newAuthor("zip") = PostalCode.Text
                newAuthor("contract") = Contract.Checked
                ds.Tables(0).Rows.Add(newAuthor)
            Catch Exc As Exception
                CacheMsg.Text = "Failed to create author with id = (" & AuthorId.Text & ")<br>" & "Author already exists."
                Return
            End Try

            ' rewrite the data file
            fs = New FileStream(authorsFile, FileMode.Create, FileAccess.ReadWrite, _
                FileShare.ReadWrite)
            writer = New StreamWriter(fs)
            writer = TextWriter.Synchronized(writer)
            ds.WriteXml(writer)
            writer.Close()

            Cache.Remove("MyData")
            LoadData()
        End If
    End Sub

    Sub RefreshBtn_Click(ByVal Src As Object, ByVal E As EventArgs)
        LoadData()
    End Sub

    Sub LoadData()
        Dim Source As DataView

        Source = Cache("MyData")
        If Source Is Nothing Then
            Dim ds As DataSet
            Dim fs As FileStream
            Dim reader As StreamReader
            Dim authorsFile As String

            ' read the data from the XML source
            ds = New DataSet()

            
            authorsFile = getAuthorsFile()

            fs = New FileStream(authorsFile, FileMode.Open, FileAccess.Read)
            reader = New StreamReader(fs)
            ds.ReadXml(reader)
            fs.Close()

            Source = New DataView(ds.Tables(0))

            ' cache it for future use
            Cache.Insert("MyData", Source, New CacheDependency(authorsFile))

            ' we created the data explicitly, so advertise that fact
            CacheMsg.Text = "Dataset created explicitly"
        Else
            CacheMsg.Text = "Dataset retrieved from cache"
        End If

        MyDataGrid.DataSource = Source
        MyDataGrid.DataBind()
    End Sub

    Function getAuthorsFile() As String
        ' check to see if the file exists in the temp dir first since the ASPNET
        ' process does not have permissions to write in the current directory
        
        Dim AuthorsFile As String = IO.Path.GetTempPath & "\authorsVB.xml"
        
        If Not File.Exists(AuthorsFile) Then
            File.Copy(Server.MapPath("authors.xml"), AuthorsFile)
        End If
        
        Return AuthorsFile
    End Function
      
  </script>

<body>
    <form id="Form1" runat="server">
        <h3>
            <font face="Verdana">File Dependencies</font></h3>
        <asp:DataGrid ID="MyDataGrid" runat="server" Width="900" BackColor="#ccccff" BorderColor="black"
            ShowFooter="false" CellPadding="3" CellSpacing="0" Font-Names="Verdana" Font-Size="8pt"
            HeaderStyle-BackColor="#aaaadd" />
        <hr>
        <h3>
            <font face="Verdana">Add New Author</font></h3>
        <asp:Label ID="AuthorMsg" Text="Fill in the required fields below to add a new author"
            ForeColor="red" Font-Names="Verdana" Font-Size="10" runat="server" />
        <p>
        </p>
        <table>
            <tr>
                <td>
                    Author Id:</td>
                <td>
                    <asp:TextBox ID="AuthorId" Text="111-11-1111" runat="server" /></td>
                <td>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator1" ControlToValidate="AuthorId"
                        Display="Static" ErrorMessage="*" runat="server" /></td>
            </tr>
            <tr>
                <td>
                    Last Name:</td>
                <td>
                    <asp:TextBox ID="LastName" Text="Doe" runat="server" /></td>
                <td>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator2" ControlToValidate="LastName"
                        Display="Static" ErrorMessage="*" runat="server" /></td>
            </tr>
            <tr>
                <td>
                    First Name:</td>
                <td>
                    <asp:TextBox ID="FirstName" Text="John" runat="server" /></td>
                <td>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator3" ControlToValidate="FirstName"
                        Display="Static" ErrorMessage="*" runat="server" /></td>
            </tr>
            <tr>
                <td>
                    Phone:</td>
                <td>
                    <asp:TextBox ID="Phone" Text="555 555-5050" runat="server" /></td>
                <td>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator4" ControlToValidate="Phone"
                        Display="Static" ErrorMessage="*" runat="server" /></td>
            </tr>
            <tr>
                <td>
                    Address:</td>
                <td>
                    <asp:TextBox ID="Address" Text="One Microsoft Way" runat="server" /></td>
                <td>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator5" ControlToValidate="Address"
                        ErrorMessage="*" Display="Static" runat="server" /></td>
            </tr>
            <tr>
                <td>
                    City:</td>
                <td>
                    <asp:TextBox ID="City" Text="Redmond" runat="server" /></td>
                <td>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator6" ControlToValidate="City"
                        ErrorMessage="*" Display="Static" runat="server" /></td>
            </tr>
            <tr>
                <td>
                    State:</td>
                <td>
                    <asp:TextBox ID="State" Text="WA" runat="server" /></td>
                <td>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator7" ControlToValidate="State"
                        ErrorMessage="*" Display="Static" runat="server" /></td>
            </tr>
            <tr>
                <td>
                    Postal Code:</td>
                <td>
                    <asp:TextBox ID="PostalCode" Text="98052" runat="server" /></td>
                <td>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator8" ControlToValidate="PostalCode"
                        ErrorMessage="*" Display="Static" runat="server" /></td>
            </tr>
            <tr>
                <td>
                    Contract:</td>
                <td>
                    <asp:CheckBox ID="Contract" Checked="true" runat="server" /></td>
                <td>
                </td>
            </tr>
        </table>
        <asp:Button ID="Button1" Text="Add New Author" OnClick="NewAuthorBtn_Click" runat="server" />
        <asp:Button ID="Button2" Text="Refresh List" OnClick="RefreshBtn_Click" runat="server" />
        <hr />
        <p>
            <i>
                <asp:Label ID="CacheMsg" runat="server" /></i></p>
    </form>
</body>
</html>

