#ifndef TEST_FOR_SQUAREROOT_H
#define TEST_FOR_SQUAREROOT_H

#include <QtTest/QtTest>
#include <QObject>
#include "positiveintegerthroughqvector.h"

/**
 * @brief Тесты для функции "Квадратный корень числа"
 */
class Test_for_squareRoot : public QObject
{
    Q_OBJECT

private slots:
    //! Тесты
    void rootSmallestNumber(); //!< №1 Корень самого маленького числа
    void rootSingleDigitNumberOutcomeInteger(); //!< №2 Корень однозначного числа, с целым исходом
    void rootSingleDigitNumberOutcomeNonInteger(); //!< №3 Корень однозначного числа, с не целым исходом
    void rootTwoDigitNumberOutcomeInteger(); //!< №4 Корень двухзначного числа, с целым исходом
    void rootTwoDigitNumberOutcomeNonInteger(); //!< №5 Корень двухзначного числа, с не целым исходом
    void rootThreeDigitNumberOutcomeInteger(); //!< №6 Корень трехзначного числа, с целым исходом
    void rootThreeDigitNumberOutcomeNonInteger(); //!< №7 Корень трехзначного числа, с не целым исходом
    void rootFourDigitNumberOutcomeInteger(); //!< №8 Корень четырехзначного числа, с целым исходом
    void rootFourDigitNumberOutcomeNonInteger(); //!< №9 Корень четырехзначного числа, с не целым исходом
    void rootTenDigitNumberOutcomeInteger(); //!< №10 Корень десятизначного числа, с целым исходом
    void rootTenDigitNumberOutcomeNonInteger(); //!< №11 Корень десятизначного числа, с не целым исходом
    void rootThirtyDigitNumberOutcomeInteger(); //!< №12 Корень тридцатизначного числа, с целым исходом
    void rootThirtyDigitNumberOutcomeNonInteger(); //!< №13 Корень тридцатизначного числа, с не целым исходом
    void rootFiftyDigitNumberOutcomeInteger(); //!< №14 Корень пятидесятизначного числа, с целым исходом
    void rootFiftyDigitNumberOutcomeNonInteger(); //!< №15 Корень пятидесятизначного числа, с не целым исходом
    void rootSeventyDigitNumberOutcomeInteger(); //!< №16 Корень семидесятизначного числа, с целым исходом
    void rootSeventyDigitNumberOutcomeNonInteger(); //!< №17 Корень семидесятизначного числа, с не целым исходом
    void rootNinetyDigitNumberOutcomeInteger(); //!< №18 Корень девяностозначного числа, с целым исходом
    void rootNinetyDigitNumberOutcomeNonInteger(); //!< №19 Корень девяностозначного числа, с не целым исходом
};

#endif // TEST_FOR_SQUAREROOT_H
