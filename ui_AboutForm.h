/********************************************************************************
** Form generated from reading UI file 'AboutForm.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTFORM_H
#define UI_ABOUTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AboutForm
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *licence;

    void setupUi(QDialog *AboutForm)
    {
        if (AboutForm->objectName().isEmpty())
            AboutForm->setObjectName(QStringLiteral("AboutForm"));
        AboutForm->resize(583, 305);
        buttonBox = new QDialogButtonBox(AboutForm);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(490, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        licence = new QTextEdit(AboutForm);
        licence->setObjectName(QStringLiteral("licence"));
        licence->setGeometry(QRect(10, 10, 471, 281));
        licence->setReadOnly(true);

        retranslateUi(AboutForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), AboutForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AboutForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutForm);
    } // setupUi

    void retranslateUi(QDialog *AboutForm)
    {
        AboutForm->setWindowTitle(QApplication::translate("AboutForm", "AboutForm", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutForm: public Ui_AboutForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTFORM_H
