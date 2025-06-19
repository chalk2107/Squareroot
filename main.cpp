#include <QCoreApplication>

#include <test_for_convertarrchartostring.h>
#include <test_for_maxintforsqrt.h>
#include "test_for_squareroot.h"
#include <error.h>

#include <QDebug>
#include <cstdlib>
#include <windows.h>

int main(int argc, char *argv[])
{
    //Русский язык
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");

    if(argc == 3){
        QString inputFilePath = argv[1];
        QString outputFilePath = argv[2];

        QFile file(outputFilePath);

        file.open(QIODevice::WriteOnly);
        file.close();

        Error errors;
        QStringList valResult = errors.generateErrorMessage(inputFilePath, outputFilePath);

        for(int i = 0; i < valResult.length(); i++){
            qDebug() << valResult[i];
        }

        if(valResult.length() == 0){
            PositiveIntegerThroughQVector Sqrt(inputFilePath);

            PositiveIntegerThroughQVector sqrtResult = Sqrt.squareRoot();
            QString sqrtString = sqrtResult.convertArrayCharToString();

            file.open(QIODevice::WriteOnly);
            QTextStream out(&file);

            out << sqrtString;
            file.close();
        }
    }

    else if(argc == 2 && QString(argv[1]) == "test"){
        //Тесты конвертации
        Test_for_convertArrCharToString test;
        QTest::qExec(&test);
        qDebug() << '\n';

        //Тесты максимума
        Test_for_maxIntforSqRt test1;
        QTest::qExec(&test1);
        qDebug() << '\n';

        //Тесты квадр. корня
        Test_for_squareRoot test2;
        QTest::qExec(&test2);
        qDebug() << '\n';
    }

    else{
        //Остановка программы
        system("pause");
        return 1;
    }

    //Остановка программы
    system("pause");
    return 0;
}
