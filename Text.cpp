/* 
 * File:   Text.cpp
 * Author: peter
 * 
 * Created on March 26, 2014, 9:19 PM
 */

#include "Text.h"

Text::Text() {
}

Text::~Text() {
}

QString Text::getTitle() {
    return this->title;
}

void Text::setTitle(QString title) {
    this->title = title;
}

QString Text::getText() {
    return this->text;
}

void Text::setText(QString text) {
    this->text = text;
}

QList<Word> Text::getWords() {
    return this->words;
}

void Text::setWords(QList<Word> words) {
    this->words = words;
}

void Text::addWord(Word w) {
    this->words.append(w);
}