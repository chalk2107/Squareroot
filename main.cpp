#include <QCoreApplication>

#include <test_for_convertarrchartostring.h>
#include <test_for_maxintforsqrt.h>
#include "test_for_squareroot.h"
#include <error.h>

#include <QDebug>
#include <cstdlib>
#include <windows.h>

void startTest();
void recordFile(QFile& file, QString line);

int main(int argc, char *argv[])
{
    //! Русский язык
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");

    //! Если введены входной и выходной файлы
    if(argc == 3){
        QString inputFilePath = argv[1];  //!< Путь входного файла
        QString outputFilePath = argv[2]; //!< Путь выходного файла

        //! Создаем выходной файл
        QFile file(outputFilePath);
        file.open(QIODevice::WriteOnly);
        file.close(); // Закрытие файла

        //! Провера на ошибки
        Error errors;
        QStringList valResult = errors.generateErrorMessage(inputFilePath, outputFilePath);

        //! Вывод всех ошибок, если они существуют
        for(int i = 0; i < valResult.length(); i++){
            qDebug() << valResult[i];
        }

        //! Если ошибок нет, вычисляем квадратный корень
        if(valResult.length() == 0){
            PositiveIntegerThroughQVector number(inputFilePath);
            PositiveIntegerThroughQVector sqrtResult = number.squareRoot();
            QString sqrtString = sqrtResult.convertArrayCharToString();

            //! Сохраняем результат в файл
            recordFile(file, sqrtString);
        }
    }

    //! Если введен режим тестов
    else if(argc == 2 && QString(argv[1]) == "test"){
        qDebug() << "Запуск тестов\n";
        startTest();
    }

    //! Неправильные аргументы командной строки
    else{
        //! Остановка программы
        qDebug() << "Введены неверные входные параметры";
        system("pause");
        return 1;
    }

    //! Остановка программы
    system("pause");
    return 0;
}


//! Запуск тестов
void startTest(){
    //! Тесты конвертации
    Test_for_convertArrCharToString test;
    QTest::qExec(&test);
    qDebug() << '\n';

    //! Тесты максимума
    Test_for_maxIntforSqRt test1;
    QTest::qExec(&test1);
    qDebug() << '\n';

    //! Тесты квадр. корня
    Test_for_squareRoot test2;
    QTest::qExec(&test2);
    qDebug() << '\n';
}


//! Сохранение в файл строки
void recordFile(QFile& file, QString line){
    file.open(QIODevice::WriteOnly); // открываем файл
    QTextStream out(&file);
    out << line; // записываем строку в файл
    file.close(); // закрываем файл
}
