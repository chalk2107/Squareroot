#include "error.h"

//Форматирование позиции ошибки в строку
QStringList formatErrorPosition(const int errorPosition, QString errorLine) {

    QStringList result;
    QString string;
    result << errorLine;

    // Ставим дефис до позиции ошибки
    for(int i = 0; i < errorPosition; i++) {
        string += "-";
    }

    // На позиции ошибки ставим указатель на символ где ошибка
    string += "^";
    result << string;
    return result;
}


// Проверка на пробелы и символы отличные от цифры
void Error::spaceAndCharCheak(QString line, Error& error, bool flagNegative){
    bool flagHasSpace = false;
    bool flagHasChar = false;

    int ind = 0;

    //Для всех символов в строке
    for(QChar ch : line) {
        bool hasSpace = false;

        //Если символ пробел
        if (ch.isSpace()) {
            error.errors.insert(spaceBetweenNumbers);
            hasSpace = true;

            if(!flagHasSpace){
                indexErrorSpace = ind; // Запоминаем индекс ошибки
            }

            flagHasSpace = true;
        }

        //Если символ не символ и не пробел
        if (!ch.isDigit() && !hasSpace){
            if(!flagNegative){
                error.errors.insert(noNumberInLine);

                if(!flagHasChar){
                    indexErrorNoNum = ind; // Запоминаем индекс ошибки
                }

                flagHasChar = true;
            }
        }
        flagNegative = false;
        ind++;
    }
}


// Добавление ошибок в множество
Error Error::addError(const QString& filePath, const QString& fileOutPath){
    Error error;
    bool flag = false;

    //! Проверка существования входного файла
    if (!QFile::exists(filePath)) {
        error.errors.insert(inputFileNotExist);
        flag = true;
    }

    if(!flag){

    //! Открываем файл
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);

    QString line = in.readLine(); // читаем строку

    //! Проверка пустого файла
    if (line.isNull()) {
        error.errors.insert(inputFileEmpty);
        file.close(); //!< закрываем входной файл
    }

    //! Проверка существования выходного файла
    QFile fileOut(fileOutPath);
    if (!fileOut.open(QIODevice::ReadOnly)) {
        error.errors.insert(outputFileNotCreated);
    }
    fileOut.close(); // закрываем выходной файл

    //! Проверка на наличие более одной строки
    int lineCount = 0;

    //Пока не прошли все возможные строки
    while (!in.atEnd()){
        in.readLine();
        lineCount++;
    }
    if (lineCount >= 1){
        error.errors.insert(moreOneLine);
    }

    //! Проверка на отрицательное число
    bool flagHasNegative = false;

    if (line.startsWith('-')) {
        error.errors.insert(negativeNumber);
        flagHasNegative = true;
    }

    //! Проверка на слишком большое число (больше 10^100)
//    if (line.length() > 99) {
//        error.errors.insert(largeNumber);
//    }

    //! Проверка на пробелы и символы отличные от цифры
    spaceAndCharCheak(line, error, flagHasNegative);

    file.close(); // закрываем входной файл
    }
    return error;
}

//Герерация сообщения об ошибках
QStringList  Error::generateErrorMessage(const QString& filePath, const QString& fileOutPath){
    QStringList  message;

    Error error = addError(filePath, fileOutPath);

    //! Проходим все ошибки
    for(int err : error.errors){
        switch (err) {

        // Входной файл не существует
        case inputFileNotExist:
            message << "Неверно указан файл с входными данными. Возможно, файл не существует";
            break;

        // Входной файл пуст
        case inputFileEmpty:
            message << "В указанном входном файле нет значений. Добавьте значение.";
            break;

        // Выходной файл не создан
        case outputFileNotCreated:
            message << "Неверно указан файл для выходных данных. Возможно указанного расположения не существует или нет прав на запись.";
            break;

        // Во входном файле больше одной строки
        case moreOneLine:
            message << "Программа принимает на вход файлы из одной строки. Разместите каждую строчку в отдельном файле.";
            break;

        // В строке не число
        case noNumberInLine:
            message << "Во входном числе присутствует символ, который не является цифрой.";
            message << formatErrorPosition(indexErrorNoNum, lineFile)[0];
            message << formatErrorPosition(indexErrorNoNum, lineFile)[1];
            break;

        // Число слишком большое (больше 10^100)
        case largeNumber:
            message << "Введенное значение превышает допустимое значение. Измените число.";
            break;

        // Отрицательное число
        case negativeNumber:
            message << "Во входной числе присутствует символ “-”, который не является цифрой.";
            message << formatErrorPosition(0, lineFile)[0];
            message << formatErrorPosition(0, lineFile)[1];
            break;

        // В строке присутствует пробел
        case spaceBetweenNumbers:
            message << "Во входном числе присутствует пробел, который не является цифрой.";
            message << formatErrorPosition(indexErrorSpace, lineFile)[0];
            message << formatErrorPosition(indexErrorSpace, lineFile)[1];
            break;
        default:
            message << "Нет ошибок";
        }
    }
    return message;
}
