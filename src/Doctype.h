#ifndef DOCTYPE_H
#define DOCTYPE_H

#include "Declaration.h"
#include <string>


class Doctype : public Declaration
{
public : 
	Doctype();
	Doctype(std::string n, std::string s, std::string v);


	virtual ~Doctype();
protected:
	std::string name1;
	std::string name2;
	std::string value;	
};

#endif
