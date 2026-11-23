<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/SomeTable"><html><head /><body><Table border="1"><xsl:for-each select="row"><TR><xsl:for-each select="column"><TD><xsl:value-of select="." /></TD></xsl:for-each></TR></xsl:for-each></Table></body></html></xsl:template>
</xsl:stylesheet>