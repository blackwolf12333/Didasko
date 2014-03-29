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

Word parseWord(QString word) {
    Word ret;
    if(word.startsWith("<")) { // lines with words start with this.
        QStringList split = word.split("#");
        for(int i = 0; i < split.length(); i++) {
            QString part = split[i];
            switch(i) {
                case 0: // first part, contains some magic and the word
                    part = part.remove(0, part.indexOf('>') + 1); // take of the stuff between <>
                                                                  // TODO: find out what it is
                    ret.setWord(part.trimmed());
                    break;
                case 1: // second part, contains the "betekenis"
                    ret.setMeaning(part.trimmed());
                    break;
                case 2: // third part, contains the grammar
                    ret.setGrammar(part.trimmed());
                    break;
                case 3: // fourth part, contains the "woordenboek betekenis"
                    ret.setDictionary(part.trimmed());
                    break;
            }
        }
    }
    return ret;
}

Text parseText(QString string, Text text) {
    QStringList lines = string.split("\n");
    Word word;
    for(int j = 0; j < lines.length(); j++) {
        QString line = lines.at(j);
        if(line.length() == 0) { // ignore blank lines
            continue;
        }
        word = parseWord(line);
        if(word.getWord().length() != 0)
            text.addWord(word);
    }
    return text;
}

Text finishBuildingText(Text text) {
    QString builder;
    for(int i = 0; i < text.getWords().length(); i++) {
        Word word = text.getWords().at(i);
        builder.append(word.getWord() + " ");
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