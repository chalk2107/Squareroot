#ifndef TEST_FOR_MAXINTFORSQRT_H
#define TEST_FOR_MAXINTFORSQRT_H

#include <QtTest/QtTest>
#include <QObject>
#include "positiveintegerthroughqvector.h"


class Test_for_maxIntforSqRt : public QObject
{
    Q_OBJECT

private slots:
    void minimumNumber();
    void singleDigitNumberOutcomeInteger();
    void twoDigitNumberOutcomeSmaller();
    void twoDigitNumberOutcomeInteger();
    void twoDigitNumberOutcomeSmallerWithPartialRoot();
    void threeDigitNumberOutcomeIntegerWithPartialRoot();
};

#endif // TEST_FOR_MAXINTFORSQRT_H
