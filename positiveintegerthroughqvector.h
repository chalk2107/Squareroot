#ifndef POSITIVEINTEGERTHROUGHQVECTOR_H
#define POSITIVEINTEGERTHROUGHQVECTOR_H
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QDebug>

/**
 * @brief Класс положительного целого числа, представленного через QVector<char>
 */
class PositiveIntegerThroughQVector
{
public:
    QVector<char> vectorInteger; //!< Вектов числа

    /**
     * @brief Конструктор по умолчанию
     */
    PositiveIntegerThroughQVector();

    /**
     * @brief Конструктор, инициализирующий число из файла
     * @param fileName Путь к файлу
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
QVector<char> maxIntforSqRt(const QVector<char> &p, const QVector<char> &vector, int& x, int lenSgrupInt);


/**
 * @brief Сравнение двух чисел в QVector<char>
 * @param vector1 Первое число
 * @param vector2 Второе число
 * @return 1 если vector1 > vector2, -1 если vector1 < vector2, 0 если равны
 */
int compareVectors(const QVector<char>& vector1, const QVector<char>& vector2);


/**
 * @brief Умножение числа в QVector<char> на однозначное число
 * @param vector Число, заданное через вектор
 * @param x Однозначное число
 * @return Произведение чисел, заданное через QVector<char>
 */
QVector<char> multiplyByDigit(const QVector<char>& vector, int x);


/**
 * @brief Сложение двух чисел в QVector<char
 * @param vector1 Первое число
 * @param vector2 Второе число
 * @return Сумма чисел
 */
QVector<char> addVectors(const QVector<char>& vector1, const QVector<char>& vector2);


/**
 * @brief Умножение двух чисел в QVector<char>
 * @param vector1 Первое число
 * @param vector2 Второе число
 * @return Результат умножения
 */
QVector<char> multiplyVectors(const QVector<char>& vector1, const QVector<char>& vector2);


/**
 * @brief Удаление ведущих нулей
 * @param vector Число, заданное через вектор
 */
void removeLeadingZeros(QVector<char>& vector);


/**
 * @brief Вычитание двух чисел в QVector<char>
 * @param vector1 Уменьшаемое
 * @param vector2 Вычитаемое
 * @return Разность чисел
 * @note vector1 >= vector2
 */
QVector<char> subtractVectors(const QVector<char>& vector1, const QVector<char>& vector2);

#endif // POSITIVEINTEGERTHROUGHQVECTOR_H
