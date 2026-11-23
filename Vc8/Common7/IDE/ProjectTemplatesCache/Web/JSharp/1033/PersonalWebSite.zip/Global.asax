<%@ Application Language="VJ#" %>

<script runat="server">

	void Application_Start(Object sender, EventArgs e) {
		SiteMap.add_SiteMapResolve(new SiteMapResolveEventHandler(AppendQueryString));
		if (!Roles.RoleExists("Administrators")) Roles.CreateRole("Administrators");
		if (!Roles.RoleExists("Friends")) Roles.CreateRole("Friends");
	}

	SiteMapNode AppendQueryString(Object o, SiteMapResolveEventArgs e) {
		if (SiteMap.get_CurrentNode() != null) {
			SiteMapNode temp;
			temp = SiteMap.get_CurrentNode().Clone(true);
			Uri u = new Uri(e.get_Context().get_Request().get_Url().ToString());
			temp.set_Url(temp.get_Url() + u.get_Query());
			if (temp.get_ParentNode() != null) {
				temp.get_ParentNode().set_Url(temp.get_ParentNode().get_Url() + u.get_Query());
			}
			return temp;
		} else {
			return null;
		}
	}

</script>
