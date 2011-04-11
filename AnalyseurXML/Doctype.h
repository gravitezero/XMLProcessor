#ifndef DOCTYPE_H
#define DOCTYPE_H

#include "Declaration.h"
#include <string>

<<<<<<< HEAD
using namespace std;
=======
>>>>>>> f81499f2fd8ed04d4495c6b1f3449775e2872612

class Doctype : public Declaration
{
public : 
	Doctype();
	Doctype(string n, string s, string v);


	virtual ~Doctype();
};

#endif
