<?xml version="1.0"?>
<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="xml" indent="yes"/>

  <xsl:template match="/ProcessParameters">
     <xsl:element name="xsl:stylesheet" namespace="http://www.w3.org/1999/XSL/Transform">
	<xsl:attribute name="version">1.0</xsl:attribute>
        <xsl:apply-templates/>
     </xsl:element>
  </xsl:template>

  <xsl:template match="title">
     <xsl:element name="xsl:template">
        <xsl:attribute name="match">/</xsl:attribute>
        <xsl:element name="html">
           <xsl:element name="head"/>
           <xsl:element name="body">
           <h1>Titles:</h1>
           <xsl:element name="OL">
			<xsl:element name="xsl:for-each">
				<xsl:attribute name="select">//book/title</xsl:attribute>
				<xsl:element name="LI">
	               <xsl:element name="xsl:value-of">
	                  <xsl:attribute name="select">.</xsl:attribute>
					</xsl:element>
		       </xsl:element>
	         </xsl:element>
	        </xsl:element>
	      </xsl:element>
           </xsl:element>
        </xsl:element>
  </xsl:template>

  <xsl:template match="author">
      <xsl:element name="xsl:template">
          <xsl:attribute name="match">/</xsl:attribute>
          <xsl:element name="html">
             <xsl:element name="head"/>
             <xsl:element name="body">
             <h1>Authors:</h1>
	        <xsl:element name="Table">
		   <xsl:attribute name="border">1</xsl:attribute>
			<xsl:element name="xsl:for-each">
				<xsl:attribute name="select">//book/author</xsl:attribute>
		      <xsl:element name="TR">
			    <xsl:element name="TD">
	              	       <xsl:element name="xsl:value-of">
	                          <xsl:attribute name="select">last-name</xsl:attribute>
 	                       </xsl:element>
			    </xsl:element>
			    <xsl:element name="TD">
	              	       <xsl:element name="xsl:value-of">
	                          <xsl:attribute name="select">first-name</xsl:attribute>
 	                       </xsl:element>
			    </xsl:element>
			 </xsl:element>
			 </xsl:element>
		      </xsl:element>
	           </xsl:element>
	        </xsl:element>
	     </xsl:element>
  </xsl:template>

</xsl:transform>