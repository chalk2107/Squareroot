#ifndef ERROR_H
#define ERROR_H
#include <QString>
#include <QFile>
#include <QSet>
#include <QTextStream>
#include <QDebug>

class Error {
    public:
        int indexErrorNoNum = -1;
        int indexErrorSpace = -1;
        QString errorInputFilePath;
        QString errorOutputfilePath;
        QSet<int> errors;
        QString lineFile;

        QStringList  generateErrorMessage(const QString& filePath, const QString& fileOutPath);
};

enum ErrorType{
    noError = 0,
    inputFileNotExist = 1,
    inputFileEmpty = 2,
    outputFileNotCreated = 3,
    moreOneLine = 4,
    noNumberInLine = 5,
    largeNumber = 6,
    negativeNumber = 7,
    spaceBetweenNumbers = 8
};

QStringList formatErrorPosition(const int errorPosition, QString errorLine);

#endif // ERROR_H
