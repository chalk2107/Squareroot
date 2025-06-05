#include "test_for_maxintforsqrt.h"

void Test_for_maxIntforSqRt::minimumNumber() {
    QVector<char> p = {'0'};
    QVector<char> vector = {'1'};
    int x = 0;
    int lenSgrupInt = 1;

    QVector<char> exp_vector = {'1'};

    QVERIFY2(maxIntforSqRt(p, vector, x, lenSgrupInt) == exp_vector, "Функция вернула неверный результат y");
    QVERIFY2(x == 1, "Неверное значение x");
}

void Test_for_maxIntforSqRt::singleDigitNumberOutcomeInteger() {
    QVector<char> p = {'0'};
    QVector<char> vector = {'9'};
    int x = 0;
    int lenSgrupInt = 1;

    QVector<char> exp_vector = {'9'};

    QVERIFY2(maxIntforSqRt(p, vector, x, lenSgrupInt) == exp_vector, "Функция вернула неверный результат y");
    QVERIFY2(x == 3, "Неверное значение x");
}

void Test_for_maxIntforSqRt::twoDigitNumberOutcomeSmaller() {
    QVector<char> p = {'0'};
    QVector<char> vector = {'2', '4'};
    int x = 0;
    int lenSgrupInt = 2;

    QVector<char> exp_vector = {'1', '6'};

    QVERIFY2(maxIntforSqRt(p, vector, x, lenSgrupInt) == exp_vector, "Функция вернула неверный результат y");
    QVERIFY2(x == 4, "Неверное значение x");
}

void Test_for_maxIntforSqRt::twoDigitNumberOutcomeInteger() {
    QVector<char> p = {'0'};
    QVector<char> vector = {'8', '1'};
    int x = 0;
    int lenSgrupInt = 2;

    QVector<char> exp_vector = {'8', '1'};

    QVERIFY2(maxIntforSqRt(p, vector, x, lenSgrupInt) == exp_vector, "Функция вернула неверный результат y");
    QVERIFY2(x == 9, "Неверное значение x");
}

void Test_for_maxIntforSqRt::twoDigitNumberOutcomeSmallerWithPartialRoot() {
    QVector<char> p = {'2'};
    QVector<char> vector = {'5', '4'};
    int x = 0;
    int lenSgrupInt = 2;

    QVector<char> exp_vector = {'4', '1'};

    QVERIFY2(maxIntforSqRt(p, vector, x, lenSgrupInt) == exp_vector, "Функция вернула неверный результат y");
    QVERIFY2(x == 1, "Неверное значение x");
}

void Test_for_maxIntforSqRt::threeDigitNumberOutcomeIntegerWithPartialRoot() {
    QVector<char> p = {'5'};
    QVector<char> vector = {'5', '2', '5'};
    int x = 0;
    int lenSgrupInt = 3;

    QVector<char> exp_vector = {'5', '2', '5'};

    QVERIFY2(maxIntforSqRt(p, vector, x, lenSgrupInt) == exp_vector, "Функция вернула неверный результат y");
    QVERIFY2(x == 5, "Неверное значение x");
}
