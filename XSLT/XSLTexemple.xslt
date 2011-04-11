<?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output method="html" version="1.0" encoding="UTF-8" indent="yes"/>

	<xsl:template match="/">
	<HTML>
		<xsl:apply-templates/>
	</HTML>
	</xsl:template >

	<xsl:template match="rapport">
	<HTML>
		<HEAD>
			<TITLE>XML to HTML</TITLE>
		</HEAD>
		<BODY>
			<xsl:apply-templates/>
		</BODY>
	</HTML>
	</xsl:template >


	<xsl:template match="auteur" >
		<p>
			<b>Auteur : </b> <xsl:apply-templates/>
		</p>
	</xsl:template >

	<xsl:template match="prenom" >
		<xsl:apply-templates/>
	</xsl:template >

	<xsl:template match="nom" >
		<xsl:apply-templates/>
	</xsl:template >

	<xsl:template match="resume" >
		<i><xsl:apply-templates/></i><br/>
	</xsl:template >

	<xsl:template match="chapitre" >
		<xsl:apply-templates/><br/><br/>	
	</xsl:template >


	<xsl:template match="section" >
		<p><xsl:apply-templates/></p>
	</xsl:template >

	
	<xsl:template match="titre" >
		<h2>
			<xsl:apply-templates/>
		</h2>
	</xsl:template >

</xsl:stylesheet>