#include "test_for_convertarrchartostring.h"

//#1 Массив из 1ого символа
void Test_for_convertArrCharToString::arrayCharacter1() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "1";

    QVERIFY2(obj.convertArrayCharToString() == "1", "Конвертация массива в строку не дала ожидаемый результат");
}

//#2 Массив из 4ех символов
void Test_for_convertArrCharToString::arrayCharacter4() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "1234";

    QVERIFY2(obj.convertArrayCharToString() == "1234", "Конвертация массива в строку не дала ожидаемый результат");
}

//#3 Массив из 30ти символов
void Test_for_convertArrCharToString::arrayCharacter30() {
    PositiveIntegerThroughQVector obj;
    obj.vectorInteger = "123456789101112131415161718192";

    QVERIFY2(obj.convertArrayCharToString() == "123456789101112131415161718192", "Конвертация массива в строку не дала ожидаемый результат");
}
