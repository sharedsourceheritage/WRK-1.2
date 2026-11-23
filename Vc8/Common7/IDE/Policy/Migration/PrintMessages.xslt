<?xml version="1.0" encoding="UTF-8" ?>
<!-- Copyright (c) Microsoft Corporation. All rights reserved. -->
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="text" encoding="iso-8859-1"  />

<xsl:template match="comment()">
    <xsl:if test="string-length(substring-after(string(.),'ERROR:')) or string-length(substring-after(string(.),'WARNING:')) ">
        <xsl:value-of select="."/>
        <xsl:text>&#255;
</xsl:text>
    </xsl:if>
</xsl:template>

<xsl:template match="text()" />

</xsl:stylesheet>

  