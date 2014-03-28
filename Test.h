/* 
 * File:   Test.h
 * Author: peter
 *
 * Created on March 26, 2014, 10:05 PM
 */

#ifndef _TEST_H
#define	_TEST_H

#include "ui_Test.h"

class Test : public QDialog {
    Q_OBJECT
public:
    Test();
    virtual ~Test();
    void setLabel(QString text);
private:
    Ui::Test widget;
};

#endif	/* _TEST_H */
