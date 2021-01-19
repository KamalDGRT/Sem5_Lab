<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="https://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<HTML>
<BODY>
    <TABLE BORDER="10" BGCOLOR="orange" align="center">
        <CAPTION>BOOKS DETAILS</CAPTION>
        <TR>
            <TH>TITLE</TH>
            <TH>AUTHOR</TH>
            <TH>PUBLISHER</TH>
            <TH>PRICE</TH>
        </TR>
    
        <xsl:for-each select="BOOKS/BOOK">
            <TR>
                <TD><xsl:value-of select ="TITLE"/></TD>
                <TD><xsl:value-of select ="AUTHOR"/></TD>
                <TD><xsl:value-of select ="PUBLISHER"/></TD>
                <TD><xsl:value-of select ="PRICE"/></TD>
            </TR>
        </xsl:for-each>
    </TABLE>
</BODY>
</HTML>
</xsl:template>
</xsl:stylesheet>
