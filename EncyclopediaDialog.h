/* 
 * File:   EncyclopediaDialog.h
 * Author: peter
 *
 * Created on March 29, 2014, 8:19 PM
 */

#ifndef _ENCYCLOPEDIADIALOG_H
#define	_ENCYCLOPEDIADIALOG_H

#include "ui_EncyclopediaDialog.h"

class EncyclopediaDialog : public QDialog {
    Q_OBJECT
public:
    EncyclopediaDialog(QString enc);
    virtual ~EncyclopediaDialog();
private:
    Ui::EncyclopediaDialog widget;
    QString loadEncyclopedia(QString enc);
};

#endif	/* _ENCYCLOPEDIADIALOG_H */
