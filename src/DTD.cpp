#include"DTD.h"
#include "VisitorInterface.hpp"
#include <iostream>
using namespace std;


DTD::DTD()
{
    declarationElements = new list<DeclarationElement*>() ;
}


DTD::DTD(Elements *declarationElements, Attributs *declarationAttributs)
{
    //TODO
}


DTD::~DTD()
{

}

DeclarationElement* DTD::getElementByName(string name)
{
    for(Elements::iterator it=declarationElements->begin(); it != declarationElements->end(); it++){

        if((*it)->getElementName() == name){

            return *it;
        }
    }
    return 0;
}

void DTD::addDeclarationElement(DeclarationElement* e)
{

    declarationElements->push_back(e);
}

void DTD::addDeclarationAttributs(DeclarationAttribut* a)
{
    declarationAttributs->push_back(a);
}

std::string DTD::accept(VisitorInterface * visitor)
{
    std::string result = "Aucun élement";
    DeclarationElement* root = getRoot();
    if (root != NULL)
     result = root->accept(visitor);

    /*for(Attributs ::iterator it = declarationAttributs->begin(); it != declarationAttributs->end(); ++it)
    {
        (*it)->
    }
    */
return result;
}

DeclarationElement * DTD::getRoot()
{
    set<DeclarationElement *> elements;
if (declarationElements->size() == 0)
    return NULL;



    for(Elements::iterator it = declarationElements->begin(); it != declarationElements->end(); ++it)
    {
        elements.insert(*it);
    }

    while (elements.size()>1)
    {
        for(set<DeclarationElement *>::iterator itElt = elements.begin(); itElt != elements.end(); ++itElt)
        {
            int nCorresponding = 0;
            ContenuChoix *contenuChoix = dynamic_cast<ContenuChoix *>((*itElt)->getContents());
            if (contenuChoix != NULL)
                nCorresponding += getNumCorrespondingChoice(contenuChoix, elements);

            ContenuSequence *contenuSequence = dynamic_cast<ContenuSequence *>((*itElt)->getContents());
            if (contenuSequence != NULL)
                nCorresponding += getNumCorrespondingSeq(contenuSequence, elements);

            ContenuSimple *contenuSimple = dynamic_cast<ContenuSimple *>((*itElt)->getContents());

            if (contenuSimple != NULL)
            {
                set<DeclarationElement *>::iterator it = elements.begin();
                while ( it != elements.end() && (*it)->getElementName() != contenuSimple->getName())
                    it++;

                if (it != elements.end())
                    ++nCorresponding;
            }
            if (nCorresponding == 0)
            {

                elements.erase(itElt);
            }
        }
    }
    return (*elements.begin());

}

int DTD::getNumCorrespondingSeq(ContenuSequence *seq, set<DeclarationElement *> elements)
{
    int nCorresponding = 0;
    list<Contenu *> *content = seq->getContents();

    for (list<Contenu *>::iterator it = content->begin(); it != content->end(); ++it)
    {
        ContenuChoix *contenuChoix = dynamic_cast<ContenuChoix *>(*it);
        if (contenuChoix != NULL)
            nCorresponding += getNumCorrespondingChoice(contenuChoix, elements);

        ContenuSequence *contenuSequence = dynamic_cast<ContenuSequence *>(*it);
        if (contenuSequence != NULL)
            nCorresponding += getNumCorrespondingSeq(contenuSequence, elements);

        ContenuSimple *contenuSimple = dynamic_cast<ContenuSimple *>(*it);
        if (contenuSimple != NULL)
        {
            set<DeclarationElement *>::iterator itSimple = elements.begin();
            while ( itSimple != elements.end() && (*itSimple)->getElementName() != contenuSimple->getName())
                itSimple++;

            if (itSimple != elements.end())
                ++nCorresponding;
        }

    }
    return nCorresponding;

}


int DTD::getNumCorrespondingChoice(ContenuChoix *choix, set<DeclarationElement *> elements)
{
    int nCorresponding = 0;
    list<Contenu *> *content = choix->getContents();

    for (list<Contenu *>::iterator it = content->begin(); it != content->end(); ++it)
    {
        ContenuChoix *contenuChoix = dynamic_cast<ContenuChoix *>(*it);
        if (contenuChoix != NULL)
            nCorresponding += getNumCorrespondingChoice(contenuChoix, elements);

        ContenuSequence *contenuSequence = dynamic_cast<ContenuSequence *>(*it);
        if (contenuSequence != NULL)
            nCorresponding += getNumCorrespondingSeq(contenuSequence, elements);

        ContenuSimple *contenuSimple = dynamic_cast<ContenuSimple *>(*it);
        if (contenuSimple != NULL)
        {
            set<DeclarationElement *>::iterator itSimple = elements.begin();

           while (itSimple != elements.end() && (*itSimple)->getElementName() != contenuSimple->getName())
                itSimple++;
            if (itSimple != elements.end())
                ++nCorresponding;
        }

    }
    return nCorresponding;
}
