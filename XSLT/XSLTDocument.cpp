#include "XSLTDocument.h"

Element XSLTDocument::ApplyTo(Element XMLTree)
{
	Element * HTMLTree;
	
	if (HTMLTree == NULL)
	{
		HTMLTree = FindByAttribute("match", "/"); //TODO faire une copie.
		/*
		Recopier tous les fils de HTMLTree jusqu'à tomber sur apply templates
		
		For (i=0;i<HTMLTree.Fils.length;i++)
			ApplyTo(HTMLTree.Fils[i])
		*/
	}
	else
	{		
		HTMLTree = FindByAttribute("match", XMLTree.name); //TODO faire une copie.
		For (i=0;i<HTMLTree.Fils.length;i++)
			ApplyTo(HTMLTree.Fils[i])		
	}
	
}

Element XSLTDocument::FindByAttribute(String attribute, String value)
{
	//TODO (rechercher l'element XSL dont l'attribut attribute a pour valeur value)
}