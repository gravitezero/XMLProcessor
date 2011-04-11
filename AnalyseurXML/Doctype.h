#ifndef DOCTYPE_H
#define DOCTYPE_H

#include "Declaration.h"
#include <string>


class Doctype
{
public : 
	Doctype();
	Doctype(std::string n, std::string s, std::string v);


	virtual ~Doctype();
};

#endif
