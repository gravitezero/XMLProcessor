#ifndef CONTENU_H
#define CONTENU_H

#include <string>

class VisitorInterface;

class Contenu
{
	public:
        //Contenu();
        //virtual ~Contenu();
        void setCardinality(std::string card);
        std::string getCardinality();
        virtual std::string accept(VisitorInterface*) = 0;

protected:
        std::string cardinalite;
};


#endif
