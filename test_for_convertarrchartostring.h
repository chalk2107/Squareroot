#ifndef TEST_FOR_CONVERTARRCHARTOSTRING_H
#define TEST_FOR_CONVERTARRCHARTOSTRING_H

#include <QtTest/QtTest>
#include <QObject>
#include "positiveintegerthroughqvector.h"

/**
 * @brief Тесты для функции "Конвертация массива символов в строку"
 */
class Test_for_convertArrCharToString : public QObject
{
    Q_OBJECT

private slots:
    //! Тесты
    void arrayCharacter1(); //!< #1 Массив из 1ого символа
    void arrayCharacter4(); //!< #2 Массив из 4ех символов
    void arrayCharacter30(); //!< #3 Массив из 30ти символов
};

#endif // TEST_FOR_CONVERTARRCHARTOSTRING_H
