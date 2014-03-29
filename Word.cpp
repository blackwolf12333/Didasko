/* 
 * File:   Word.cpp
 * Author: peter
 * 
 * Created on March 26, 2014, 9:19 PM
 */

#include "Word.h"

Word::Word() {
}

Word::~Word() {
}

QString Word::getWord() {
    return this->word;
}

void Word::setWord(QString word) {
    this->word = word;
}

QString Word::getMeaning() {
    return this->meaning;
}

void Word::setMeaning(QString meaning) {
    this->meaning = meaning;
}

QString Word::getGrammar() {
    return this->grammar;
}

void Word::setGrammar(QString grammar) {
    this->grammar = grammar;
}

QString Word::getDictionary() {
    return this->dictionary;
}

void Word::setDictionary(QString dict) {
    this->dictionary = dict;
}

QString Word::getExtendedGrammarEntry() {
    return this->extendedGrammarEntry;
}

void Word::setExtendedGrammarEntry(QString gram) {
    this->extendedGrammarEntry = gram;
}

QString Word::getEncyclopediaEntry() {
    return this->encyclopediaEntry;
}

void Word::setEncyclopediaEntry(QString enc) {
    this->encyclopediaEntry = enc;
}