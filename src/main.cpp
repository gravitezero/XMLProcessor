#include <QtCore/QCoreApplication>
#include <iostream>
#include "Element.hpp"
#include "ElementComplexe.h"
#include "ElementTextuel.h"
#include "VisitorInterface.hpp"
#include "VisitorDisplay.h"
#include "XMLDocument.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Element Complexe 1 : document
    ElementName nom1;
    nom1.first = "";
    nom1.second = "Document";
    ElementComplexe* document = new ElementComplexe(nom1);
    document->addAttribute(make_pair("color","red"));
    document->addAttribute(make_pair("title","book"));

    //Element Complexe 2 : title
    ElementName nom2;
    nom2.first = "";
    nom2.second = "Title";
    ElementComplexe* title = new ElementComplexe(nom2);

    //Ajouter title a document
    document->addElement(title);

    //Element textuel : texte
    ElementTextuel* texte = new ElementTextuel("Exemple XMLDocumentDocument");

    title->addElement(texte);

    XMLDocument xml;
    xml.addElement(document);
    //xml.addElement(title);

    xml.accept(new VisitorDisplay());
    //document->accept(new VisitorDisplay());

    std::cout<<"XXXXXXXXXXXXXXXXXXX"<<std::endl;
    return a.exec();

}
