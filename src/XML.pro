#-------------------------------------------------
#
# Project created by QtCreator 2011-04-06T14:36:14
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = XML
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Contenu.cpp \
    ContenuNonTextuel.cpp \
    DeclarationAttribut.cpp \
    DeclarationElement.cpp \
    DTD.cpp \
    ElementComplexe.cpp \
    ElementTextuel.cpp \
    PCDATA.cpp \
    XMLDocument.cpp \
    VisitorDisplay.cpp \
    Doctype.cpp \
    visitorbuild.cpp \
    Declaration.cpp \
    contenuchoix.cpp \
    contenusequence.cpp \
    contenusimple.cpp \
    lex.xml.cpp \
    xml.tab.cpp \
    lex.dtd.cpp \
    dtd.tab.cpp

HEADERS += \
    commun.h \
    Contenu.h \
    ContenuNonTextuel.h \
    DeclarationAttribut.h \
    DeclarationElement.h \
    DTD.h \
    ElementComplexe.h \
    ElementTextuel.h \
    PCDATA.h \
    XMLDocument.h \
    VisitorDisplay.h \
    VisitorInterface.hpp \
    Element.hpp \
    Doctype.h \
    visitorbuild.h \
    Declaration.h \
    contenuchoix.h \
    contenusequence.h \
    contenusimple.h \
    dtd.tab.h \
    xml.tab.h
