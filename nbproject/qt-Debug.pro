# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/CLang-Linux-x86
TARGET = Didasko
VERSION = 0.1.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += EncyclopediaDialog.cpp ExtendedGrammarForm.cpp Main.cpp Test.cpp Text.cpp TextParser.cpp Word.cpp main.cpp
HEADERS += EncyclopediaDialog.h ExtendedGrammarForm.h Main.h Test.h Text.h TextParser.h Word.h
FORMS += EncyclopediaDialog.ui ExtendedGrammarForm.ui Main.ui Test.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/CLang-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = clang
QMAKE_CXX = clang++
DEFINES += 
INCLUDEPATH += . 
LIBS += -lcppunit -ldl  
