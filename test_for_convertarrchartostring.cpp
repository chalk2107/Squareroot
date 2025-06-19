#include "test_for_convertarrchartostring.h"

//#1 Массив из 1ого символа
void Test_for_convertArrCharToString::arrayCharacter1() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '1' };

    QVERIFY2(obj.convertArrayCharToString() == "1", "Конвертация массива в строку не дала ожидаемый результат");
}

//#2 Массив из 4ех символов
void Test_for_convertArrCharToString::arrayCharacter4() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = { '1', '2', '3', '4'};

    QVERIFY2(obj.convertArrayCharToString() == "1234", "Конвертация массива в строку не дала ожидаемый результат");
}

//#3 Массив из 30ти символов
void Test_for_convertArrCharToString::arrayCharacter30() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = {
    '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '1', '0', '1', '1', '1', '2', '1', '3', '1', '4',
    '1', '5', '1', '6', '1', '7', '1', '8', '1', '9', '2'
    };

    QVERIFY2(obj.convertArrayCharToString() == "123456789101112131415161718192", "Конвертация массива в строку не дала ожидаемый результат");
}
