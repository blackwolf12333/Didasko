/********************************************************************************
** Form generated from reading UI file 'EncyclopediaDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCYCLOPEDIADIALOG_H
#define UI_ENCYCLOPEDIADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_EncyclopediaDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EncyclopediaDialog)
    {
        if (EncyclopediaDialog->objectName().isEmpty())
            EncyclopediaDialog->setObjectName(QStringLiteral("EncyclopediaDialog"));
        EncyclopediaDialog->resize(584, 334);
        horizontalLayout = new QHBoxLayout(EncyclopediaDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textEdit = new QTextEdit(EncyclopediaDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        horizontalLayout->addWidget(textEdit);

        buttonBox = new QDialogButtonBox(EncyclopediaDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(EncyclopediaDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EncyclopediaDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EncyclopediaDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EncyclopediaDialog);
    } // setupUi

    void retranslateUi(QDialog *EncyclopediaDialog)
    {
        EncyclopediaDialog->setWindowTitle(QApplication::translate("EncyclopediaDialog", "EncyclopediaDialog", 0));
    } // retranslateUi

};

namespace Ui {
    class EncyclopediaDialog: public Ui_EncyclopediaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCYCLOPEDIADIALOG_H
