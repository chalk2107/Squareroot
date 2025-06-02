#include "test_for_maxintforsqrt.h"

void Test_for_maxIntforSqRt::minimumNumber() {
    int p = 0;
    QVector<char> vector = {'1'};
    int x = 0;
    int sgrupInt = 0;
    int lenSgrupInt = 1;

    QVERIFY2(maxIntforSqRt(p, vector, x, sgrupInt, lenSgrupInt) == 1, "Функция вернула неверный результат y");
    QVERIFY2(x == 1, "Неверное значение x");
    QVERIFY2(sgrupInt == 1, "Неверное значение sgrupInt");
}

void Test_for_maxIntforSqRt::singleDigitNumberOutcomeInteger() {
    int p = 0;
    QVector<char> vector = {'9'};
    int x = 0;
    int sgrupInt = 0;
    int lenSgrupInt = 1;

    QVERIFY2(maxIntforSqRt(p, vector, x, sgrupInt, lenSgrupInt) == 9, "Функция вернула неверный результат y");
    QVERIFY2(x == 3, "Неверное значение x");
    QVERIFY2(sgrupInt == 9, "Неверное значение sgrupInt");
}

void Test_for_maxIntforSqRt::twoDigitNumberOutcomeSmaller() {
    int p = 0;
    QVector<char> vector = {'2', '4'};
    int x = 0;
    int sgrupInt = 0;
    int lenSgrupInt = 2;

    QVERIFY2(maxIntforSqRt(p, vector, x, sgrupInt, lenSgrupInt) == 1, "Функция вернула неверный результат y");
    QVERIFY2(x == 4, "Неверное значение x");
    QVERIFY2(sgrupInt == 24, "Неверное значение sgrupInt");
}

void Test_for_maxIntforSqRt::twoDigitNumberOutcomeInteger() {
    int p = 0;
    QVector<char> vector = {'8', '1'};
    int x = 0;
    int sgrupInt = 0;
    int lenSgrupInt = 2;

    QVERIFY2(maxIntforSqRt(p, vector, x, sgrupInt, lenSgrupInt) == 81, "Функция вернула неверный результат y");
    QVERIFY2(x == 9, "Неверное значение x");
    QVERIFY2(sgrupInt == 81, "Неверное значение sgrupInt");
}

void Test_for_maxIntforSqRt::twoDigitNumberOutcomeSmallerWithPartialRoot() {
    int p = 2;
    QVector<char> vector = {'5', '4'};
    int x = 0;
    int sgrupInt = 0;
    int lenSgrupInt = 2;

    QVERIFY2(maxIntforSqRt(p, vector, x, sgrupInt, lenSgrupInt) == 41, "Функция вернула неверный результат y");
    QVERIFY2(x == 1, "Неверное значение x");
    QVERIFY2(sgrupInt == 54, "Неверное значение sgrupInt");
}

void Test_for_maxIntforSqRt::threeDigitNumberOutcomeIntegerWithPartialRoot() {
    int p = 5;
    QVector<char> vector = {'5', '2', '5'};
    int x = 0;
    int sgrupInt = 0;
    int lenSgrupInt = 3;

    QVERIFY2(maxIntforSqRt(p, vector, x, sgrupInt, lenSgrupInt) == 525, "Функция вернула неверный результат y");
    QVERIFY2(x == 5, "Неверное значение x");
    QVERIFY2(sgrupInt == 525, "Неверное значение sgrupInt");
}
