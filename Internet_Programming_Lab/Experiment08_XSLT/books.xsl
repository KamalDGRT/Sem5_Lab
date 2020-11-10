<?xml version="1.0"?>

<xsl:stylesheet version = "1.0"
   xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
<html>
<body>
<table  style="border:1 px solid black">
<caption> BOOKS DETAILS </caption>
<tr>
<th> TITLE </th>
<th> AUTHOR </th>
<th> PUBLISHER </th>
<th> PRICE </th>
</tr>
<xsl:for-each select="BOOKS/BOOK">
<tr>
<td><xsl:value-of select="TITLE"/></td>
<td><xsl:value-of select="AUTHOR"/></td>
<td><xsl:value-of select="PUBLISHER"/></td>
<td><xsl:value-of select="PRICE"/></td>
</tr>
</xsl:for-each>
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>
