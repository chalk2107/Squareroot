#include "error.h"


QStringList formatErrorPosition(const int errorPosition, QString errorLine) {

    QStringList result;
     result << errorLine;
    QString string;
    for (int i = 0; i < errorPosition; i++) {
        string += "-";
    }
    string += "^";
    result << string;
    return result;
}


QStringList  Error::generateErrorMessage(const QString& filePath, const QString& fileOutPath){
    Error error;
    error.errorInputFilePath = filePath;

    bool flag = false;

    // Проверка существования входного файла
    if (!QFile::exists(filePath)) {
        error.errors.insert(inputFileNotExist);
        flag = true;
    }

    if(!flag){

    QFile file(filePath);
    file.open(QIODevice::ReadOnly);

    QTextStream in(&file);
    QString line = in.readLine();
    lineFile = line;
    //qDebug() << line;

    // Проверка пустого файла
    if (line.isNull()) {
        error.errors.insert(inputFileEmpty);
        file.close();
    }

    // Проверка существования выходного файла
    QFile fileOut(fileOutPath);
    if (!fileOut.open(QIODevice::ReadOnly)) {
        error.errors.insert(outputFileNotCreated);
    }

    fileOut.close();

    // Проверка на наличие более одной строки
    int lineCount = 0;
    while (!in.atEnd()) {
        in.readLine();
        lineCount++;
    }
    if (lineCount >= 1) {
        error.errors.insert(moreOneLine);
    }

    // Проверка на отрицательное число
    bool flagHasNegative = false;
    if (line.startsWith('-')) {
        error.errors.insert(negativeNumber);
        flagHasNegative = true;
    }

    // Проверка на слишком большое число (больше 10^100)
    if (line.length() > 99) {
        error.errors.insert(largeNumber);
    }

    // Проверка на пробелы
    bool flagHasSpace = false;
    bool flagHasChar = false;

    int ind = 0;
    for (QChar ch : line) {
        bool hasSpace = false;
        if (ch.isSpace()) {
            error.errors.insert(spaceBetweenNumbers);
            hasSpace = true;

            if(!flagHasSpace){
                indexErrorSpace = ind;
            }

            flagHasSpace = true;
        }

        if (!ch.isDigit() && !hasSpace) {
            if(!flagHasNegative){
                error.errors.insert(noNumberInLine);

                if(!flagHasChar){
                    indexErrorNoNum = ind;
                }

                flagHasChar = true;
            }
        }
        flagHasNegative = false;
        ind++;
    }
    file.close();
    }

    //qDebug() << "Errors count:" << error.errors.size();
    QStringList  message;
    for (int err : error.errors) {
        switch (err) {
        case inputFileNotExist:
            message << "Неверно указан файл с входными данными. Возможно, файл не существует";
            break;
        case inputFileEmpty:
            message << "В указанном входном файле нет значений. Добавьте значение.";
            break;
        case outputFileNotCreated:
            message << "Неверно указан файл для выходных данных. Возможно указанного расположения не существует или нет прав на запись.";
            break;
        case moreOneLine:
            message << "Программа принимает на вход файлы из одной строки. Разместите каждую строчку в отдельном файле.";
            break;
        case noNumberInLine:
            message << "Во входном числе присутствует символ, который не является цифрой.";
            message << formatErrorPosition(indexErrorNoNum, lineFile)[0];
            message << formatErrorPosition(indexErrorNoNum, lineFile)[1];
            break;
        case largeNumber:
            message << "Введенное значение превышает допустимое значение. Измените число.";
            break;
        case negativeNumber:
            message << "Во входной числе присутствует символ “-”, который не является цифрой.";
            message << formatErrorPosition(0, lineFile)[0];
            message << formatErrorPosition(0, lineFile)[1];
            break;
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
