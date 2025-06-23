#include "test_for_squareroot.h"

//№1 Корень самого маленького числа
void Test_for_squareRoot::rootSmallestNumber() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "1";

    QByteArray exp_vector = "1";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№2 Корень однозначного числа, с целым исходом
void Test_for_squareRoot::rootSingleDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "9";

    QByteArray exp_vector = "3";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№3 Корень однозначного числа, с не целым исходом
void Test_for_squareRoot::rootSingleDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "8";

    QByteArray exp_vector = "2";;

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№4 Корень двухзначного числа, с целым исходом
void Test_for_squareRoot::rootTwoDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "49";

    QByteArray exp_vector = "7";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№5 Корень двухзначного числа, с не целым исходом
void Test_for_squareRoot::rootTwoDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "76";

    QByteArray exp_vector = "8";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№6 Корень трехзначного числа, с целым исходом
void Test_for_squareRoot::rootThreeDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "441";

    QByteArray exp_vector = "21";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№7 Корень трехзначного числа, с не целым исходом
void Test_for_squareRoot::rootThreeDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "785";

    QByteArray exp_vector = "28";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№8 Корень четырехзначного числа, с целым исходом
void Test_for_squareRoot::rootFourDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "5329";

    QByteArray exp_vector = "73";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№9 Корень четырехзначного числа, с не целым исходом
void Test_for_squareRoot::rootFourDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "9217";

    QByteArray exp_vector = "96";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№10 Корень десятизначного числа, с целым исходом
void Test_for_squareRoot::rootTenDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "9065705796";

    QByteArray exp_vector = "95214";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№11 Корень десятизначного числа, с не целым исходом
void Test_for_squareRoot::rootTenDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "3949242642";

    QByteArray exp_vector = "62842";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№12 Корень тридцатизначного числа, с целым исходом
void Test_for_squareRoot::rootThirtyDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "344996716210321093735486775625";

    QByteArray exp_vector = "587364210869475";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№13 Корень тридцатизначного числа, с не целым исходом
void Test_for_squareRoot::rootThirtyDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "72050255728561611059696353243";

    QByteArray exp_vector = "268421786985635";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№14 Корень пятидесятизначного числа, с целым исходом
void Test_for_squareRoot::rootFiftyDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "55731083248115498293300263571660816405638623620225";

    QByteArray exp_vector = "7465325394657321853964735";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№15 Корень пятидесятизначного числа, с не целым исходом
void Test_for_squareRoot::rootFiftyDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "12008480090856923461582383571660816405638623620325";

    QByteArray exp_vector = "3465325394657321853964735";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№16 Корень семидесятизначного числа, с целым исходом
void Test_for_squareRoot::rootSeventyDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "3180379945334899892027284213262264236218663687843841708416724444288329";

    QByteArray exp_vector = "56394857436958734562394124901260573";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№17 Корень семидесятизначного числа, с не целым исходом
void Test_for_squareRoot::rootSeventyDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "7677962874579627576689810177449872061945559982672143118783865546988321";

    QByteArray exp_vector = "87623985726395872368957236895762389";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№18 Корень девяностозначного числа, с целым исходом
void Test_for_squareRoot::rootNinetyDigitNumberOutcomeInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "119485391238767892091365587382452042239075361038234371379156158275811868076215130937667204";

    QByteArray exp_vector = "345666589705698765976706587458768760568705698";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}

//№19 Корень девяностозначного числа, с не целым исходом
void Test_for_squareRoot::rootNinetyDigitNumberOutcomeNonInteger() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "472719992252510932429301358863873979096990185397850352673025855258061407006508897512148741";

    QByteArray exp_vector = "68754635643897563485639486893469846364342136";

    QVERIFY2(obj.squareRoot().vectorInteger == exp_vector, "Квадратный корень вычислен неверно");
}
