#ifndef DOCTYPE_H
#define DOCTYPE_H

#include "Declaration.h"
<<<<<<< HEAD
#include <string.h>

using namespace std;
=======
#include <string>

>>>>>>> fa46d99cdcf678995f7749c4fdd2468be7083a5a

class Doctype
{
public : 
	Doctype();
	Doctype(std::string n, std::string s, std::string v);


	virtual ~Doctype();
};

#endif
