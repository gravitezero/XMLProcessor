#include <QtCore/QCoreApplication>
#include <iostream>
#include "Element.hpp"
#include "ElementComplexe.h"
#include "ElementTextuel.h"
#include "VisitorInterface.hpp"
#include "VisitorDisplay.h"
#include "visitorbuild.h"
#include "XMLDocument.h"
#include "contenusimple.h"
#include "contenusequence.h"
#include "contenuchoix.h"
#include "DTD.h"
#include "commun.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);


    DTD* dtd = new DTD();

    XMLDocument *xml = new XMLDocument();
    ElementName *nom = new ElementName();
    nom->first = "";
    nom->second = "auteur";


    //ElementComplexe(ElementName *n, AttList *a, list<Element *> *e);
    list<Element*>* listElt = new list<Element*>;
    list<Element*>* listElt2 = new list<Element*>;
    AttList* attList = new AttList();
    Attribut *att = new Attribut();
    att->first = "nom";
    att->second = "Byfall";
    ElementComplexe* auteurXML = new ElementComplexe(nom, attList, listElt);
    //auteurXML->addAttribute(att);

    ElementName *nomLivre = new ElementName();
    nomLivre->first = "";
    nomLivre->second = "livre";



    ElementTextuel* text = new ElementTextuel("Chacha");


    AttList* attList2 = new AttList();
    ElementComplexe* livreXML = new ElementComplexe(nom, attList2, listElt2);
    livreXML->addElement(text);
    auteurXML->addElement(livreXML);
    xml->setElement(auteurXML);

    cout<<xml->build(new VisitorBuild());



    //DTD
    ContenuSimple *livre = new ContenuSimple("livre",dtd);
    ContenuSimple *pcdata = new ContenuSimple("#PCDATA",dtd);




    DeclarationElement* elementRacine = new DeclarationElement("auteur", livre);
    DeclarationElement* eltA = new DeclarationElement("livre", pcdata);


    dtd->addDeclarationElement(elementRacine);
    dtd->addDeclarationElement(eltA);



    std::cout<<dtd->accept(new VisitorBuild())<<std::endl;
    std::cout<<"Fin"<<std::endl;

    return 0;

}
