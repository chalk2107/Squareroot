#include "positiveintegerthroughqvector.h"

PositiveIntegerThroughQVector::PositiveIntegerThroughQVector()
{

}


QString PositiveIntegerThroughQVector::convertArrayCharToString(){
    QString string;

    for (int i = 0; i < vectorInteger.length(); i++) {
        string += vectorInteger[i];
    }
    return string;
}


PositiveIntegerThroughQVector PositiveIntegerThroughQVector::squareRoot() {
    int y{ 0 }; // максимальное число
    int p{ 0 }; // уже найденный корень
    int del;    // делитель
    int i{ 0 }; // данная цифра
    int sg{ 0 };
    QVector<char> vectorSqrt;
    QVector<char> newVector = vectorInteger;


    if (newVector.length() % 2 == 0) {
        del = 2;
    }
    else {
        del = 1;
    }

    i = del;

    while (i <= vectorInteger.length()) {
        int x = 0;

        //Считать, что текущее максимальное число по формуле y = x(20p + x)
        y = maxIntforSqRt(p, newVector, x, sg, del);

        //Дополняем вычитаемое число в конец найденного корня
        vectorSqrt += x + '0';

        //говно
        int lenSqV = vectorSqrt.length();
        p = p * 10 + (vectorSqrt[lenSqV - 1] - '0');


        //Находим разность сгруппированного числа и максимального числа
        int raz = sg - y;


        QString newRemaining = QString::number(raz);
        int lenRaz = newRemaining.length();


        newVector.remove(0, del);

        for (int g = lenRaz - 1; g >= 0; g--) {
            newVector.insert(0, newRemaining.at(g).toLatin1());
        }
        del = 2 + lenRaz;
        i += 2;

    }

    PositiveIntegerThroughQVector r;
    r.vectorInteger = vectorSqrt;

    return r;
}


int maxIntforSqRt(int p, QVector<char> vector, int &x, int &sgrupInt, int lenSgrupInt){
    int y = 0;
    int sg = 0;
    int flag = 0;

    //Пока длина сгруппированного числа не равняется нулю
    for (int j = 0; lenSgrupInt != 0; j++) {

        //Находим сгруппированное число
        sg += qPow(10, j) * (vector[lenSgrupInt - 1] - '0');
        lenSgrupInt--;
    }

    for (; y < sg && !flag;) {
        y = x * (20 * p + x);

        if (!((x + 1) * (20 * p + (x + 1)) > sg)) {
            ++x;
        }
        else flag = 1;
    }

    sgrupInt = sg;

    return y;
}


// Сравнение двух чисел в QVector<char>
int compareVectors(const QVector<char>& vector1, const QVector<char>& vector2) {
    if (vector1.size() != vector2.size()) {
        return vector1.size() < vector2.size() ? -1 : 1;
    }

    for (int i = 0; i < vector1.size(); i++) {
        if (vector1[i] != vector2[i]) {
            return vector1[i] < vector2[i] ? -1 : 1;
        }
    }
    return 0;
}

