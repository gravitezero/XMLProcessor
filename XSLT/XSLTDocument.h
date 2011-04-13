#ifndef XSLT_H
#define XSLT_H

#include "../AnalyseurXML/XMLDocument.h"
#include "../AnalyseurXML/Element.hpp"

using namespace std;

class XSLTDocument : public XMLDocument
{
public :
	XSLTDocument();
	virtual ~XSLTDocument();
	Element ApplyTo(Element XMLTree);
	
};

#endif
