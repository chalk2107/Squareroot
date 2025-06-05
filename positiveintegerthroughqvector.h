#ifndef POSITIVEINTEGERTHROUGHQVECTOR_H
#define POSITIVEINTEGERTHROUGHQVECTOR_H
#include <QVector>
#include <QtMath>

class PositiveIntegerThroughQVector
{
public:
    QVector<char> vectorInteger;

    PositiveIntegerThroughQVector();
    QString convertArrayCharToString();
    PositiveIntegerThroughQVector squareRoot();
};


int maxIntforSqRt(int p, QVector<char> vector, int &x, int &sgrupInt, int lenSgrupInt);

// Сравнение двух чисел в QVector<char>
int compareVectors(const QVector<char>& vector1, const QVector<char>& vector2);

// Умножение числа в QVector<char> на однозначное число
QVector<char> multiplyByDigit(const QVector<char>& vector, int x);

// Сложение двух чисел в QVector<char>
QVector<char> addVectors(const QVector<char>& vector1, const QVector<char>& vector2);

#endif // POSITIVEINTEGERTHROUGHQVECTOR_H
