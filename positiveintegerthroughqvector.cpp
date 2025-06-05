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
        //y = maxIntforSqRt(p, newVector, x, sg, del);

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


QVector<char> maxIntforSqRt(const QVector<char> &p, const QVector<char> &vector, int& x, int lenSgrupInt){
    QVector<char> y;
    QVector<char> sg;
    x = 0;
    bool found = false;

    //Пока длина сгруппированного числа не равняется нулю
    for (int j = 0; j != lenSgrupInt; j++) {

        //Находим сгруппированное число
        sg += (vector[j]);
    }

    while (!found && compareVectors(y, sg) < 0) {

        QVector<char> term = multiplyByDigit(p, 20);    // 20*p
        QVector<char> xVector = QVector<char>(1, x + '0');  // x в виде вектора
        term = addVectors(term, xVector);   // 20*p + x
        y = multiplyVectors(term, xVector); // x*(20*p + x)

        QVector<char> nextX = QVector<char>(1, (x + 1) + '0');  // x+1 в виде вектора
        QVector<char> nextTerm = multiplyByDigit(p, 20);    // 20*p
        nextTerm = addVectors(nextTerm, nextX); // 20*p + (x+1)
        QVector<char> yNext = multiplyVectors(nextTerm, nextX); // (x+1)*(20*p + (x+1))


        if (compareVectors(yNext, sg) <= 0) {
            x++;
        }
        else {
            found = true;
        }
    }


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


// Умножение числа в QVector<char> на однозначное число
QVector<char> multiplyByDigit(const QVector<char>& vector, int x) {
    if (x == 0) return { '0' };

    QVector<char> resultVector;
    int carry = 0;

    for (int i = vector.size() - 1; i >= 0; --i) {
        int digit = vector[i] - '0';
        int product = digit * x + carry;
        carry = product / 10;
        resultVector.prepend((product % 10) + '0');
    }

    if (carry > 0) {
        resultVector.prepend(carry + '0');
    }

    return resultVector;
}


// Сложение двух чисел в QVector<char>
QVector<char> addVectors(const QVector<char>& vector1, const QVector<char>& vector2) {
    QVector<char> resultVector;
    int i = vector1.size() - 1;
    int j = vector2.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digitA = (i >= 0) ? vector1[i--] - '0' : 0;
        int digitB = (j >= 0) ? vector2[j--] - '0' : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;

        resultVector.prepend((sum % 10) + '0');
    }

    return resultVector;
}


// Умножение двух чисел в QVector<char>
QVector<char> multiplyVectors(const QVector<char>& vector1, const QVector<char>& vector2){
    QVector<char> resultVector = { '0' };

    for(int i = vector2.size() - 1; i >= 0; i--) {
        int shift = 0;
        int digit = vector2[i] - '0';

        QVector<char> partial = multiplyByDigit(vector1, digit);

        for(int j = 0; j < shift; j++) {
            partial.append('0');
        }

        resultVector = addVectors(resultVector, partial);
        shift++;
    }

    return resultVector;
}

// Удаляет ведущие нули
void removeLeadingZeros(QVector<char>& vector) {
    while (vector.size() >= 1 && vector[0] == '0') {
        vector.remove(0);
    }
}


QVector<char> subtractVectors(const QVector<char>& vector1, const QVector<char>& vector2) {

    QVector<char> resultVector;
    QVector<char> vectorCopy1 = vector1;
    QVector<char> vectorCopy2 = vector2;

    while (vectorCopy2.size() < vectorCopy1.size()) {
        vectorCopy2.prepend('0');
    }

    int borrow = 0;

    for (int i = vectorCopy1.size() - 1; i >= 0; --i) {
        int digitCopy1 = vectorCopy1[i] - '0' - borrow;
        int digitCopy2 = vectorCopy2[i] - '0';

        if (digitCopy1 < digitCopy2) {
            digitCopy1 += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        int diff = digitCopy1 - digitCopy2;
        resultVector.prepend(diff + '0');
    }

    // Удаляем ведущие нули
    removeLeadingZeros(resultVector);

    return resultVector;
}
