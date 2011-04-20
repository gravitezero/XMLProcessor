#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include "commun.h"


class VisitorInterface;

class Element{

    public:
   // Element();
   // virtual ~Element();
    virtual void accept(VisitorInterface*) = 0;
    virtual string build(VisitorInterface*) = 0;





};


#endif // ELEMENT_HPP
