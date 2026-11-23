 <%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>
    
    <h2>ADO.NET: Handle Errors</h2>
    
    <br /><br />In addition to Try/Catch and exceptions, the new ADO.NET data architecture allows you to add error messages to each row of Data in a DataSet. <b>SqlDataAdapters</b> attach error messages to Rows if updates or other actions fail. Furthermore, you can filter for rows in error to present them to the user, or pass them to error handling functions.
    <br /><br />
    Errors persist with the DataSet even when being transferred using XML or XML Web services. You can use the <b>RowError</b> property to set the Error message of a DataRow in a DataSet.
    <br /><br />
    
    <Acme:TabControl runat="server">
    <Tab Name="C#">
    myDataSet.Tables["Customers"].Rows[0].RowError = "An error was added";
    myDataSet.Tables["Customers"].Rows[1].RowError = "This is another error message";
    </Tab>
    <Tab Name="VB">
    myDataSet.Tables("Customers").Rows(0).RowError = "An error was added"
    myDataSet.Tables("Customers").Rows(1).RowError = "This is another error message"
    </Tab>
    <Tab Name="C++">
    myDataSet->Tables->Item["Customers"]->Rows->Item[0]->RowError = "An Error was added";
    myDataSet->Tables->Item["Customers"]->Rows->Item[1]->RowError = "This is another error message";
    </Tab>
    </Acme:TabControl>
    
    <br /><br />
    Now you can walk the error in a DataTable with the <b>GetErrors()</b> method. You can also test for errors using <b>HasErrors</b>.
    
    <Acme:TabControl runat="server">
    <Tab Name="C#">
    if ( myDataSet.Tables["Customers"].HasErrors )
    {
      DataRow[] ErrDataRows = myDataSet.Tables["Customers"].GetErrors();
      Console.WriteLine("DataTable " + myDataSet.Tables["Customers"].TableName + " has " + ErrDataRows.Length.ToString() + " Error(s)!");
    
      for (int i = 0; i <= ErrDataRows.Length -1; i++)
      {
        Console.WriteLine("Row Error for row " + ErrDataRows[i]["CustomerID"].ToString() + " --  Error Msg="  + ErrDataRows[i].RowError);
      }
    }
    else
    {
      Console.WriteLine("=================");
      Console.WriteLine("DataTable " + myDataSet.Tables["Customers"].TableName + " Has no errors");
    }
    </Tab>
    <Tab Name="VB">
    if myDataSet.Tables("Customers").HasErrors then
      Dim ErrDataRows as DataRow()
      ErrDataRows = myDataSet.Tables("Customers").GetErrors()
      Console.WriteLine("DataTable " + myDataSet.Tables("Customers").TableName + " has " + ErrDataRows.Length.ToString() + " Error(s)!")
    
      Dim i as integer
      for i = 0 to ErrDataRows.Length -1
        Console.WriteLine("Row Error for row " + ErrDataRows(i)("CustomerID").ToString() + " --  Error Msg="  + ErrDataRows(i).RowError)
      next
    else
      Console.WriteLine("=================")
      Console.WriteLine("DataTable " + myDataSet.Tables("Customers").TableName + " Has no errors")
    end if
    </Tab>
    <Tab Name="C++">
    if ( myDataSet->Tables->Item["Customers"]->HasErrors )
    {
      DataRow * ErrDataRows[] = myDataSet->Tables->Item["Customers"]->GetErrors();
      Console::Write("DataTable ");
	  Console::Write(myDataSet->Tables->Item["Customers"]->TableName); 
	  Console::Write(" has ");
	  Console::Write(ErrDataRows->Count.ToString());
	  Console::WriteLine(" Error(s)!");

      for (int i = 0; i <= ErrDataRows->Length -1; i++)
      {
        Console::Write("Row Error for row ");
		Console::Write(ErrDataRows[i]->Item["CustomerID"]->ToString());
		Console::Write(" --  Error Msg=");
		Console::WriteLine(ErrDataRows[i]->RowError);
      }
    }
    else
    {
      Console::WriteLine("=================");
      Console::Write("DataTable ");
	  Console::Write(myDataSet->Tables->Item["Customers"]->TableName);
	  Console::Write(" Has no errors");
    }
    </Tab>
    </Acme:TabControl>
    
    <br /><br />
    The following example loads a DataSet, sets some errors, and then shows the Errors in the Rows.
    <br /><br />
    
    
    <Acme:LangSwitch runat="server">
      <CsTemplate>
    <Acme:SourceRef
      RunSample="../../samples/adoplus/HandleErrors/cs/HandleErrors/HandleErrors.aspx"
      ViewSource="~/howto/samples/adoplus/HandleErrors/HandleErrors.src"
      Icon="../../../images/genicon.gif"
      Caption="C# HandleErrors.aspx"
      SamplePath="howto\samples\adoplus\HandleErrors\"
      CanBeHosted="false"
      runat="server" />
      </CsTemplate>
      <VbTemplate>
    <Acme:SourceRef
      RunSample="../../samples/adoplus/HandleErrors/vb/HandleErrors/HandleErrors.aspx"
      ViewSource="~/howto/samples/adoplus/HandleErrors/HandleErrors.src"
      Icon="../../../images/genicon.gif"
      SamplePath="howto\samples\adoplus\HandleErrors\"
      Caption="VB HandleErrors.aspx"
      CanBeHosted="false"
      runat="server" />
      </VbTemplate>
      <CpTemplate>
    <Acme:SourceRef
      RunSample=""
      ViewSource="~/howto/samples/adoplus/HandleErrors/HandleErrors.src"
      Icon="../../../images/genicon.gif"
      Caption="C++ HandleErrors.exe"
      SamplePath="howto\samples\adoplus\HandleErrors\"
      CanBeHosted="false"
      runat="server" />
      </CpTemplate>
 <VjsTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />
  </VjsTemplate>
    </Acme:LangSwitch>
    
    <br /><br />

</asp:Content>

