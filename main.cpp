#include <QCoreApplication>

#include <test_for_convertarrchartostring.h>
#include <test_for_maxintforsqrt.h>
#include "test_for_squareroot.h"

#include <QDebug>
#include <cstdlib>
#include <windows.h>

int main(int argc, char *argv[])
{
    //Русский язык
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //qDebug() << 532532;

    //Тесты конвертации
    Test_for_convertArrCharToString test;
    QTest::qExec(&test);

    //Тесты максимума
    Test_for_maxIntforSqRt test1;
    QTest::qExec(&test1);

    //Тесты квадр. корня
    Test_for_squareRoot test2;
    QTest::qExec(&test2);

    //Остановка программы
    system("pause");
    return 0;

}
