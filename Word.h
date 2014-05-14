/* 
 * File:   Word.h
 * Author: peter
 *
 * Created on March 26, 2014, 9:19 PM
 */

#ifndef WORD_H
#define	WORD_H

#include <QString>

class Word {
public:
    Word();
    virtual ~Word();
    
    QString getWord();
    void setWord(QString word);
    QString getMeaning();
    void setMeaning(QString meaning);
    QString getGrammar();
    void setGrammar(QString grammar);
    QString getDictionary();
    void setDictionary(QString dict);
    QString getExtendedGrammarEntry();
    void setExtendedGrammarEntry(QString gram);
    QString getEncyclopediaEntry();
    void setEncyclopediaEntry(QString enc);
    QString getTooltip();
    void setTooltip(QString tooltip);
    int[] getLinkedWords();
    void setLinkedWords(int[] linkedWords);
private:
    QString word;
    QString meaning;
    QString grammar;
    QString dictionary;
    QString extendedGrammarEntry;
    QString encyclopediaEntry;
    int[] linkedWords;
    QString tooltip;
};

#endif	/* WORD_H */

