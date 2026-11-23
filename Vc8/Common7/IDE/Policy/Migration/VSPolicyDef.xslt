<?xml version="1.0" encoding="UTF-8" ?>
<!-- Copyright (c) Microsoft Corporation. All rights reserved. -->
<xsl:stylesheet version = '1.0' 
     xmlns:xsl='http://www.w3.org/1999/XSL/Transform'
     xmlns:tdl="http://www.microsoft.com/schema/EnterpriseTemplates/TDLSchema"
     xmlns="http://schemas.microsoft.com/VSPolicy/PDLSchema"> 
     
<xsl:output method="xml" indent="yes" encoding="utf-8"  />
<xsl:strip-space elements="*" />
<xsl:include href="messages.xslt" />

<xsl:template match="/tdl:TDL"> 
    <PolicyDefinitions Version="8.0">
        <xsl:call-template name="PolicyDefinitions"/>  
    </PolicyDefinitions>
</xsl:template>

<xsl:template match="/TDL">
    <PolicyDefinitions Version="8.0">
        <xsl:message><xsl:value-of select="$error_nonamespace" />
        </xsl:message>
        <xsl:comment><xsl:value-of select="$error_nonamespace" /></xsl:comment>
    </PolicyDefinitions>
</xsl:template>

<xsl:template name="PolicyDefinitions">
    <xsl:if test="tdl:ELEMENTS">
        <ElementDefs>
            <xsl:apply-templates mode="ElementDefs"/>
        </ElementDefs>
    </xsl:if>
    <xsl:if test="tdl:CATEGORIES">
        <CategoryDefs>
            <xsl:apply-templates mode="CategoryDefs"/>
        </CategoryDefs>
    </xsl:if>
    <xsl:if test="tdl:FEATURES">
        <FeatureDefs>
            <xsl:apply-templates mode="FeatureDefs"/>
        </FeatureDefs>
    </xsl:if>
</xsl:template>

<!-- ElementDefs -->

<xsl:template match="tdl:ELEMENTS" mode="ElementDefs">
    <xsl:call-template name="DefsCodeType"/>
    <xsl:call-template name="DefsCodeVariableType"/>
    <xsl:call-template name="DefsReferenceType"/>
    <xsl:call-template name="DefsHtmlElementType"/>
    <xsl:call-template name="DefsProjectType"/>
    <xsl:call-template name="DefsProjectItemType"/>
    <xsl:call-template name="DefsFeaturesType"/>
<!-- picks up every not recognised element. Please remember to update this 
     if filter rules change for any of the above types. -->
    <xsl:apply-templates mode="DefsUnknowns"/>
</xsl:template>

<xsl:template name="DefsCodeType">
    <xsl:for-each select="tdl:*[tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'CODE' ]">
        <CodeType>
            <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

            <xsl:call-template name="sub_SanityCheck"/>
            
            <xsl:call-template name="DefsCodeIdentType"/>
            <xsl:call-template name="FeatureLinksCType"/>
            <xsl:call-template name="PrototypesType"/>
        </CodeType>
    </xsl:for-each>
</xsl:template>

<xsl:template name="DefsCodeVariableType">
    <xsl:for-each select="tdl:*[tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'CODEVARIABLE' ]">
        <CodeVariable>
            <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

            <xsl:call-template name="sub_SanityCheck"/>
            
            <xsl:call-template name="DefsCodeVariableIdentType"/>
            <xsl:call-template name="FeatureLinksTType"/>
        </CodeVariable>
    </xsl:for-each>
</xsl:template>

<xsl:template name="DefsReferenceType">
    <xsl:for-each select="tdl:*[tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'REFERENCE' ]">
        <Reference>
            <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

            <xsl:call-template name="sub_SanityCheck"/>
            
            <xsl:call-template name="DefsReferenceIdentType"/>
        </Reference>
    </xsl:for-each>
</xsl:template>

<xsl:template name="DefsHtmlElementType">
    <xsl:for-each select="tdl:*[tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'HTMLELEMENT' ]">
        <HtmlElement>
            <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

            <xsl:call-template name="sub_SanityCheck"/>
            
            <xsl:call-template name="DefsHtmlElementIdentType"/>
            <xsl:call-template name="FeatureLinksTType"/>
        </HtmlElement>
    </xsl:for-each>
</xsl:template>

<xsl:template name="DefsProjectType">
    <xsl:for-each select="tdl:*[(tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'PROJECT' 
                                or (substring(tdl:ID,1,4) = 'proj' and substring(tdl:ID,1,8) != 'projItem')) ]">
        <Project>
            <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

            <xsl:call-template name="sub_SanityCheck"/>
            
            <xsl:call-template name="DefsProjectIdentType"/>
            <xsl:call-template name="FeatureLinksCType"/>
            <xsl:call-template name="PrototypesType"/>
        </Project>
    </xsl:for-each>
</xsl:template>

<xsl:template name="DefsProjectItemType">
    <xsl:for-each select="tdl:*[tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'PROJECTITEM' or substring(tdl:ID,1,8) = 'projItem']">
        <ProjectItem>
            <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

            <xsl:call-template name="sub_SanityCheck"/>

            <xsl:call-template name="DefsProjectItemIdentType"/>
            <xsl:call-template name="FeatureLinksCType"/>
            <xsl:call-template name="PrototypesType"/>
        </ProjectItem>
    </xsl:for-each>
</xsl:template>

<xsl:template name="DefsFeaturesType">
    <xsl:for-each select="tdl:*[not(tdl:IDENTIFIERS) and not(tdl:PROTOTYPES)]">
        <Feature>
            <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

            <xsl:call-template name="FeatureLinksTCType"/>
        </Feature>
    </xsl:for-each>
</xsl:template>

<xsl:template match="tdl:ELEMENT" name="DefsUnknowns" mode="DefsUnknowns">
    <xsl:choose>
    <xsl:when test="tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'CODE'" />
    <xsl:when test="tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'CODEVARIABLE' " />
    <xsl:when test="tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'REFERENCE' " />
    <xsl:when test="tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'HTMLELEMENT' " />
    <xsl:when test="(tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'PROJECT' 
                                or (substring(tdl:ID,1,4) = 'proj' and substring(tdl:ID,1,8) != 'projItem')) " />
    <xsl:when test="tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'PROJECTITEM' or substring(tdl:ID,1,8) = 'projItem'" />
    <xsl:when test="not(tdl:IDENTIFIERS) and not(tdl:PROTOTYPES)" />
    <xsl:otherwise>
        <xsl:message><xsl:value-of select="concat(tdl:ID,': ',$error_unknown)" />
            <xsl:value-of select="."/>
        </xsl:message>
        <xsl:comment><xsl:value-of select="concat(tdl:ID,': ',$error_unknown)" /></xsl:comment>
    </xsl:otherwise>
    </xsl:choose>
</xsl:template>

<xsl:template name="DefsCodeIdentType">
    <xsl:if test="tdl:IDENTIFIERS/tdl:IDENTIFIER">
        <Identifiers>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='Kind' or ./tdl:NAME='KIND']" mode="ValueType">
                <xsl:with-param name="key">Kind</xsl:with-param>
            </xsl:apply-templates>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='Implements' or ./tdl:NAME='IMPLEMENTS']" mode="ValueType">
                <xsl:with-param name="key">Implements</xsl:with-param>
            </xsl:apply-templates>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='Inherits' or ./tdl:NAME='INHERITS']" mode="ValueType">
                <xsl:with-param name="key">Inherits</xsl:with-param>
            </xsl:apply-templates> 
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[ substring-before( tdl:NAME ,':' ) ='Attribute' or substring-before( tdl:NAME ,':' ) ='ATTRIBUTE' ]" mode="NameValueType">
                <xsl:with-param name="key">Attribute</xsl:with-param>
            </xsl:apply-templates>
        </Identifiers>
    </xsl:if>
</xsl:template>

<xsl:template name="DefsCodeVariableIdentType">
    <xsl:if test="tdl:IDENTIFIERS/tdl:IDENTIFIER">
        <Identifiers>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='TYPENAME']" mode="ValueType">
                <xsl:with-param name="key">TypeName</xsl:with-param>
            </xsl:apply-templates>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='TYPEINHERITS']" mode="ValueType">
                <xsl:with-param name="key">TypeInherits</xsl:with-param>
            </xsl:apply-templates>
        </Identifiers>
    </xsl:if>
</xsl:template>

<xsl:template name="DefsReferenceIdentType">
    <xsl:if test="tdl:IDENTIFIERS/tdl:IDENTIFIER">
        <Identifiers>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='FileName']" mode="ValueType">
                <xsl:with-param name="key">Filename</xsl:with-param>
            </xsl:apply-templates>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='MajorVersion']" mode="ValueType">
                <xsl:with-param name="key">MajorVersion</xsl:with-param>
            </xsl:apply-templates>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='MinorVersion']" mode="ValueType">
                <xsl:with-param name="key">MinorVersion</xsl:with-param>
            </xsl:apply-templates>
        </Identifiers>
    </xsl:if>
</xsl:template>

<xsl:template name="DefsHtmlElementIdentType">
    <xsl:if test="tdl:IDENTIFIERS/tdl:IDENTIFIER">
        <Identifiers>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='TAG']" mode="ValueType">
                <xsl:with-param name="key">Tag</xsl:with-param>
            </xsl:apply-templates>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[ substring-before( tdl:NAME ,':' ) ='Attribute' ]" mode="NameValueType">
                <xsl:with-param name="key">Attribute</xsl:with-param>
            </xsl:apply-templates>
        </Identifiers>
    </xsl:if>
</xsl:template>

<xsl:template name="DefsProjectIdentType">
    <xsl:if test="tdl:IDENTIFIERS/tdl:IDENTIFIER">
        <Identifiers>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='Kind' or ./tdl:NAME='KIND']" mode="ValueType">
                <xsl:with-param name="key">Kind</xsl:with-param>
            </xsl:apply-templates>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='UniqueId' or ./tdl:NAME='UNIQUEID']" mode="ValueType">
                <xsl:with-param name="key">UniqueId</xsl:with-param>
            </xsl:apply-templates>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='FileExtension'  or ./tdl:NAME='FILEEXTENSION']" mode="ValueType">
                <xsl:with-param name="key">FileExtension</xsl:with-param>
            </xsl:apply-templates> 
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[ substring-before( tdl:NAME ,':' ) ='Property' or  substring-before( tdl:NAME ,':' ) ='PROPERTY'  ]" mode="NameValueType">
                <xsl:with-param name="key">Property</xsl:with-param>
            </xsl:apply-templates>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[ substring-before( tdl:NAME ,':' ) ='Global' or substring-before( tdl:NAME ,':' ) ='GLOBAL']" mode="NameValueType">
                <xsl:with-param name="key">Global</xsl:with-param>
            </xsl:apply-templates>
        </Identifiers>
    </xsl:if>
</xsl:template>

<xsl:template name="DefsProjectItemIdentType">
    <xsl:if test="tdl:IDENTIFIERS/tdl:IDENTIFIER">
        <Identifiers>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='Kind' or ./tdl:NAME='KIND']" mode="ValueType">
                <xsl:with-param name="key">Kind</xsl:with-param>
            </xsl:apply-templates>
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[./tdl:NAME='FileExtension'  or ./tdl:NAME='FILEEXTENSION']" mode="ValueType">
                <xsl:with-param name="key">FileExtension</xsl:with-param>
            </xsl:apply-templates> 
            <xsl:apply-templates select="(tdl:IDENTIFIERS/tdl:IDENTIFIER[1])/tdl:IDENTIFIERDATA[ substring-before( tdl:NAME ,':' ) ='Property' or substring-before( tdl:NAME ,':' ) ='PROPERTY']" mode="NameValueType">
                <xsl:with-param name="key">Property</xsl:with-param>
            </xsl:apply-templates>
        </Identifiers>
    </xsl:if>
</xsl:template>

<xsl:template match="tdl:IDENTIFIERDATA" mode="ValueType" >
    <xsl:param name="key" />
    <xsl:element name="{$key}"><xsl:value-of select="tdl:VALUE"/></xsl:element>
</xsl:template>

<xsl:template match="tdl:IDENTIFIERDATA" mode="NameValueType" >
    <xsl:param name="key" /> 
    <xsl:element name="{$key}">
        <xsl:attribute name="Name"><xsl:value-of select="substring-after(tdl:NAME,':')"/></xsl:attribute>
        <xsl:attribute name="Value"><xsl:value-of select="tdl:VALUE"/></xsl:attribute>
    </xsl:element>
</xsl:template>

<xsl:template name="FeatureLinksCType">
    <xsl:if test="tdl:FEATURELINKS/tdl:MENULINKS">
    <FeatureLinks>
        <CommandLinks>
            <xsl:apply-templates select="tdl:FEATURELINKS/tdl:MENULINKS" mode="CommandLinkType" />
        </CommandLinks>
    </FeatureLinks>
    </xsl:if>
</xsl:template>

<xsl:template name="FeatureLinksTType">
    <xsl:if test="tdl:FEATURELINKS/tdl:TOOLBOXLINKS">
    <FeatureLinks>
        <ToolboxItemLinks>
            <xsl:apply-templates select="tdl:FEATURELINKS/tdl:TOOLBOXLINKS" mode="ToolboxItemLinkType" />
        </ToolboxItemLinks>
    </FeatureLinks>
    </xsl:if>
</xsl:template>

<xsl:template name="FeatureLinksTCType">
    <FeatureLinks>
        <xsl:if test="tdl:FEATURELINKS/tdl:TOOLBOXLINKS">
            <ToolboxItemLinks>
                <xsl:apply-templates select="tdl:FEATURELINKS/tdl:TOOLBOXLINKS" mode="ToolboxItemLinkType" />
            </ToolboxItemLinks>
        </xsl:if>
        <xsl:if test="tdl:FEATURELINKS/tdl:MENULINKS">
            <CommandLinks>
                <xsl:apply-templates select="tdl:FEATURELINKS/tdl:MENULINKS" mode="CommandLinkType" />
            </CommandLinks>
        </xsl:if>
    </FeatureLinks>
</xsl:template>

<xsl:template match="tdl:MENULINK" name="CommandLinkType" mode="CommandLinkType">
    <CommandLink><xsl:value-of select="."/></CommandLink>
</xsl:template>

<xsl:template match="tdl:TOOLBOXLINK" name="ToolboxItemLinkType" mode="ToolboxItemLinkType">
    <ToolboxItemLink><xsl:value-of select="."/></ToolboxItemLink>
</xsl:template>

<xsl:template name="PrototypesType">
    <xsl:if test="tdl:PROTOTYPES/tdl:PROTOTYPE">
        <Prototypes>
            <xsl:apply-templates select="tdl:PROTOTYPES/tdl:PROTOTYPE" mode="PrototypeType" />
        </Prototypes>
    </xsl:if>
</xsl:template>

<xsl:template match="tdl:PROTOTYPE" name="PrototypeType" mode="PrototypeType">
    <Prototype><xsl:value-of select="."/></Prototype>
</xsl:template>

<xsl:template name="sub_SanityCheck">
    <xsl:if test="count(tdl:IDENTIFIERS/tdl:IDENTIFIER) > 1">
        <xsl:message><xsl:value-of select="concat(tdl:ID,': ',$warning_multipleid)" />
            <xsl:value-of select="."/>
        </xsl:message>
        <xsl:comment><xsl:value-of select="concat(tdl:ID,': ',$warning_multipleid)" /></xsl:comment>
        <xsl:comment><xsl:copy-of select="."/></xsl:comment>
    </xsl:if>
    <xsl:if test="not( tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE )">
        <xsl:message><xsl:value-of select="concat(tdl:ID,': ',$warning_uncertain)" />
            <xsl:value-of select="."/>
        </xsl:message>
        <xsl:comment><xsl:value-of select="concat(tdl:ID,': ',$warning_uncertain)" /></xsl:comment>
    </xsl:if>
</xsl:template>

<!-- CategoryDefs -->

<xsl:template match="tdl:CATEGORIES" mode="CategoryDefs">
    <xsl:apply-templates mode="CategoryDefs"/>
</xsl:template>

<xsl:template match="tdl:CATEGORY" mode="CategoryDefs">
    <Category>
        <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

        <xsl:apply-templates mode="CategoryDefs"/>
    </Category>
</xsl:template>

<xsl:template match="tdl:CATEGORYMEMBER" mode="CategoryDefs">
    <CategoryMember><xsl:value-of select="."/></CategoryMember>
</xsl:template>

<!-- FeatureDefs -->

<xsl:template match="tdl:FEATURES" mode="FeatureDefs">
    <Commands>
        <xsl:apply-templates select="tdl:MENUS" mode="FeatureDefs"/>
    </Commands>
    <ToolboxItems>
        <xsl:apply-templates select="tdl:TOOLBOXITEMS" mode="FeatureDefs"/>
    </ToolboxItems>
</xsl:template>

<xsl:template match="tdl:MENUS" mode="FeatureDefs">
    <xsl:apply-templates mode="FeatureDefs"/>
</xsl:template>

<xsl:template match="tdl:TOOLBOXITEMS" mode="FeatureDefs">
    <xsl:apply-templates mode="FeatureDefs"/>
</xsl:template>

<xsl:template match="tdl:MENU" mode="FeatureDefs">
    <Command>
        <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>
        <xsl:choose>
        <xsl:when test="tdl:CMDID and tdl:GUID">
            <CmdId><xsl:value-of select="tdl:CMDID"/></CmdId>
            <Guid><xsl:value-of select="tdl:GUID"/></Guid>
        </xsl:when>
        <xsl:otherwise>
            <xsl:message><xsl:value-of select="concat(tdl:ID,': ',$error_missingdata)" />
                <xsl:value-of select="."/>
            </xsl:message>
            <xsl:comment><xsl:value-of select="concat(tdl:ID,': ',$error_missingdata)" /></xsl:comment>
            <xsl:comment><xsl:copy-of select="."/></xsl:comment>
        </xsl:otherwise>
        </xsl:choose>
    </Command>
</xsl:template>

<xsl:template match="tdl:TOOLBOXITEM" mode="FeatureDefs">
    <ToolboxItem>
        <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>
        <Descriptor><xsl:value-of select="tdl:DESCRIPTOR"/></Descriptor>
    </ToolboxItem>
</xsl:template>

<!-- prevents default template matches to sprout out plain text -->
<xsl:template match="tdl:*" mode="ElementDefs"/>
<xsl:template match="tdl:*" mode="CategoryDefs"/>
<xsl:template match="tdl:*" mode="FeatureDefs"/>


</xsl:stylesheet>
