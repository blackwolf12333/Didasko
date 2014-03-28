/* 
 * File:   Text.h
 * Author: peter
 *
 * Created on March 26, 2014, 9:19 PM
 */

#ifndef TEXT_H
#define	TEXT_H

#include <QString>
#include <QList>
#include "Word.h"

class Text {
public:
    Text();
    virtual ~Text();
    
    QString getTitle();
    void setTitle(QString title);
    QString getText();
    void setText(QString text);
    QList<Word> getWords();
    void setWords(QList<Word> words);
    void addWord(Word w);
private:
    QString title;
    QString text;
    QList<Word> words;
};

#endif	/* TEXT_H */

