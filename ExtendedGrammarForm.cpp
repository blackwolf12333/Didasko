/*
 * File:   ExtendedGrammarForm.cpp
 * Author: peter
 *
 * Created on March 29, 2014, 5:54 PM
 */

#include <qt/QtWidgets/qmessagebox.h>
#include <qt/QtCore/qfile.h>
#include <qt/QtCore/qtextstream.h>

#include "ExtendedGrammarForm.h"

ExtendedGrammarForm::ExtendedGrammarForm(QString gram) {
    this->widget.setupUi(this);
    this->setWindowTitle(QString("Extra grammatica informatie"));
    this->widget.textEdit->setText(this->loadExtendedGrammar(gram));
}

ExtendedGrammarForm::~ExtendedGrammarForm() {
}

QString ExtendedGrammarForm::loadExtendedGrammar(QString gram) {
    QFile file(QString("Grammatica/") + gram + QString(".txt")); // TODO: make this find the installation directory
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(0, "Error", file.errorString(), file.fileName());
    }
    
    QTextStream in(&file);
    QString builder;
    while(!in.atEnd()) {
        builder.append(in.readLine() + "\n");
    }
    file.close();
    return builder;
}