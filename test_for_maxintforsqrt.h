#ifndef TEST_FOR_MAXINTFORSQRT_H
#define TEST_FOR_MAXINTFORSQRT_H

#include <QtTest/QtTest>
#include <QObject>
#include "positiveintegerthroughqvector.h"

/**
 * @brief Тесты для функции "Нахождение максимальной цифры для алгоритма извлечения квадратного корня"
 */
class Test_for_maxIntforSqRt : public QObject
{
    Q_OBJECT

private slots:
    //! Тесты
    void minimumNumber(); //!< #1 Минимальное число
    void singleDigitNumberOutcomeInteger(); //!< #2 Однозначное число, с целым исходом
    void twoDigitNumberOutcomeSmaller(); //!< #3 Двузначное число, с меньшим исходом
    void twoDigitNumberOutcomeInteger(); //!< #4 Двузначное число, с целым исходом
    void twoDigitNumberOutcomeSmallerWithPartialRoot(); //!< #5 Двузначное число, с меньшим исходом и частью найденного корня
    void threeDigitNumberOutcomeIntegerWithPartialRoot(); //!< #6 Трехзначное число, с целым исходом и частью найденного корня
};

#endif // TEST_FOR_MAXINTFORSQRT_H
