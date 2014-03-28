/* 
 * File:   TextParser.cpp
 * Author: peter
 * 
 * Created on March 26, 2014, 9:18 PM
 */

#include "TextParser.h"
#include <QMessageBox>

TextParser::TextParser() {
}

TextParser::~TextParser() {
}

Text parseText(QString string, Text text) {
    QStringList lines = string.split("\n");
    Word word;
    for(QString line : lines) {
        if(line.length() == 0) { // ignore blank lines
            continue;
        }
        if(line.startsWith("<")) { // lines with words start with this.
            QStringList split = line.split("#");
            for(int i = 0; i < split.length(); i++) {
                QString part = split[i];
                switch(i) {
                    case 0: // first part, contains some magic and the word
                        part = part.remove(0, part.indexOf('>') + 1); // take of the stuff between <>
                                                                      // TODO: find out what it is
                        word.setWord(part.trimmed());
                        break;
                    case 1: // second part, contains the "betekenis"
                        word.setMeaning(part.trimmed());
                        break;
                    case 2: // third part, contains the grammar
                        word.setGrammar(part.trimmed());
                        break;
                    case 3: // fourth part, contains the "woordenboek betekenis"
                        word.setDictionary(part.trimmed());
                        break;
                }
            }
        }
        if(word.getWord().length() != 0)
            text.addWord(word);
    }
    return text;
}

Text finishBuildingText(Text text) {
    QString builder;
    for(Word woord : text.getWords()) {
        builder.append(woord.getWord() + " ");
    }
    text.setText(builder);
    return text;
}

Text TextParser::parseFile(QFile *file) {
    if(!file->open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file->errorString());
    }
    QTextStream in(file);
    Text text;
    QString line;
    bool firstLine = true;
    QString builder;
    while(!in.atEnd()) {
        line = in.readLine();
        if(firstLine) {
            text.setTitle(line);
            firstLine = false;
        }
        builder.append(line + "\n");
    }
    file->close();
    text = parseText(builder, text);
    text = finishBuildingText(text);

    return text;
}