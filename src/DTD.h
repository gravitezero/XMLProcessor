#ifndef DTD_H
#define DTD_H


// include Système
#include<list>
#include<set>

// include perso
#include"DeclarationElement.h"
#include"DeclarationAttribut.h"

#include"contenuchoix.h"
#include"contenusequence.h"
#include"contenusimple.h"

using namespace std;

typedef list<DeclarationElement*> Elements;
typedef list<DeclarationAttribut*> Attributs;
class VisitorInterface;

class DTD
{
        public:
        DTD();
        DTD(Elements *declarationElements, Attributs *declarationAttributs);
        virtual ~DTD();

        void addDeclarationElement(DeclarationElement*);
        void addDeclarationAttributs(DeclarationAttribut*);
        std::string accept(VisitorInterface * visitor);
        DeclarationElement *getRoot();
        int getNumCorrespondingSeq(ContenuSequence *seq, set<DeclarationElement *> names);
        int getNumCorrespondingChoice(ContenuChoix *choix, set<DeclarationElement *> names);
        DeclarationElement* getElementByName(string name);


        protected:
        Elements *declarationElements;
        Attributs *declarationAttributs;
};

#endif
