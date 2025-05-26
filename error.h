#ifndef ERROR_H
#define ERROR_H
#include <QString>


class Error {
    public:
        int indexError;
        QString errorInputFilePath;
        QString errorOutputfilePath;

        QString generateErrorMessage();
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

#endif // ERROR_H
