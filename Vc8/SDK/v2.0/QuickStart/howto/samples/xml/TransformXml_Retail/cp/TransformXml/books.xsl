<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">
	<HTML>
	<BODY>
	<H1>Books:</H1>
		<xsl:apply-templates/>
	</BODY>
	</HTML>
	</xsl:template>

	<xsl:template match="bookstore">
	<!-- Prices and books -->
		<TABLE Border="1">
		<TH>Title</TH>
		<TH>ISBN</TH>
		<TH>Price</TH>
			<xsl:apply-templates select="book"/>
		</TABLE>
	</xsl:template>

	<xsl:template match="book">
		<TR>
			<TD><xsl:apply-templates select="title"/></TD>
			<TD><xsl:value-of select="@ISBN"/></TD>
			<TD><xsl:apply-templates select="price"/></TD>
		</TR>
	</xsl:template>
	<xsl:template match="title">
		<xsl:value-of select="."/>
	</xsl:template>
	
	<xsl:template match="price">
		<xsl:value-of select="."/>
	</xsl:template>
	
</xsl:stylesheet>
