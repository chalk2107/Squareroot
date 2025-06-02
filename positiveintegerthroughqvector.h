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

#endif // POSITIVEINTEGERTHROUGHQVECTOR_H
