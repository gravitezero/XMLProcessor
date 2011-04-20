#include "visitorbuild.h"
#include "DeclarationAttribut.h"
#include "DeclarationElement.h"
#include "contenusimple.h"
#include "contenusequence.h"
#include "Contenu.h"
#include "ElementTextuel.h"
#include "ElementComplexe.h"
#include "contenuchoix.h"
#include <iostream>

VisitorBuild::VisitorBuild()
{

}

std::string VisitorBuild::build(ElementTextuel* elementTextuel)
{
    return "DATA";
}

 std::string VisitorBuild::build(ElementComplexe* elementComplexe)
{
     std::string result;
     result+="<";

     string name(elementComplexe->getElementName()->second);



     result+=name;
     //Récupérer la liste des attributs
     AttList *attList = elementComplexe->getAttList();

     //Parcours de la liste et affichage des attributs
     for(AttList::iterator it = attList->begin(); it != attList->end(); ++it)
     {

         result+=" " + (*it)->first+" = \""+  (*it)->second+"\"";
     }
     result+=">";

     //récupérer les fils

     list<Element*> *elementList(elementComplexe->getElements());


     for(list<Element*> ::iterator it = elementList->begin(); it != elementList->end(); ++it)
     {

         result+=(*it)->build(this);

     }

     //Fermer la balise de l'élément

     result+="</"+name+">";

    return result;
}

void VisitorBuild::visit(ElementTextuel* elementTextuel)
{

}

void VisitorBuild::visit(ElementComplexe* elementComplex)
{

}


std::string VisitorBuild::build(ContenuChoix* c)
{
    std::string result;
    string card = c->getCardinality();
    if (card != "")
    {
    result += "(";
    }

    //boucle fils
    list<Contenu*> * contenus = new list<Contenu*>;
    contenus = c->getContents();
    int n = contenus->size();
    list<Contenu*>::iterator it = contenus->begin();
    for ( int i = 0; i< n-1 ; ++i)
    {

        result+= (*it)->accept(this);
        result+="|";
        ++it;

    }

    result+= (*it)->accept(this);
    if (card != "")
    {
    result += ")";
    result+= c->getCardinality();
    }




    return result;
}

std::string VisitorBuild::build(ContenuSequence* c)
{

    std::string result;
    string card = c->getCardinality();
    if (card != "")
    {
    result += "(";
    }
    //boucle fils
    list<Contenu*> * contenus = new list<Contenu*>;
    contenus = c->getContents();

    for (list<Contenu*>::iterator it = contenus->begin(); it != contenus->end(); ++it)
    {

        result+= (*it)->accept(this);


    }
    if (card != "")
    {
    result += ")";
    result+= c->getCardinality();
    }

    return result;
}

std::string VisitorBuild::build(ContenuSimple* contenuSimple)
{
    string name = contenuSimple->getName();


    if (name.compare("#PCDATA") == 0)     
        return "DATA";
    //Sinon faut chercher dans data !!!
    DeclarationElement* elt = contenuSimple->getElementByName(name);

    return elt->accept(this);
}

std::string VisitorBuild::build(DeclarationElement* declarationElement)
{
    std::string result;
    //Algo

    //Debut de regex
    result+= "<";
    result+=declarationElement->getElementName();
    //result+="(\\s*[^\\s=]+)\\s*=\\s*(\\'[^<\\']*\\'|\"[^<\"]*\")*"; //Internet
    result+="((\\s)*[a-zA-Z]+(\\s)*=(\\s)*\"[^\"]*\")*";

    //result+= "((\\s)*[a-zA-Z]+(\\s)*=\\\"[a-zA-Z]+\\\")*";
    //[:space:]*\\\"[^\\\"]+\\\"[:space:]*
    result+=">";
    result+= declarationElement->getContents()->accept(this);

    //Gestion des attributs




    result+= "</";
    result+=declarationElement->getElementName();
    result+=">";


    return result;
}


std::string VisitorBuild::build(DeclarationAttribut* declarationAttribut)
{
    //TODO
    return 0;
}




//attribut: cdata: attNom=\"[^\"]*\"(\\s)*

//element:
//
//pcdata: [^<]*
//(\\s)* : espace

