/*
 * File:   main.cpp
 * Author: peter
 *
 * Created on March 26, 2014, 9:17 PM
 */

#include <QApplication>
#include "Main.h"
#include "TextParser.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here
    Main main;
    main.show();

    return app.exec();
}
