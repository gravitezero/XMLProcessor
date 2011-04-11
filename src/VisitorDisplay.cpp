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
    string ns(elementComplexe->getElementName().first);
    string name(elementComplexe->getElementName().second);
    if (ns.compare("") != 0)
    {
           ns+=":";
           ns+=name;
           name = ns;
    }


    cout<<name;
    //Récupérer la liste des attributs
    AttList attList = elementComplexe->getAttList();

      //Parcours de la liste et affichage des attributs
    for(AttList::iterator it = attList.begin(); it != attList.end(); ++it)
    {

        cout<<" "<< it->first<<" = \""<<it->second<<"\"";
    }
    cout<<">";

    //récupérer les fils
    //Appeler les petits
    list<Element*> elementList(elementComplexe->getElements());

    for(list<Element*> ::iterator it = elementList.begin(); it != elementList.end(); ++it)
    {

        (*it)->accept(this);

    }

    //Fermer la balise de l'élément

    cout<<"</"<<name<<">";




}

void VisitorDisplay::visit(DeclarationElement* declarationElement)
{

}
void VisitorDisplay::visit(DeclarationAttribut* declarationAttribut)
{
    //TODO
}
