#include "test_for_maxintforsqrt.h"

void Test_for_maxIntforSqRt::testCase1() {
    int p = 0;
    QVector<char> vector = {1};
    int x = 0;
    int sgrupInt = 0;
    int lenSgrupInt = 1;

    QVERIFY2(maxIntforSqRt(p, vector, x, sgrupInt, lenSgrupInt) == 1, "не так");
    QVERIFY2(x == 1, "не так");
    QVERIFY2(sgrupInt == 1, "не так");
}
