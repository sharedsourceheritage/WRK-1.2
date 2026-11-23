<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/"><html><head /><body><h1>Titles:</h1><OL><xsl:for-each select="//book/title"><LI><xsl:value-of select="." /></LI></xsl:for-each></OL></body></html></xsl:template>
</xsl:stylesheet>