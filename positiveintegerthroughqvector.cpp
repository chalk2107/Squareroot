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

    PositiveIntegerThroughQVector r;
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
