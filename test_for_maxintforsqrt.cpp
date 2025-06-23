#include "test_for_maxintforsqrt.h"

//#1 Минимальное число
void Test_for_maxIntforSqRt::minimumNumber() {
    QByteArray p = "0";
    QByteArray vector = "1";
    int x = 0;
    int lenSgrupInt = 1;

    QByteArray exp_vector = "1";

    QVERIFY2(maxIntforSqRt(p, vector, x, lenSgrupInt) == exp_vector, "Функция вернула неверный результат y");
    QVERIFY2(x == 1, "Неверное значение x");
}

//#2 Однозначное число, с целым исходом
void Test_for_maxIntforSqRt::singleDigitNumberOutcomeInteger() {
    QByteArray p = "0";
    QByteArray vector = "9";
    int x = 0;
    int lenSgrupInt = 1;

    QByteArray exp_vector = "9";

    QVERIFY2(maxIntforSqRt(p, vector, x, lenSgrupInt) == exp_vector, "Функция вернула неверный результат y");
    QVERIFY2(x == 3, "Неверное значение x");
}

//#3 Двузначное число, с меньшим исходом
void Test_for_maxIntforSqRt::twoDigitNumberOutcomeSmaller() {
    QByteArray p = "0";
    QByteArray vector = "24";
    int x = 0;
    int lenSgrupInt = 2;

    QByteArray exp_vector = "16";

    QVERIFY2(maxIntforSqRt(p, vector, x, lenSgrupInt) == exp_vector, "Функция вернула неверный результат y");
    QVERIFY2(x == 4, "Неверное значение x");
}

//#4 Двузначное число, с целым исходом
void Test_for_maxIntforSqRt::twoDigitNumberOutcomeInteger() {
    QByteArray p = "0";
    QByteArray vector = "81";
    int x = 0;
    int lenSgrupInt = 2;

    QByteArray exp_vector = "81";

    QVERIFY2(maxIntforSqRt(p, vector, x, lenSgrupInt) == exp_vector, "Функция вернула неверный результат y");
    QVERIFY2(x == 9, "Неверное значение x");
}

//#5 Двузначное число, с меньшим исходом и частью найденного корня
void Test_for_maxIntforSqRt::twoDigitNumberOutcomeSmallerWithPartialRoot() {
    QByteArray p = "2";
    QByteArray vector = "54";
    int x = 0;
    int lenSgrupInt = 2;

    QByteArray exp_vector = "41";

    QVERIFY2(maxIntforSqRt(p, vector, x, lenSgrupInt) == exp_vector, "Функция вернула неверный результат y");
    QVERIFY2(x == 1, "Неверное значение x");
}

//#6 Трехзначное число, с целым исходом и частью найденного корня
void Test_for_maxIntforSqRt::threeDigitNumberOutcomeIntegerWithPartialRoot() {
    QByteArray p = "5";
    QByteArray vector = "525";
    int x = 0;
    int lenSgrupInt = 3;

    QByteArray exp_vector = "525";

    QVERIFY2(maxIntforSqRt(p, vector, x, lenSgrupInt) == exp_vector, "Функция вернула неверный результат y");
    QVERIFY2(x == 5, "Неверное значение x");
}
