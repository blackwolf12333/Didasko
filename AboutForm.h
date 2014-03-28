/* 
 * File:   AboutForm.h
 * Author: peter
 *
 * Created on March 27, 2014, 2:08 PM
 */

#ifndef _ABOUTFORM_H
#define	_ABOUTFORM_H

#include "ui_AboutForm.h"

class AboutForm : public QDialog {
    Q_OBJECT
public:
    AboutForm();
    virtual ~AboutForm();
signals:
    void accepted();
public slots:
    void accept();
private:
    Ui::AboutForm widget;
};

#endif	/* _ABOUTFORM_H */
