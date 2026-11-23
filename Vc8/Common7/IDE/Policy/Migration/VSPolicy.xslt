<?xml version="1.0" encoding="UTF-8" ?>
<!-- Copyright (c) Microsoft Corporation. All rights reserved. -->
<xsl:stylesheet version = '1.0' 
     xmlns:xsl='http://www.w3.org/1999/XSL/Transform'
     xmlns:tdl="http://www.microsoft.com/schema/EnterpriseTemplates/TDLSchema"
     xmlns="http://schemas.microsoft.com/VSPolicy/PDLSchema">
<xsl:param name="DefinitionFile" select="vside.vspolicydef"/>

<xsl:output method="xml" indent="yes" encoding="utf-8"  />
<xsl:strip-space elements="*" />
<xsl:include href="messages.xslt" />

<xsl:template name="SymbolMap">
    <xsl:param name="Key"/>
    
    <xsl:choose>
        <xsl:when test="$Key = 'INCLUDE'">Include</xsl:when>
        <xsl:when test="$Key = 'EXCLUDE'">Exclude</xsl:when>
        <xsl:when test="$Key = 'INCLUDEEXCLUDE'">IncludeFirst</xsl:when>
        <xsl:when test="$Key = 'EXCLUDEINCLUDE'">ExcludeFirst</xsl:when>
        <xsl:when test="$Key = 'PERMISSIVE'">Permissive</xsl:when>
        <xsl:when test="$Key = 'RESTRICTIVE'">Restrictive</xsl:when>
        <xsl:otherwise><xsl:value-of select="$Key"/></xsl:otherwise>
    </xsl:choose>
</xsl:template>


<xsl:template match="/tdl:TDL"> 
    <PolicyActions Version="8.0">
        <Definitions>
            <Definition><xsl:value-of select="$DefinitionFile"/></Definition>
        </Definitions>
        <xsl:apply-templates mode="PolicyActionsType"/>  
    </PolicyActions>
</xsl:template>

<xsl:template match="/TDL">
    <PolicyActions Version="8.0">
        <xsl:message><xsl:value-of select="$error_nonamespace" />
        </xsl:message>
        <xsl:comment><xsl:value-of select="$error_nonamespace" /></xsl:comment>
    </PolicyActions>
</xsl:template>

<xsl:template match="*" />

<xsl:template match="tdl:DEFAULTSETTINGS" mode="PolicyActionsType" >
    <DefaultSettings>
        <xsl:if test="tdl:DEFAULTACTION">
            <xsl:attribute name="DefaultAction">
                <xsl:call-template name="SymbolMap">
                    <xsl:with-param name="Key"><xsl:value-of select="tdl:DEFAULTACTION"/></xsl:with-param>
                </xsl:call-template>
            </xsl:attribute>
        </xsl:if>
        <xsl:if test="tdl:ORDER">
            <xsl:attribute name="Order">
                <xsl:call-template name="SymbolMap">
                    <xsl:with-param name="Key"><xsl:value-of select="tdl:ORDER"/></xsl:with-param>
                </xsl:call-template>
            </xsl:attribute>
        </xsl:if>
        <xsl:if test="tdl:POLICYMODE">
            <xsl:attribute name="PolicyMode">
                <xsl:call-template name="SymbolMap">
                    <xsl:with-param name="Key"><xsl:value-of select="tdl:POLICYMODE"/></xsl:with-param>
                </xsl:call-template>
            </xsl:attribute>
        </xsl:if>

        <xsl:apply-templates mode="ConstraintsType" />
    </DefaultSettings>
</xsl:template>

<xsl:template match="tdl:CONSTRAINTS" mode="ConstraintsType">
    <Constraints>
        <!-- call 3 times with the select attrib to force ordering -->
        <xsl:apply-templates select="tdl:TOOLBOXCONSTRAINTS" mode="ConstraintsType" />
        <xsl:apply-templates select="tdl:MENUCONSTRAINTS" mode="ConstraintsType" />
        <xsl:apply-templates select="tdl:PROPERTYCONSTRAINTS" mode="ConstraintsType" />
    </Constraints>
</xsl:template>

<xsl:template match="tdl:MEMBERCONSTRAINTS" mode="MemberConstraintsType">
    <MemberConstraints>
        <xsl:apply-templates select="tdl:MEMBERCONSTRAINT" mode="MemberConstraintType" />
    </MemberConstraints>
</xsl:template>
<xsl:template match="tdl:*" mode="MemberConstraintsType"/>

<xsl:template match="tdl:MEMBERCONSTRAINT" mode="MemberConstraintType">
    <MemberConstraint>
        <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

        <!-- call 3 times with the select attrib to force ordering -->
        <xsl:apply-templates select="tdl:TOOLBOXCONSTRAINTS" mode="ConstraintsType" />
        <xsl:apply-templates select="tdl:MENUCONSTRAINTS" mode="ConstraintsType" />
        <xsl:apply-templates select="tdl:PROPERTYCONSTRAINTS" mode="ConstraintsType" />
    </MemberConstraint>
</xsl:template>

<xsl:template match="tdl:TOOLBOXCONSTRAINTS" name="ToolboxItemConstraintsType" mode="ConstraintsType">
    <ToolboxItemConstraints>
        <xsl:for-each select="tdl:TOOLBOXCONSTRAINT">
            <ToolboxItemConstraint>
                <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>
                <xsl:attribute name="Visible"><xsl:value-of select="tdl:ENABLED"/></xsl:attribute>
            </ToolboxItemConstraint>
        </xsl:for-each>
    </ToolboxItemConstraints>
</xsl:template>

<xsl:template match="tdl:MENUCONSTRAINTS" name="CommandConstraintsType" mode="ConstraintsType">
    <CommandConstraints>
        <xsl:for-each select="tdl:MENUCONSTRAINT">
            <CommandConstraint>
                <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>
                <xsl:attribute name="Enabled"><xsl:value-of select="tdl:ENABLED"/></xsl:attribute>
            </CommandConstraint>
        </xsl:for-each>
    </CommandConstraints>
</xsl:template>

<xsl:template match="tdl:PROPERTYCONSTRAINTS" name="PropertyConstraintsType" mode="ConstraintsType">
    <PropertyConstraints>
        <xsl:for-each select="tdl:PROPERTYCONSTRAINT">
            <PropertyConstraint>
                <xsl:attribute name="Name"><xsl:value-of select="tdl:NAME"/></xsl:attribute>
                <xsl:attribute name="ReadOnly"><xsl:value-of select="tdl:READONLY"/></xsl:attribute>
                <xsl:if test="tdl:DEFAULT">
                    <Fixed><xsl:value-of select="tdl:DEFAULT" /></Fixed>
                </xsl:if>
                <xsl:if test="tdl:MINVALUE or tdl:MAXVALUE">
                    <xsl:element name="Range">
                        <xsl:attribute name="Minimum"><xsl:value-of select="tdl:MINVALUE" /></xsl:attribute>
                        <xsl:attribute name="Maximum"><xsl:value-of select="tdl:MAXVALUE" /></xsl:attribute>
                    </xsl:element>
                </xsl:if>
            </PropertyConstraint>
        </xsl:for-each>
    </PropertyConstraints>
</xsl:template>
<xsl:template match="tdl:*" mode="ConstraintsType" />


<xsl:template match="tdl:ELEMENTS" mode="PolicyActionsType">
    <Elements>
        <xsl:call-template name="CodeType"/>
        <xsl:call-template name="CodeVariableType"/>
        <xsl:call-template name="ReferenceType"/>
        <xsl:call-template name="HtmlElementType"/>
        <xsl:call-template name="ProjectType"/>
        <xsl:call-template name="ProjectItemType"/>
    <!-- picks up every not recognised element. Please remember to update this 
        if filter rules change for any of the above types. -->
        <xsl:apply-templates mode="Unknowns"/>
    </Elements>
</xsl:template>

<xsl:template name="CodeType">
    <xsl:for-each select="tdl:*[tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'CODE'
                            and (tdl:CONSTRAINTS or tdl:ELEMENTSET) ]">
        <CodeType>
            <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

            <xsl:call-template name="sub_SanityCheck"/>

            <xsl:apply-templates select="tdl:CONSTRAINTS" mode="ConstraintsType"/>
            <xsl:apply-templates select="tdl:ELEMENTSET" mode="ElementSetType"/>
        </CodeType>
    </xsl:for-each>
</xsl:template>

<xsl:template name="CodeVariableType">
    <xsl:for-each select="tdl:*[tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'CODEVARIABLE' 
                             and (tdl:CONSTRAINTS or tdl:ELEMENTSET) ]">
        <CodeVariable>
            <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

            <xsl:call-template name="sub_SanityCheck"/>

            <xsl:apply-templates select="tdl:CONSTRAINTS" mode="ConstraintsType"/>
            <xsl:apply-templates select="tdl:ELEMENTSET" mode="ElementSetType"/>
        </CodeVariable>
    </xsl:for-each>
</xsl:template>

<xsl:template name="ReferenceType">
    <xsl:for-each select="tdl:*[tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'REFERENCE' 
                             and (tdl:CONSTRAINTS) ]">
        <Reference>
            <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

            <xsl:call-template name="sub_SanityCheck"/>
            
            <xsl:apply-templates select="tdl:CONSTRAINTS" mode="ConstraintsType"/>
        </Reference>
    </xsl:for-each>
</xsl:template>

<xsl:template name="HtmlElementType">
    <xsl:for-each select="tdl:*[tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'HTMLELEMENT' 
                             and (tdl:CONSTRAINTS or tdl:ELEMENTSET) ]">
        <HtmlElement>
            <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

            <xsl:call-template name="sub_SanityCheck"/>
            
            <xsl:apply-templates select="tdl:CONSTRAINTS" mode="ConstraintsType"/>
            <xsl:apply-templates select="tdl:ELEMENTSET" mode="ElementSetType"/>
        </HtmlElement>
    </xsl:for-each>
</xsl:template>

<xsl:template name="ProjectType">
    <xsl:for-each select="tdl:*[(tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'PROJECT' 
                                or (substring(ID,1,4) = 'proj' and substring(ID,1,8) != 'projItem'))
                             and (tdl:CONSTRAINTS or tdl:ELEMENTSET or tdl:CONTEXT) ]">
        <Project>
            <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

            <xsl:call-template name="sub_SanityCheck"/>

            <xsl:apply-templates select="tdl:CONTEXT" mode="ContextType"/>
            <xsl:apply-templates select="tdl:CONSTRAINTS" mode="ConstraintsType"/>
            <xsl:apply-templates select="tdl:ELEMENTSET" mode="ElementSetType"/>
        </Project>
    </xsl:for-each>
</xsl:template>

<xsl:template name="ProjectItemType">
    <xsl:for-each select="tdl:*[(tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'PROJECTITEM' or substring(ID,1,8) = 'projItem')
                            and (tdl:CONSTRAINTS or tdl:ELEMENTSET or tdl:CONTEXT) ]">
        <ProjectItem>
            <xsl:attribute name="Id"><xsl:value-of select="tdl:ID"/></xsl:attribute>

            <xsl:call-template name="sub_SanityCheck"/>

            <xsl:apply-templates select="tdl:CONTEXT" mode="ContextType"/>
            <xsl:apply-templates select="tdl:CONSTRAINTS" mode="ConstraintsType"/>
            <xsl:apply-templates select="tdl:ELEMENTSET" mode="ElementSetType"/>
        </ProjectItem>
    </xsl:for-each>
</xsl:template>

<xsl:template match="tdl:ELEMENT" name="Unknowns" mode="Unknowns">
    <xsl:choose>
    <xsl:when test="tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'CODE'" />
    <xsl:when test="tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'CODEVARIABLE' " />
    <xsl:when test="tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'REFERENCE' " />
    <xsl:when test="tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'HTMLELEMENT' " />
    <xsl:when test="(tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'PROJECT' 
                                or (substring(tdl:ID,1,4) = 'proj' and substring(tdl:ID,1,8) != 'projItem')) " />
    <xsl:when test="tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE = 'PROJECTITEM' or substring(tdl:ID,1,8) = 'projItem'" />
    <xsl:otherwise>
        <!-- only output any warning if this element has actions in it -->
        <xsl:if test="(tdl:CONSTRAINTS or tdl:ELEMENTSET or tdl:CONTEXT)">
            <xsl:message><xsl:value-of select="concat(tdl:ID,': ',$error_unknown)" />
                <xsl:value-of select="."/>
            </xsl:message>
            <xsl:comment><xsl:value-of select="concat(tdl:ID,': ',$error_unknown)" /></xsl:comment>
        </xsl:if>
    </xsl:otherwise>
    </xsl:choose>
</xsl:template>
<xsl:template match="tdl:*" mode="Unknowns"/>

<xsl:template name="sub_SanityCheck">
    <xsl:if test="not( tdl:IDENTIFIERS/tdl:IDENTIFIER/tdl:TYPE )">
        <xsl:message><xsl:value-of select="concat(tdl:ID,': ',$warning_uncertain)" />
            <xsl:value-of select="."/>
        </xsl:message>
        <xsl:comment><xsl:value-of select="concat(tdl:ID,': ',$warning_uncertain)" /></xsl:comment>
    </xsl:if>
</xsl:template>

<xsl:template name="ElementSetType" match="tdl:ELEMENTSET" mode="ElementSetType">
    <ElementSet>
        <xsl:if test="tdl:DEFAULTACTION">
            <xsl:attribute name="DefaultAction">
                <xsl:call-template name="SymbolMap">
                    <xsl:with-param name="Key"><xsl:value-of select="tdl:DEFAULTACTION"/></xsl:with-param>
                </xsl:call-template>
            </xsl:attribute>
        </xsl:if>
        <xsl:if test="tdl:ORDER">
            <xsl:attribute name="Order">
                <xsl:call-template name="SymbolMap">
                    <xsl:with-param name="Key"><xsl:value-of select="tdl:ORDER"/></xsl:with-param>
                </xsl:call-template>
            </xsl:attribute>
        </xsl:if>
        <xsl:if test="tdl:POLICYMODE">
            <xsl:attribute name="PolicyMode">
                <xsl:call-template name="SymbolMap">
                    <xsl:with-param name="Key"><xsl:value-of select="tdl:POLICYMODE"/></xsl:with-param>
                </xsl:call-template>
            </xsl:attribute>
        </xsl:if>
        <xsl:apply-templates mode="ConstraintsType"/>
        <xsl:apply-templates mode="MemberConstraintsType"/>
        <xsl:apply-templates mode="IncludeExcludeType"/>
    </ElementSet>
</xsl:template>

<xsl:template match="tdl:INCLUDE" mode="IncludeExcludeType">
    <Include><xsl:value-of select="."/></Include>
</xsl:template>

<xsl:template match="tdl:EXCLUDE" mode="IncludeExcludeType">
    <Exclude><xsl:value-of select="."/></Exclude>
</xsl:template>
<xsl:template match="*" mode="IncludeExcludeType"/>


<xsl:template name="ContextType" match="tdl:CONTEXT" mode="ContextType">
    <Context>
        <xsl:apply-templates select="tdl:CTXTKEYWORD" mode="ContextType"/> 
        <xsl:apply-templates select="tdl:CTXTATTRIBUTE" mode="ContextType"/> 
    </Context>
</xsl:template>

<xsl:template name="ContextKeyword" match="tdl:CTXTKEYWORD" mode="ContextType">
    <ContextKeyword>
        <xsl:value-of select="."/>
    </ContextKeyword>
</xsl:template>

<xsl:template name="ContextAttribute" match="tdl:CTXTATTRIBUTE" mode="ContextType">
    <ContextAttribute>
        <xsl:attribute name="Name"><xsl:value-of select="tdl:NAME"/></xsl:attribute>
        <xsl:attribute name="Value"><xsl:value-of select="tdl:VALUE"/></xsl:attribute>
    </ContextAttribute>
</xsl:template>

<xsl:template match="tdl:*" mode="PolicyActionsType"/>


</xsl:stylesheet>
