#include "test_for_squareroot.h"

void Test_for_squareRoot::testCase1() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '1' };

    QVector<char> exp_vector= { '1' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "не так");
}
