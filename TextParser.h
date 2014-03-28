/* 
 * File:   TextParser.h
 * Author: peter
 *
 * Created on March 26, 2014, 9:18 PM
 */

#ifndef TEXTPARSER_H
#define	TEXTPARSER_H

#include <QFile>
#include <QTextStream>
#include "Text.h"
#include "Word.h"

class TextParser {
public:
    TextParser();
    virtual ~TextParser();
    
    Text parseFile(QFile *file);
private:

};

#endif	/* TEXTPARSER_H */

