#include "positiveintegerthroughqvector.h"

// Конструктор по умолчанию
PositiveIntegerThroughQVector::PositiveIntegerThroughQVector(){

}


// Конструктор, инициализирующий число из файла
PositiveIntegerThroughQVector::PositiveIntegerThroughQVector(QString fileName){
    QFile file(fileName);

    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);

    QString line = in.readLine(); // Чтение файла

    file.close(); // Закрытие файла

    //! Сохранение числа в вектор
    QByteArray byteArray = line.toLatin1();

    for (int i = 0; i < byteArray.length();i++) {
        vectorInteger += byteArray[i];
    }
}


// Конвертация массива символов в строку
QString PositiveIntegerThroughQVector::convertArrayCharToString(){
    QString string;

    //! Для всех символов в массиве цифр
    for (int i = 0; i < vectorInteger.length(); i++){
        string += vectorInteger[i]; //!< Добавлять в конец строки новый символ
    }
    return string;
}


// Квадратный корень числа
PositiveIntegerThroughQVector PositiveIntegerThroughQVector::squareRoot() {
    int lenSgrupInt; // длина сгруппированного число
    int i{ 0 }; // индекс данной цифры
    QVector<char> vectorSqrt; // вектор с результатом вычисления квадратного корня
    QVector<char> newVector = vectorInteger; // копия исходного числа
    QVector<char> p = { '0' };  // текущее значение корень

    //! Определяем начальную длину сгруппированного числа
   (newVector.length() % 2 == 0) ? lenSgrupInt = 2 : lenSgrupInt = 1;

    i = lenSgrupInt;

    //! Пока число не закончилось
    while(i <= vectorInteger.length()){
        int x = 0; // текущая цифра корня
        QVector<char> sg; // сгруппированное число

        //! Считать, что текущее максимальное число по формуле y = x(20p + x)
        QVector<char> y = maxIntforSqRt(p, newVector, x, lenSgrupInt);

        //! Дополняем вычитаемое число в конец найденного корня
        vectorSqrt += x + '0';

        // Обновляем p = p * 10 + x
        p = multiplyByDigit(p, 10);
        QVector<char> xVector = QVector<char>(1, x + '0');
        p = addVectors(p, xVector);

        //! Находим сгруппированное число для всех длины сгруппированного числа
        for(int j = 0; j != lenSgrupInt; j++){
            sg += (newVector[j]);
        }

        //! Находим разность сгруппированного числа и максимального числа
        QVector<char> raz = subtractVectors(sg, y);
        int lenRaz = raz.length();
        removeLeadingZeros(raz); // удаляем ведущие нули
        newVector.remove(0, lenSgrupInt); // удаляем по длине сгруппированного числа

        //! Группируем разность с двумя следующими цифрами
        for(int g = lenRaz - 1; g >= 0; g--){
            newVector.insert(0, raz[g]);
        }

        lenSgrupInt = 2 + lenRaz; // обновляем колличество цифр
        i += 2; // переходим к следующей паре цифр
    }

    // Сохраняем результат
    PositiveIntegerThroughQVector r;
    r.vectorInteger = vectorSqrt;
    return r;
}


// Нахождение максимальной цифры для алгоритма извлечения квадратного корня
QVector<char> maxIntforSqRt(const QVector<char> &p, const QVector<char> &vector, int& x, int lenSgrupInt){
    QVector<char> y;
    QVector<char> sg; // сгруппированное число
    x = 0;
    bool found = false; // флаг нахождения максимального x

    //! Находим сгруппированное число, пока длина сгруппированного числа не равняется нулю
    for (int j = 0; j != lenSgrupInt; j++) {
        sg += (vector[j]);
    }

    //! Пока максимальное число меньше сгруппированного числа
    while (!found && compareVectors(y, sg) < 0) {

        //! Находим y по формуле  y = x*(20*p + x)
        QVector<char> term = multiplyByDigit(p, 20);    // 20*p
        QVector<char> xVector = QVector<char>(1, x + '0');  // x в виде вектора
        term = addVectors(term, xVector);   // 20*p + x
        y = multiplyVectors(term, xVector); // x*(20*p + x)

        //! Вычисляем yNext = (x+1)*(20*p + (x+1))
        QVector<char> nextX = QVector<char>(1, (x + 1) + '0');  // x+1 в виде вектора
        QVector<char> nextTerm = multiplyByDigit(p, 20);    // 20*p
        nextTerm = addVectors(nextTerm, nextX); // 20*p + (x+1)
        QVector<char> yNext = multiplyVectors(nextTerm, nextX); // (x+1)*(20*p + (x+1))

        //! Если yNext <= sg, увеличиваем x
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

    //! Сравниваем по длине
    if (vector1.size() != vector2.size()) {
        return vector1.size() < vector2.size() ? -1 : 1;
    }

    //! Сравниваем по цифрам
    for (int i = 0; i < vector1.size(); i++) {
        if (vector1[i] != vector2[i]) {
            return vector1[i] < vector2[i] ? -1 : 1;
        }
    }
    return 0;
}


// Умножение числа в QVector<char> на однозначное число
QVector<char> multiplyByDigit(const QVector<char>& vector, int x) {
    if (x == 0) return { '0' }; // Если умножаем на 0

    QVector<char> resultVector;
    int carry = 0; // перенос

    //! Для всего чила справа налево
    for (int i = vector.size() - 1; i >= 0; --i) {
        int digit = vector[i] - '0'; // текущая цифра
        int product = digit * x + carry; //!< вычисляем произведение
        carry = product / 10; // вычисляем перенос
        resultVector.prepend((product % 10) + '0');
    }

    //! Если остался перенос, добавляем его
    if (carry > 0) {
        resultVector.prepend(carry + '0');
    }

    return resultVector;
}


// Сложение двух чисел в QVector<char>
QVector<char> addVectors(const QVector<char>& vector1, const QVector<char>& vector2) {
    QVector<char> resultVector;
    int i = vector1.size() - 1; // индекс последней цифры первого числа
    int j = vector2.size() - 1; // индекс последней цифры второго числа
    int carry = 0; // перенос

    //! Пока не сложили все число
    while (i >= 0 || j >= 0 || carry > 0) {
        int digitA = (i >= 0) ? vector1[i--] - '0' : 0; // берем цифру для первого числа
        int digitB = (j >= 0) ? vector2[j--] - '0' : 0; // берем цифру для второго числа
        int sum = digitA + digitB + carry; //!< вычисляем сумму
        carry = sum / 10; // вычисляем перенос
        resultVector.prepend((sum % 10) + '0');
    }

    return resultVector;
}


// Умножение двух чисел в QVector<char>
QVector<char> multiplyVectors(const QVector<char>& vector1, const QVector<char>& vector2){
    QVector<char> resultVector = { '0' };

    //! Для всех цифр второго числа
    for(int i = vector2.size() - 1; i >= 0; i--) {
        int shift = 0; // сдвиг для добавления нулей
        int digit = vector2[i] - '0'; // текущая цифра

        //! Умножаем первое число на текущую цифру
        QVector<char> partial = multiplyByDigit(vector1, digit);

        //! Добавляем нули
        for(int j = 0; j < shift; j++) {
            partial.append('0');
        }

        //! Суммируем произведения
        resultVector = addVectors(resultVector, partial);
        shift++;
    }

    return resultVector;
}

// Удаление ведущих нулей
void removeLeadingZeros(QVector<char>& vector) {

    //! Пока в векторе есть в начале нули, удаляем их
    while(vector.size() >= 1 && vector[0] == '0') {
        vector.remove(0);
    }
}


// Вычитание двух чисел в QVector<char>
QVector<char> subtractVectors(const QVector<char>& vector1, const QVector<char>& vector2) {

    QVector<char> resultVector;
    QVector<char> vectorCopy1 = vector1; // копия первого числа
    QVector<char> vectorCopy2 = vector2; // копия второго числа

    //! Добавляем нули ко второму числу
    while (vectorCopy2.size() < vectorCopy1.size()) {
        vectorCopy2.prepend('0');
    }

    int borrow = 0;

    //! Вычитаем справа налево
    for(int i = vectorCopy1.size() - 1; i >= 0; --i){
        int digitCopy1 = vectorCopy1[i] - '0' - borrow;
        int digitCopy2 = vectorCopy2[i] - '0';

        //! Если цифра уменьшаемого меньше вычитаемого, занимаем из старшего разряда
        if (digitCopy1 < digitCopy2){
            digitCopy1 += 10;
            borrow = 1;
        }
        else{
            borrow = 0;
        }

        int diff = digitCopy1 - digitCopy2;
        resultVector.prepend(diff + '0');
    }

    //! Удаляем ведущие нули
    removeLeadingZeros(resultVector);

    return resultVector;
}
