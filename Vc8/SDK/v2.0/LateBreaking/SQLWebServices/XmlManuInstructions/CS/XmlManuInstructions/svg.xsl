<xsl:stylesheet version="1.0" 
		xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  		xmlns:svg="http://www.w3.org/2000/svg">
<xsl:output method="html" />

<!-- =====================================================================

  File:      svg.xsl for Manufacuting Instructions XML sample
  Summary:   Transform XML for  manufacturing instruction illustrations for the specified product.
  Date:	     June 5, 2003

=====================================================================

  This file is part of the Microsoft SQL Server Code Samples.
  Copyright (C) 2003 Microsoft Corporation.  All rights reserved.

This source code is intended only as a supplement to Microsoft
Development Tools and/or on-line documentation.  See these other
materials for detailed information regarding Microsoft code samples.

THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

======================================================= -->

<xsl:template match="*"><xsl:copy><xsl:copy-of select="@*"/><xsl:apply-templates/></xsl:copy></xsl:template>
<xsl:template match="svg:*"><xsl:element name="svg:{local-name(.)}"><xsl:copy-of select="@*"/><xsl:apply-templates/></xsl:element></xsl:template>

</xsl:stylesheet>
