#ifndef TEST_FOR_SQUAREROOT_H
#define TEST_FOR_SQUAREROOT_H

#include <QtTest/QtTest>
#include <QObject>
#include "positiveintegerthroughqvector.h"

class Test_for_squareRoot : public QObject
{
    Q_OBJECT

private slots:
    void rootSmallestNumber();
    void rootSingleDigitNumberOutcomeInteger();
    void rootSingleDigitNumberOutcomeNonInteger();
    void rootTwoDigitNumberOutcomeInteger();
    void rootTwoDigitNumberOutcomeNonInteger();
    void rootThreeDigitNumberOutcomeInteger();
    void rootThreeDigitNumberOutcomeNonInteger();
    void rootFourDigitNumberOutcomeInteger();
    void rootFourDigitNumberOutcomeNonInteger();
    void rootTenDigitNumberOutcomeInteger();
    void rootTenDigitNumberOutcomeNonInteger();
    void rootThirtyDigitNumberOutcomeInteger();
    void rootThirtyDigitNumberOutcomeNonInteger();
    void rootFiftyDigitNumberOutcomeInteger();
    void rootFiftyDigitNumberOutcomeNonInteger();
    void rootSeventyDigitNumberOutcomeInteger();
    void rootSeventyDigitNumberOutcomeNonInteger();
    void rootNinetyDigitNumberOutcomeInteger();
    void rootNinetyDigitNumberOutcomeNonInteger();
};

#endif // TEST_FOR_SQUAREROOT_H
