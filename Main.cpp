/*
 * File:   Main.cpp
 * Author: Peter Maatman
 *
 * Created on March 27, 2014, 1:38 PM
 */

#include "Main.h"
#include "TextParser.h"
#include "ExtendedGrammarForm.h"
#include <QFileDialog>
#include <QEvent>
#include <QKeyEvent>
#include <Qt>
#include <qt/QtWidgets/qmessagebox.h>

Main::Main() {
    widget.setupUi(this);
    this->widget.text->setFocus();
    this->widget.centralwidget->installEventFilter(this);
    this->connectSignals();
    
    indexInText = 0;
    this->showDictionary = true;
    this->showGrammar = true;
    this->showMeaning = true;
}

Main::~Main() {
}

void Main::onAboutTriggered() {
    QMessageBox::information(this, "About", "Made by Peter Maatman\nReleased under GPLv3");
}

void Main::onOpenTriggered() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open file", "", "Text files (*.dt?)");
    if(!fileName.isEmpty()) {
        TextParser parser;
        QFile file(fileName);
        this->text = parser.parseFile(&file);
    
        this->widget.text->setText(text.getText());
        Word word = text.getWords().at(this->indexInText);
        setWordInfo(word);
    }
}

void Main::onDictionaryTriggered() {
    this->showDictionary = !this->showDictionary;
    if(this->showDictionary == true) {
        Word word = this->text.getWords().at(this->indexInText);
        this->widget.dictionary->setText(word.getDictionary());
    } else {
        this->widget.dictionary->setText("");
    }
}

void Main::onGrammarTriggered() {
    this->showGrammar = !this->showGrammar;
    if(this->showGrammar == true) {
        Word word = this->text.getWords().at(this->indexInText);
        this->widget.grammar->setText(word.getGrammar());
    } else {
        this->widget.grammar->setText("");
    }
}

void Main::onMeaningTriggered() {
    this->showMeaning = !this->showMeaning;
    if(this->showMeaning == true) {
        Word word = this->text.getWords().at(this->indexInText);
        this->widget.meaning->setText(word.getMeaning());
    } else {
        this->widget.meaning->setText("");
    }
}

void Main::onCursorPositionChanged() {
    QPoint cursorPos = this->widget.text->mapFromGlobal(this->widget.text->cursor().pos());
    QTextCursor cursor = this->widget.text->cursorForPosition(cursorPos);
    cursor.select(QTextCursor::WordUnderCursor);
    this->highlightCurrentWord();
    QString word = cursor.selectedText();
    for (int i = 0; i < this->text.getWords().length(); i++) {
        Word w = this->text.getWords().at(i);
        if (w.getWord().startsWith(word)) { // Using startsWith because some of the words end with a . which messes things up if using ==
            this->indexInText = i;
            this->setWordInfo(w);
        } else {
            continue;
        }
    }
}

void Main::highlightCurrentWord() {
    QList<QTextEdit::ExtraSelection> extraSelections;

    QTextCursor cursor = this->widget.text->textCursor();
    cursor.select(QTextCursor::WordUnderCursor);
    QTextEdit::ExtraSelection currentWord;
    QColor lineColor = QColor(Qt::yellow).lighter(160);
    currentWord.format.setBackground(lineColor);
    currentWord.cursor = cursor;
    extraSelections.append(currentWord);

    this->widget.text->setExtraSelections(extraSelections);
}

void Main::setWordInfo(Word word) {
    if(this->showGrammar)
        this->widget.grammar->setText(word.getGrammar());
    if(this->showMeaning)
        this->widget.meaning->setText(word.getMeaning());
    if(this->showDictionary)
        this->widget.dictionary->setText(word.getDictionary());
}

void Main::connectSignals() {
    this->connect(widget.actionOpen, SIGNAL(triggered()), this, SLOT(onOpenTriggered()));
    this->connect(widget.actionClose, SIGNAL(triggered()), this, SLOT(close()));
    this->connect(widget.actionAbout, SIGNAL(triggered()), this, SLOT(onAboutTriggered()));
    this->connect(widget.actionDictionary, SIGNAL(triggered()), this, SLOT(onDictionaryTriggered()));
    this->connect(widget.actionGrammar, SIGNAL(triggered()), this, SLOT(onGrammarTriggered()));
    this->connect(widget.actionMeaning, SIGNAL(triggered()), this, SLOT(onMeaningTriggered()));
    this->connect(widget.text, SIGNAL(cursorPositionChanged()), this, SLOT(onCursorPositionChanged()));
}

bool Main::eventFilter(QObject *obj, QEvent *event) {
    if(event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if(keyEvent->key() == 0x47) { // 0x47 == G
            Word word = this->text.getWords().at(this->indexInText);
            ExtendedGrammarForm extendedGrammar(word.getExtendedGrammarEntry());
            extendedGrammar.exec();
            return true;
        } else if(keyEvent->key() == 0x45) { // 0x45 == E
            Word word = this->text.getWords().at(this->indexInText);
            // TODO: add encyclopedia form here
        } else {
            return false;
        }
    } else {
        return false;
    }
}