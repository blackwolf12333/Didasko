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

void parseMetadata(QString part, Word* word) {
    // Everything starts with a magic value and if there is other stuff
    // it adds that after it with a + separating it.
    if(part.contains('+')) {
        QStringList split = part.split("+");
        
        // starting at 1 because we can't handle the magic value at index 0
        for(int i = 0; i < split.length(); i++) {
            if(i == 0) {
                word.setTooltip(getTooltipFrom(split.at(i)));
                QString ttip = split.at(i).remove(3, 5);
            } else if(i == 1) {
                QString str = split.at(i);
                QString result = str.remove(str.indexOf(QString(">")), str.length());
                word->setExtendedGrammarEntry(result);
            } else if(i == 2) {
                QString enc = split.at(i);
                QString result = enc.remove(enc.indexOf(QString(">")), enc.length());
                word->setEncyclopediaEntry(result);
            }
        }
    }
}

Word parseWord(QString word) {
    Word ret;
    if(word.startsWith("<")) { // lines with words start with this.
        QStringList split = word.split("#");
        for(int i = 0; i < split.length(); i++) {
            QString part = split[i];
            switch(i) {
                case 0: // first part, contains some magic and the word
                    parseMetadata(part, &ret); // parses the meta data between <>
                    part = part.remove(0, part.indexOf('>') + 1); // take of the stuff between <>
                                                                  // TODO: find out what it is
                    if(part.contains('.')) {
                        // end of sentence, put the linkedWords right here.
                        
                    }
                    ret.setWord(part.trimmed());
                    break;
                case 1: // second part, contains the meaning
                    ret.setMeaning(part.trimmed());
                    break;
                case 2: // third part, contains the grammar
                    ret.setGrammar(part.trimmed());
                    break;
                case 3: // fourth part, contains the word to look up in the dictionary
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
        if(word.getWord().endsWith(QString("."))) {
            builder.append(word.getWord() + " ");
        } else {
            builder.append(word.getWord() + " ");
        }
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
