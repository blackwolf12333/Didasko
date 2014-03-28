/* 
 * File:   Main.h
 * Author: peter
 *
 * Created on March 27, 2014, 1:38 PM
 */

#ifndef _MAIN_H
#define	_MAIN_H

#include "ui_Main.h"
#include "Text.h"
#include "Word.h"

class Main : public QMainWindow {
    Q_OBJECT
public:
    Main();
    virtual ~Main();
signals:
    void triggered();
public slots:
    void onAboutTriggered();
    void onOpenTriggered();
    void onMeaningTriggered();
    void onDictionaryTriggered();
    void onGrammarTriggered();
    void onCursorPositionChanged();
private:
    Ui::Main widget;
    int indexInText;
    bool showDictionary;
    bool showGrammar;
    bool showMeaning;
    Text text;
    
    void connectSignals();
    void setWordInfo(Word word);
    void highlightCurrentWord();
};

#endif	/* _MAIN_H */
