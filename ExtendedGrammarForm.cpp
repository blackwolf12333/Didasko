/*
 * File:   ExtendedGrammarForm.cpp
 * Author: peter
 *
 * Created on March 29, 2014, 5:54 PM
 */

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>

#include "ExtendedGrammarForm.h"

ExtendedGrammarForm::ExtendedGrammarForm(QString gram) {
    this->widget.setupUi(this);
    this->setWindowTitle(QString("Extra grammatica informatie"));
    this->widget.textEdit->setText(this->loadExtendedGrammar(gram));
}

ExtendedGrammarForm::~ExtendedGrammarForm() {
}

QDir getInstallationDirectory() {
#ifdef Q_WS_WIN
    return QDir("C:/Didasko/");
#elif Q_WS_X11
    return QDir("/usr/bin/didasko/");
#elif Q_WS_MACX
    return QDir(""); //TODO MAC
#endif
}

QString ExtendedGrammarForm::loadExtendedGrammar(QString gram) {
    QFile file(getInstallationDirectory().absolutePath() + QString("Grammatica/") + gram + QString(".txt")); // TODO: make this find the installation directory
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
