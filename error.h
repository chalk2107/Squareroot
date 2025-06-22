#ifndef ERROR_H
#define ERROR_H
#include <QString>
#include <QFile>
#include <QSet>
#include <QTextStream>
#include <QDebug>

//! @brief Класс для обработки ошибок
class Error {
    public:
        int indexErrorNoNum = -1; //!< Индекс ошибки, если символ не цифра
        int indexErrorSpace = -1; //!< Индекс ошибки, если присутствует пробел
        QSet<int> errors; //!< Множество ошибок
        QString lineFile; //!< Строка файла

        /**
         * @brief Генерация сообщения об ошибках
         * @param filePath[in] Путь входного файла
         * @param fileOutPath[in] Путь выходного файла
         * @return Список строк с сообщениями об ошибках
         */
        QStringList  generateErrorMessage(const QString& filePath, const QString& fileOutPath);

        /**
         * @brief Добавление ошибок в множество
         * @param filePath[in] Путь входного файла
         * @param fileOutPath[in] Путь выходного файла
         * @return Класс обработки ошибок со всеми найденными ошибками
         */
        Error addError(const QString& filePath, const QString& fileOutPath);

        /**
         * @brief Проверка на пробелы и символы отличные от цифры
         * @param line[in] Строка из файла
         * @param error[out] Класс обработки ошибок
         * @param flagNegative[in] Флаг отрицательного числа
         */
        void spaceAndCharCheak(QString line, Error& error, bool flagNegative);
};

//! @brief Перечисление типов ошибок
enum ErrorType{
    inputFileNotExist = 1,      //!< Входной файл не существует
    inputFileEmpty = 2,         //!< Входной файл пуст
    outputFileNotCreated = 3,   //!< Выходной файл не создан
    moreOneLine = 4,            //!< Во входном файле больше одной строки
    noNumberInLine = 5,         //!< В строке не число
    largeNumber = 6,            //!< Число слишком большое (больше 10^100)
    negativeNumber = 7,         //!< Отрицательное число
    spaceBetweenNumbers = 8     //!< В строке присутствует пробел
};

/**
 * @brief Форматирование позиции ошибки в строку
 * @param errorPosition[in] Позиция ошибки
 * @param errorLine[in] Строка, в которой ошибка
 * @return Строка, с указанием местоположения ошибки
 */
QStringList formatErrorPosition(const int errorPosition, QString errorLine);

#endif // ERROR_H
