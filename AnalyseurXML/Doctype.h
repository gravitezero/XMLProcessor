#ifndef DOCTYPE_H
#define DOCTYPE_H

#include "Declaration.h"
#include <string.h>

using namespace std;

class Doctype
{
public : 
	Doctype();
	Doctype(string n, string s, string v);


	virtual ~Doctype();
};

#endif
