/********************************************************************************
** Form generated from reading UI file 'ExtendedGrammarForm.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTENDEDGRAMMARFORM_H
#define UI_EXTENDEDGRAMMARFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExtendedGrammarForm
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ExtendedGrammarForm)
    {
        if (ExtendedGrammarForm->objectName().isEmpty())
            ExtendedGrammarForm->setObjectName(QStringLiteral("ExtendedGrammarForm"));
        ExtendedGrammarForm->resize(568, 298);
        verticalLayout = new QVBoxLayout(ExtendedGrammarForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(ExtendedGrammarForm);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        buttonBox = new QDialogButtonBox(ExtendedGrammarForm);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ExtendedGrammarForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), ExtendedGrammarForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ExtendedGrammarForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExtendedGrammarForm);
    } // setupUi

    void retranslateUi(QDialog *ExtendedGrammarForm)
    {
        ExtendedGrammarForm->setWindowTitle(QApplication::translate("ExtendedGrammarForm", "ExtendedGrammarForm", 0));
    } // retranslateUi

};

namespace Ui {
    class ExtendedGrammarForm: public Ui_ExtendedGrammarForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTENDEDGRAMMARFORM_H
