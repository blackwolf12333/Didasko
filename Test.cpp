/*
 * File:   Test.cpp
 * Author: peter
 *
 * Created on March 26, 2014, 10:05 PM
 */

#include "Test.h"

Test::Test() {
    widget.setupUi(this);
}

Test::~Test() {
}

void Test::setLabel(QString text) {
    this->widget.testLabel->setText(text);
}