<?xml version = "1.0" encoding = "UTF-8"?>
<xsl:stylesheet version = "1.0"
   xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">
   <xsl:template match = "/">
      <html>
         <body style="background-color:turquoise;">
            <center>
               <h2>Employee Details</h2>
            </center>

            <table border = "5" cellpadding="10" cellspacing="2" bgcolor="red" style="border-radius:5px;">
               <tr bgcolor = "cyan">
                  <th>ID</th>
                  <th>First Name</th>
                  <th>Last Name</th>
                  <th>Nick Name</th>
                  <th>Salary</th>
               </tr>

               <xsl:for-each select="class/employee">
                  <tr>
                     <td bgcolor="yellow">

                        <xsl:value-of select ="@id"/>
                     </td>
                     <td bgcolor="pink">
                        <xsl:value-of select = "firstname"/>
                     </td>
                     <td bgcolor="magenta">
                        <xsl:value-of select = "lastname"/>
                     </td>
                     <td bgcolor="violet">
                        <xsl:value-of select = "nickname"/>
                     </td>
                     <td bgcolor="grey">
                        <xsl:value-of select = "salary"/>
                     </td>
                  </tr>
               </xsl:for-each>
            </table>
         </body>
      </html>
   </xsl:template>
</xsl:stylesheet> 