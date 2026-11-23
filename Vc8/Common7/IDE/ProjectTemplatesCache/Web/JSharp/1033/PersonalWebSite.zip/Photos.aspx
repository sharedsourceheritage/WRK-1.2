<%@ Page Language="VJ#" MasterPageFile="~/Default.master" Title="Your Name Here | Admin" %>
<%@ Import Namespace="System.IO" %>

<script runat="server">

	protected void FormView1_ItemInserting(Object sender, FormViewInsertEventArgs e) {
		FileUpload f = (FileUpload)FormView1.FindControl("PhotoFile");
		if (f.get_HasFile()) {
			e.get_Values().set_Item("BytesOriginal", f.get_FileBytes());
		} else {
			e.set_Cancel(true);
		}
	}

	protected void Button1_Click(Object sender, ImageClickEventArgs e) {
		DirectoryInfo d = new DirectoryInfo(get_Server().MapPath("~/Upload"));
		FileInfo[] filelist = d.GetFiles("*.jpg");
		for (int i = 0; i < filelist.length; i++) {
			FileInfo f = filelist[i];
			ubyte[] buffer = new ubyte[(int)f.OpenRead().get_Length()];
			f.OpenRead().Read(buffer, 0, (int)f.OpenRead().get_Length());
			PhotoManager.AddPhoto(Convert.ToInt32(get_Request().get_QueryString().get_Item("AlbumID")), f.get_Name(), buffer);
		}
		GridView1.DataBind();
	}

</script>

<asp:content id="Content1" contentplaceholderid="Main" runat="server">

	<div class="shim column"></div>
	
	<div class="page" id="admin-photos">
		<div id="sidebar">
			<h4>Bulk Upload Photos</h4>
			<p>The following files were found in your <b>Upload</b>	folder. Click on <b>Import</b>	to import these	pictures to your photo album. This operation may take a	few moments.</p>
			<br />
			<br />
			<asp:ImageButton ID="ImageButton1" Runat="server" onclick="Button1_Click" SkinID="import" />
			<asp:datalist runat="server" id="UploadList" repeatcolumns="1" repeatlayout="table" repeatdirection="horizontal" DataSourceID="ObjectDataSource2">
				<itemtemplate>
					<%# Container.get_DataItem() %>
				</itemtemplate>
			</asp:datalist>
		</div>

		<div id="content">
			<h4>Add	Photos</h4>
			<p>To add single photos over HTTP, select a file and caption, then click <b>Add</b>.</p>
			<asp:FormView ID="FormView1" Runat="server" 
				DataSourceID="ObjectDataSource1" DefaultMode="insert"
				BorderWidth="0px" CellPadding="0" OnItemInserting="FormView1_ItemInserting">
				<InsertItemTemplate>
					<asp:RequiredFieldValidator	ID="RequiredFieldValidator1" Runat="server" ErrorMessage="You must choose a caption." ControlToValidate="PhotoFile" Display="Dynamic" Enabled="false" />
					<p>
						Photo<br />
						<asp:FileUpload ID="PhotoFile" Runat="server" Width="416" CssClass="textfield" /><br />
						Caption<br />
						<asp:TextBox ID="PhotoCaption" Runat="server" Width="326" Text='<%# Bind("Caption") %>' CssClass="textfield" />
					</p>
					<p style="text-align:right;">
						<asp:ImageButton ID="AddNewPhotoButton" Runat="server" CommandName="Insert" skinid="add"/>
					</p>
				</InsertItemTemplate>
			</asp:FormView>
			<hr />
			<h4>Photos in This Album</h4>
			<p>The following are the photos	currently in this album.</p>
			<asp:gridview id="GridView1" runat="server" datasourceid="ObjectDataSource1" 
				datakeynames="PhotoID" cellpadding="6" EnableViewState="false"
				autogeneratecolumns="False" BorderStyle="None" BorderWidth="0px" width="420px" showheader="false" >
				<EmptyDataRowStyle CssClass="emptydata"></EmptyDataRowStyle>
				<EmptyDataTemplate>
					You currently have no photos.
				</EmptyDataTemplate>
				<columns>
					<asp:TemplateField>
						<ItemStyle Width="50" />
						<ItemTemplate>
							<table border="0" cellpadding="0" cellspacing="0" class="photo-frame">
								<tr>
									<td class="topx--"></td>
									<td class="top-x-"></td>
									<td class="top--x"></td>
								</tr>
								<tr>
									<td class="midx--"></td>
									<td><a href='Details.aspx?AlbumID=<%# Eval("AlbumID") %>&Page=<%# ((GridViewRow)Container).get_RowIndex() %>'>
										<img src='../Handler.ashx?Size=S&PhotoID=<%# Eval("PhotoID") %>' class="photo_198" style="border:2px solid white;width:50px;" alt='Thumbnail of Photo Number <%# Eval("PhotoID") %>' /></a></td>
									<td class="mid--x"></td>
								</tr>
								<tr>
									<td class="botx--"></td>
									<td class="bot-x-"></td>
									<td class="bot--x"></td>
								</tr>
							</table>
						</ItemTemplate>
					</asp:TemplateField>
					<asp:boundfield headertext="Caption" datafield="Caption" />
					<asp:TemplateField>
						<ItemStyle Width="150" />
						<ItemTemplate>
							<div style="width:100%;text-align:right;">
								<asp:ImageButton ID="ImageButton2" Runat="server" CommandName="Edit" SkinID="rename" />
								<asp:ImageButton ID="ImageButton3" Runat="server" CommandName="Delete"  SkinID="delete" />
							</div>
						</ItemTemplate>
						<EditItemTemplate>
							<div style="width:100%;text-align:right;">
								<asp:ImageButton ID="ImageButton4" Runat="server" CommandName="Update" SkinID="save" />
								<asp:ImageButton ID="ImageButton5" Runat="server" CommandName="Cancel"  SkinID="cancel" />
							</div>
						</EditItemTemplate>
					</asp:TemplateField>
				</columns>
			</asp:gridview>
		</div>

	 </div>
	
	<asp:ObjectDataSource ID="ObjectDataSource1" Runat="server" TypeName="PhotoManager" 
		SelectMethod="GetPhotos"
		InsertMethod="AddPhoto" 
		DeleteMethod="RemovePhoto" 
		UpdateMethod="EditPhoto" >
		<SelectParameters>
			<asp:QueryStringParameter Name="AlbumID" Type="Int32" QueryStringField="AlbumID" />
		</SelectParameters>
		<InsertParameters>
			<asp:QueryStringParameter Name="AlbumID" Type="Int32" QueryStringField="AlbumID" />
		</InsertParameters>
	</asp:ObjectDataSource>
	
	<asp:ObjectDataSource ID="ObjectDataSource2" Runat="server" TypeName="PhotoManager" 
		SelectMethod="ListUploadDirectory" >
	</asp:ObjectDataSource>
	 
</asp:content>
