#include "ElementTextuel.h"
#include "VisitorInterface.hpp"

ElementTextuel::ElementTextuel(string name)
{
        value = name;
}


ElementTextuel::~ElementTextuel()
{
	//TODO
}
	

//Retourne la valeur de l'élément textuel sous forme de chaine de caractères
string ElementTextuel::getValue()
{
    return value;
}

void ElementTextuel::accept(VisitorInterface * visitor)
{
    visitor->visit(this);
}
