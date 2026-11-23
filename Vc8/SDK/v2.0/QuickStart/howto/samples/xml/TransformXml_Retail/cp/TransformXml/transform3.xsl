<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/"><html><head /><body><h1>Authors:</h1><Table border="1"><xsl:for-each select="//book/author"><TR><TD><xsl:value-of select="last-name" /></TD><TD><xsl:value-of select="first-name" /></TD></TR></xsl:for-each></Table></body></html></xsl:template>
</xsl:stylesheet>