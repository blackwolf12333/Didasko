/*
 * File:   EncyclopediaDialog.cpp
 * Author: peter
 *
 * Created on March 29, 2014, 8:19 PM
 */

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

#include "EncyclopediaDialog.h"

EncyclopediaDialog::EncyclopediaDialog(QString enc) {
    widget.setupUi(this);
    this->setWindowTitle(QString("Encyclopedie."));
    this->widget.textEdit->setText(this->loadEncyclopedia(enc));
}

EncyclopediaDialog::~EncyclopediaDialog() {
}

QString EncyclopediaDialog::loadEncyclopedia(QString enc) {
    QFile file(QString("Encyclopedie/") + enc + QString(".txt")); // TODO: make this find the installation directory
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