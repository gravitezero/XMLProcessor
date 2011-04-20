#ifndef CONTENU_H
#define CONTENU_H

#include <string>

class Contenu
{
	public:
        //Contenu();
        //virtual ~Contenu();
        virtual void setCardinality(std::string card);

protected:
        std::string cardinalite;
};


#endif
