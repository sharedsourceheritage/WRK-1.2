<?xml version='1.0' ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0" xmlns:x="http://schemas.microsoft.com/sqlserver/2004/07/adventure-works/ProductModelManuInstructions" xmlns:zz="http://schemas.microsoft.com/office/word/2002/8/wordml" xmlns:html="http://www.w3.org/1999/xhtml">
<xsl:output indent="no" method="html"/>

<!-- 
=====================================================================

  File:      ManuInstructions.xsl for Manufacuting Instructions XML sample
  Summary:   Transform Manufacturing Instructions XML for display in a browser
  Date:	     February 11, 2004

=====================================================================

  This file is part of the Microsoft SQL Server Code Samples.
  Copyright (C) Microsoft Corporation.  All rights reserved.

This source code is intended only as a supplement to Microsoft
Development Tools and/or on-line documentation.  See these other
materials for detailed information regarding Microsoft code samples.

THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

======================================================= 
-->
    <xsl:template match="/" >
	<xsl:apply-templates />
    </xsl:template>
    <xsl:template match="x:root" >
        <html:HTML>
	    <HEAD>
                <STYLE>
                    body { font-family:Arial, Helvetica, sans-serif; }
                    h1 { font-size:18pt; color:#336699 }
                    h2 { font-size:14pt; color:#336699 }
                </STYLE>
	    </HEAD>
            <BODY>               
                <H1 align="center" style="color:navy" >
                    <xsl:value-of select="@ProductModelName"/> - 
                    <xsl:value-of select="@ProductModelID"/>
                </H1>
                <xsl:if test="//x:Location">
                     <TABLE width="100%" align="left" >
                         <TR>
                             <TD>
                                <xsl:apply-templates select="x:Location" />
                             </TD>
                         </TR>
                     </TABLE>
                </xsl:if>
            </BODY>
        </html:HTML>
    </xsl:template>

    <xsl:template match="x:Location">
        <H2 align="left" style="color:red" >
    WorkCenter <xsl:value-of select="@LocationID" />
  </H2>
        <xsl:if test="//x:step">
            <TABLE width="90%" align="CENTER" border="1">
                <TR>
                    <TD>
                        <xsl:apply-templates select="x:step" />
                    </TD>
                </TR>
            </TABLE>
        </xsl:if>
    </xsl:template>
    <!--
<xsl:template match="x:step" >
  <TABLE ALIGN="center" ><TR><TD xmlns="http://www.w3.org/1999/xhtml">
    <xsl:value-of select="." />
   </TD></TR>
  </TABLE>
</xsl:template>
-->
    <xsl:template match="x:step" >
        <TR VALIGN="TOP">
            <TD ALIGN="LEFT">
                <xsl:value-of select="."/>
            </TD>
            <xsl:if test=".//x:diag">
                <TD ALIGN="CENTER">
                   <embed width="300" height="200" type="image/svg+xml" 
             src="http://localhost/xmlmanuinstructions/GetDiagram.ashx?ProductModelID={ancestor::x:root/@ProductModelID}&amp;IllustrationID={.//x:diag}" /> 
                </TD>
            </xsl:if>
        </TR>
    </xsl:template>
</xsl:stylesheet>