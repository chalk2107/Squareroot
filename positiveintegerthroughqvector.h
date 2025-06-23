#ifndef POSITIVEINTEGERTHROUGHQVECTOR_H
#define POSITIVEINTEGERTHROUGHQVECTOR_H
#include <QFile>
#include <QTextStream>
#include <QDebug>

/**
 * @brief Класс положительного целого числа, представленного через массив
 */
class PositiveIntegerThroughQVector
{
public:
    QByteArray vectorInteger; //!< Вектов числа

    /**
     * @brief Конструктор по умолчанию
     */
    PositiveIntegerThroughQVector();

    /**
     * @brief Конструктор, инициализирующий число из файла
     * @param fileName[in] Путь к файлу
     */
    PositiveIntegerThroughQVector(QString fileName);

    /**
     * @brief Конвертация массива символов в строку
     * @return Строковое представления массива символов
     */
    QString convertArrayCharToString();

    /**
     * @brief Квадратный корень числа
     * @return Целую часть квадратного корня
     */
    PositiveIntegerThroughQVector squareRoot();
};


/**
 * @brief Нахождение максимальной цифры для алгоритма извлечения квадратного корня
 * @param p[in] Текущий корень
 * @param vector[in] Вектор числа
 * @param x[out] Перечисляемая переменная
 * @param lenSgrupInt[in] Длина группы цифр
 * @return Вектор максимальной возможной цифрой
 */
QByteArray  maxIntforSqRt(const QByteArray  &p, const QByteArray  &vector, int& x, int lenSgrupInt);


/**
 * @brief Сравнение двух чисел в векторе
 * @param vector1[in] Первое число
 * @param vector2[in] Второе число
 * @return 1 если vector1 > vector2, -1 если vector1 < vector2, 0 если равны
 */
int compareVectors(const QByteArray & vector1, const QByteArray & vector2);


/**
 * @brief Умножение числа в векторе на однозначное число
 * @param vector[in] Число, заданное через вектор
 * @param x[in] Однозначное число
 * @return Произведение чисел, заданное через QVector<char>
 */
QByteArray multiplyByDigit(const QByteArray& vector, int x);


/**
 * @brief Сложение двух чисел в векторе
 * @param vector1[in] Первое число
 * @param vector2[in] Второе число
 * @return Сумма чисел
 */
QByteArray addVectors(const QByteArray& vector1, const QByteArray& vector2);


/**
 * @brief Умножение двух чисел в векторе
 * @param vector1[in] Первое число
 * @param vector2[in] Второе число
 * @return Результат умножения
 */
QByteArray multiplyVectors(const QByteArray& vector1, const QByteArray& vector2);


/**
 * @brief Удаление ведущих нулей
 * @param vector[in] Число, заданное через вектор
 */
void removeLeadingZeros(QByteArray& vector);


/**
 * @brief Вычитание двух чисел в векторе
 * @param vector1[in] Уменьшаемое
 * @param vector2[in] Вычитаемое
 * @return Разность чисел
 * @note vector1 >= vector2
 */
QByteArray subtractVectors(const QByteArray& vector1, const QByteArray& vector2);

#endif // POSITIVEINTEGERTHROUGHQVECTOR_H
