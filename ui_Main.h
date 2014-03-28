/********************************************************************************
** Form generated from reading UI file 'Main.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main
{
public:
    QAction *actionOpen;
    QAction *actionMeaning;
    QAction *actionGrammar;
    QAction *actionDictionary;
    QAction *actionAbout;
    QAction *actionClose;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *text;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *dictionary;
    QLabel *label_2;
    QTextEdit *grammar;
    QLabel *label_3;
    QTextEdit *meaning;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Main)
    {
        if (Main->objectName().isEmpty())
            Main->setObjectName(QStringLiteral("Main"));
        Main->resize(796, 605);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Main->sizePolicy().hasHeightForWidth());
        Main->setSizePolicy(sizePolicy);
        actionOpen = new QAction(Main);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionMeaning = new QAction(Main);
        actionMeaning->setObjectName(QStringLiteral("actionMeaning"));
        actionMeaning->setCheckable(true);
        actionMeaning->setChecked(true);
        actionGrammar = new QAction(Main);
        actionGrammar->setObjectName(QStringLiteral("actionGrammar"));
        actionGrammar->setCheckable(true);
        actionGrammar->setChecked(true);
        actionDictionary = new QAction(Main);
        actionDictionary->setObjectName(QStringLiteral("actionDictionary"));
        actionDictionary->setCheckable(true);
        actionDictionary->setChecked(true);
        actionAbout = new QAction(Main);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionClose = new QAction(Main);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralwidget = new QWidget(Main);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 791, 561));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 0, 0, 0);
        text = new QTextEdit(layoutWidget);
        text->setObjectName(QStringLiteral("text"));
        text->setMinimumSize(QSize(550, 0));
        text->setReadOnly(true);

        horizontalLayout->addWidget(text);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        dictionary = new QTextEdit(layoutWidget);
        dictionary->setObjectName(QStringLiteral("dictionary"));
        dictionary->setReadOnly(true);
        dictionary->setOverwriteMode(false);

        verticalLayout->addWidget(dictionary);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        grammar = new QTextEdit(layoutWidget);
        grammar->setObjectName(QStringLiteral("grammar"));
        grammar->setReadOnly(true);

        verticalLayout->addWidget(grammar);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        meaning = new QTextEdit(layoutWidget);
        meaning->setObjectName(QStringLiteral("meaning"));
        meaning->setReadOnly(true);

        verticalLayout->addWidget(meaning);


        horizontalLayout->addLayout(verticalLayout);

        Main->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Main);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 796, 19));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Main->setMenuBar(menubar);
        statusbar = new QStatusBar(Main);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Main->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuOptions->addAction(actionMeaning);
        menuOptions->addAction(actionGrammar);
        menuOptions->addAction(actionDictionary);
        menuHelp->addAction(actionAbout);

        retranslateUi(Main);

        QMetaObject::connectSlotsByName(Main);
    } // setupUi

    void retranslateUi(QMainWindow *Main)
    {
        Main->setWindowTitle(QApplication::translate("Main", "Didasko", 0));
        actionOpen->setText(QApplication::translate("Main", "Open", 0));
        actionMeaning->setText(QApplication::translate("Main", "Meaning", 0));
        actionGrammar->setText(QApplication::translate("Main", "Grammar", 0));
        actionDictionary->setText(QApplication::translate("Main", "Dictionary", 0));
        actionAbout->setText(QApplication::translate("Main", "About", 0));
        actionClose->setText(QApplication::translate("Main", "Close", 0));
        label->setText(QApplication::translate("Main", "Dictionary", 0));
        label_2->setText(QApplication::translate("Main", "Grammar", 0));
        label_3->setText(QApplication::translate("Main", "Meaning", 0));
        menuFile->setTitle(QApplication::translate("Main", "File", 0));
        menuOptions->setTitle(QApplication::translate("Main", "Options", 0));
        menuHelp->setTitle(QApplication::translate("Main", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class Main: public Ui_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H
