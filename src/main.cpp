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
#include <QRegExp>
#include <cstdio>

int xmlparse(void);
int dtdparse(void);

extern XMLDocument *docXML;
extern DTD *docDTD;

extern FILE * xmlin;
extern FILE * dtdin;

int main(int argc, char *argv[])
{
    /*//QCoreApplication a(argc, argv);

    QRegExp rx;

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
    auteurXML->addAttribute(att);

    ElementName *nomLivre = new ElementName();
    nomLivre->first = "";
    nomLivre->second = "livre";



    ElementTextuel* text = new ElementTextuel("Chacha");


    AttList* attList2 = new AttList();
    ElementComplexe* livreXML = new ElementComplexe(nomLivre, attList2, listElt2);
    livreXML->addElement(text);
    auteurXML->addElement(livreXML);
    xml->setElement(auteurXML);

    cout<<xml->build(new VisitorBuild());

    QString toValidate(xml->build(new VisitorBuild()).c_str());


    //DTD
    ContenuSimple *livre = new ContenuSimple("livre",dtd);
    ContenuSimple *pcdata = new ContenuSimple("#PCDATA",dtd);




    DeclarationElement* elementRacine = new DeclarationElement("auteur", livre);
    DeclarationElement* eltA = new DeclarationElement("livre", pcdata);


    dtd->addDeclarationElement(elementRacine);
    dtd->addDeclarationElement(eltA);


    rx.setPattern(QString(dtd->accept(new VisitorBuild()).c_str()));
    std::cout<<dtd->accept(new VisitorBuild())<<std::endl;
    std::cout<<rx.indexIn(QString(xml->build(new VisitorBuild()).c_str()))<<std::endl;
    //{
      //  std::cout<<"On est dans la merde !"<<std::endl;
    //}
    std::cout<<"Fin"<<std::endl;
    */


    QRegExp rx;
    int err = -1;
    int errXML, errDTD;

    FILE *fidXML, *fidDTD;

    if(argc != 3){
          std::cout << "argc != 2" << std::endl;
    }

    /* Analyse XML */
    fidXML = fopen(argv[1], "r");
    xmlin  = fidXML;

    errXML = xmlparse();
    fclose(fidXML);
    if (errXML != 0)
        std::cout << "Parse XML ended with "<< errXML << " error(s)" << std::endl;
    else
        std::cout << "Parse XML ended with sucess"<< std::endl;
        std::cout << "----------------------------------------------------"<< std::endl;
        docXML->accept(new VisitorDisplay);
        std::cout << "----------------------------------------------------"<< std::endl;

    /* Analyse DTD */
    fidDTD = fopen(argv[2], "r");
    dtdin  = fidDTD;

    errDTD = dtdparse();
    fclose(fidDTD);
    if (errDTD != 0)
        std::cout << "Parse DTD ended with "<< errDTD << " error(s)" << std::endl;
    else
        std::cout << "Parse DTD ended with sucess"<< std::endl;
        std::cout << "----------------------------------------------------"<< std::endl;
        cout << docDTD->accept(new VisitorBuild) << endl;
        std::cout << "----------------------------------------------------"<< std::endl;


    rx.setPattern(QString(docDTD->accept(new VisitorBuild()).c_str()));
    std::cout << rx.indexIn(QString(docXML->build(new VisitorBuild()).c_str())) << std::endl;
    return 0;
}
