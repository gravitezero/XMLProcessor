#include "VisitorDisplay.h"
#include "Element.hpp"
#include "ElementTextuel.h"
#include "ElementComplexe.h"
#include "DeclarationAttribut.h"
#include "DeclarationElement.h"
#include <list>
#include <iostream>



VisitorDisplay::VisitorDisplay()
{
    //TODO
}

VisitorDisplay::~VisitorDisplay()
{
    //todo
}

/*
 Cette méthode affiche un élément simple (textuel)
 */
void VisitorDisplay::visit(ElementTextuel* elementTextuel)
{
    cout<<elementTextuel->getValue();
}


/*
 Cette méthode affiche un élément complexe
 en mettant la balise ouvrante de l'élément suivi des attributs eventuels
 suivis de tous les éléments fils appartenenant à l'élément et enfin une balise fermante.
 Cette méthode ne prend pas en compte l'indentation
 */

void VisitorDisplay::visit(ElementComplexe* elementComplexe)
{
    cout<<"<";
    string ns(elementComplexe->getElementName()->first);
    string name(elementComplexe->getElementName()->second);
    if (ns.compare("") != 0)
    {
           ns+=":";
           ns+=name;
           name = ns;
    }


    cout<<name;
    //Récupérer la liste des attributs
    AttList *attList = elementComplexe->getAttList();

    //Parcours de la liste et affichage des attributs
    for(AttList::iterator it = attList->begin(); it != attList->end(); ++it)
    {

        cout<<" "<< (*it)->first<<" = \""<<  (*it)->second<<"\"";
    }
 

    //récupérer les fils
    //Appeler les petits
	if (elementComplexe->getElements() != NULL)
	{
	   cout<<">"<<endl;
	 
	   list<Element*> *elementList(elementComplexe->getElements());
	    for(list<Element*> ::iterator it = elementList->begin(); it != elementList->end(); ++it)
	    {
    		(*it)->accept(this);
        }

	    //Fermer la balise de l'élément

	    cout<<"</"<<name<<">"<<endl;

	} else
        cout<<"/>"<<endl;
    


}

std::string VisitorDisplay::build(ElementTextuel* elementTextuel)
{

}

std::string VisitorDisplay::build(ElementComplexe* elementComplexe)
{

}

std::string VisitorDisplay::build(DeclarationElement* declarationElement)
{

}

std::string VisitorDisplay::build(DeclarationAttribut* declarationAttribut)
{

}

std::string VisitorDisplay::build(ContenuSimple*)
{

}

std::string VisitorDisplay::build(ContenuChoix*)
{

}

std::string VisitorDisplay::build(ContenuSequence*)
{

}


