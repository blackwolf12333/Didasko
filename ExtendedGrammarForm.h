/* 
 * File:   ExtendedGrammarForm.h
 * Author: peter
 *
 * Created on March 29, 2014, 5:54 PM
 */

#ifndef _EXTENDEDGRAMMARFORM_H
#define	_EXTENDEDGRAMMARFORM_H

#include "ui_ExtendedGrammarForm.h"

class ExtendedGrammarForm : public QDialog {
    Q_OBJECT
public:
    ExtendedGrammarForm(QString gram);
    virtual ~ExtendedGrammarForm();
private:
    Ui::ExtendedGrammarForm widget;
    QString loadExtendedGrammar(QString gram);
};

#endif	/* _EXTENDEDGRAMMARFORM_H */
