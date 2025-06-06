#include "test_for_squareroot.h"

void Test_for_squareRoot::rootSmallestNumber() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '1' };

    QVector<char> exp_vector= { '1' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootSingleDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '9' };

    QVector<char> exp_vector= { '3' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootSingleDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '8' };

    QVector<char> exp_vector= { '2' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootTwoDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '4', '9' };

    QVector<char> exp_vector= { '7' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootTwoDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '7', '6' };

    QVector<char> exp_vector= { '8' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootThreeDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '4', '4', '1' };

    QVector<char> exp_vector= { '2', '1' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootThreeDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '7', '8', '5' };

    QVector<char> exp_vector= { '2', '8' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootFourDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '5', '3', '2', '9' };

    QVector<char> exp_vector= { '7', '3' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootFourDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '9', '2', '1', '7' };

    QVector<char> exp_vector= { '9', '6' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootTenDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '9', '0', '6', '5', '7', '0', '5', '7', '9', '6' };

    QVector<char> exp_vector= { '9', '5', '2', '1', '4' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootTenDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '3', '9', '4', '9', '2', '4', '2', '6', '4', '2' };

    QVector<char> exp_vector= { '6', '2', '8', '4', '2' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootThirtyDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '3', '4', '4', '9', '9', '6', '7', '1', '6', '2',
                          '1', '0', '3', '2', '1', '0', '9', '3', '7', '3',
                          '5', '4', '8', '6', '7', '7', '5', '6', '2', '5' };

    QVector<char> exp_vector= { '5', '8', '7', '3', '6', '4', '2', '1', '0', '8',
                                '6', '9', '4', '7', '5' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootThirtyDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '7', '2', '0', '5', '0', '2', '5', '5', '7', '2',
                          '8', '5', '6', '1', '6', '1', '1', '0', '5', '9',
                          '6', '9', '6', '3', '5', '3', '2', '4', '3' };

    QVector<char> exp_vector= { '2', '6', '8', '4', '2', '1', '7', '8', '6', '9',
                                '8', '5', '6', '3', '5' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootFiftyDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '5','5','7','3','1','0','8','3','2','4',
                          '8','1','1','5','4','9','8','2','9','3',
                          '3','0','0','2','6','3','5','7','1','6',
                          '6','0','8','1','6','4','0','5','6','3',
                          '8','6','2','3','6','2','0','2','2','5' };

    QVector<char> exp_vector= { '7','4','6','5','3','2','5','3','9','4',
                                '6','5','7','3','2','1','8','5','3','9',
                                '6','4','7','3','5' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootFiftyDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '1','2','0','0','8','4','8','0','0','9',
                          '0','8','5','6','9','2','3','4','6','1',
                          '5','8','2','3','8','3','5','7','1','6',
                          '6','0','8','1','6','4','0','5','6','3',
                          '8','6','2','3','6','2','0','3','2','5' };

    QVector<char> exp_vector= { '3','4','6','5','3','2','5','3','9','4',
                                '6','5','7','3','2','1','8','5','3','9',
                                '6','4','7','3','5' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}


void Test_for_squareRoot::rootSeventyDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '3','1','8','0','3','7','9','9','4','5',
                          '3','3','4','8','9','9','8','9','2','0',
                          '2','7','2','8','4','2','1','3','2','6',
                          '2','2','6','4','2','3','6','2','1','8',
                          '6','6','3','6','8','7','8','4','3','8',
                          '4','1','7','0','8','4','1','6','7','2',
                          '4','4','4','4','2','8','8','3','2','9' };

    QVector<char> exp_vector= { '5','6','3','9','4','8','5','7','4','3',
                                '6','9','5','8','7','3','4','5','6','2',
                                '3','9','4','1','2','4','9','0','1','2',
                                '6','0','5','7','3' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootSeventyDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '7','6','7','7','9','6','2','8','7','4',
                          '5','7','9','6','2','7','5','7','6','6',
                          '8','9','8','1','0','1','7','7','4','4',
                          '9','8','7','2','0','6','1','9','4','5',
                          '5','5','9','9','8','2','6','7','2','1',
                          '4','3','1','1','8','7','8','3','8','6',
                          '5','5','4','6','9','8','8','3','2','1' };

    QVector<char> exp_vector= { '8','7','6','2','3','9','8','5','7','2',
                                '6','3','9','5','8','7','2','3','6','8',
                                '9','5','7','2','3','6','8','9','5','7',
                                '6','2','3','8','9' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootNinetyDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '1','1','9','4','8','5','3','9','1','2',
                          '3','8','7','6','7','8','9','2','0','9',
                          '1','3','6','5','5','8','7','3','8','2',
                          '4','5','2','0','4','2','2','3','9','0',
                          '7','5','3','6','1','0','3','8','2','3',
                          '4','3','7','1','3','7','9','1','5','6',
                          '1','5','8','2','7','5','8','1','1','8',
                          '6','8','0','7','6','2','1','5','1','3',
                          '0','9','3','7','6','6','7','2','0','4' };

    QVector<char> exp_vector= { '3','4','5','6','6','6','5','8','9',
                                '7','0','5','6','9','8','7','6','5',
                                '9','7','6','7','0','6','5','8','7',
                                '4','5','8','7','6','8','7','6','0',
                                '5','6','8','7','0','5','6','9','8' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}

void Test_for_squareRoot::rootNinetyDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '4','7','2','7','1','9','9','9','2','2',
                          '5','2','5','1','0','9','3','2','4','2',
                          '9','3','0','1','3','5','8','8','6','3',
                          '8','7','3','9','7','9','0','9','6','9',
                          '9','0','1','8','5','3','9','7','8','5',
                          '0','3','5','2','6','7','3','0','2','5',
                          '8','5','5','2','5','8','0','6','1','4',
                          '0','7','0','0','6','5','0','8','8','9',
                          '7','5','1','2','1','4','8','7','4','1' };

    QVector<char> exp_vector= { '6','8','7','5','4','6','3','5','6',
                                '4','3','8','9','7','5','6','3','4',
                                '8','5','6','3','9','4','8','6','8',
                                '9','3','4','6','9','8','4','6','3',
                                '6','4','3','4','2','1','3','6','7' };

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычеслен неверно");
}










