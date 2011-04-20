#ifndef VISITORBUILD_H
#define VISITORBUILD_H

#include "VisitorInterface.hpp"
#include <string>

class VisitorBuild : public VisitorInterface
{
public:
    VisitorBuild();
    void visit(ElementTextuel* elementTextuel);
    void visit(ElementComplexe* elementComplexe);
    virtual std::string build(ElementTextuel* elementTextuel) ;
    virtual std::string build(ElementComplexe* elementComplexe) ;
    std::string build(DeclarationElement* declarationElement);
    std::string build(DeclarationAttribut* declarationAttribut);
    std::string build(ContenuSimple*);
    std::string build(ContenuChoix*);
    std::string build(ContenuSequence*);
};

#endif // VISITORBUILD_H
