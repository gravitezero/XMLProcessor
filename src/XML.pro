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
    VisitorDisplay.cpp

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
    Element.hpp
