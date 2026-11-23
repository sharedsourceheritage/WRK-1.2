<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/SomeList"><html><head /><body><UL><xsl:for-each select="item"><LI><xsl:value-of select="." /></LI></xsl:for-each></UL></body></html></xsl:template>
</xsl:stylesheet>