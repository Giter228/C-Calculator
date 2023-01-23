// С+.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
using namespace std;

int Fibonacci(int i);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
  //  setlocale(LC_ALL, "Ru");
    while (true)
    {
        cout << "Добро пожаловать в калькулятор.\nВыберите действие:\n1 - Сложение\n2 - Вычитание\n3 - Умножение\n4 - Деление\n5 - Остаток от деления\n6 - Числа Фибоначчи\nВаш выбор - ";
        int number;
        cin >> number;

        
        if (number > 6 || number < 1)
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Введите число в необходимом диапазоне!\n\n";
            Sleep(1000);
            cout << "\033[2J\033[1;1H"; // 2 команды. \033[2J - очистка консоли. \033[1;1H - перевод курсора
                                                                                     // в левый верхний угол
            continue;
        }

        if (number > 0 && number < 6)
        {
            double firstVariable, secondVariable;
            try
            {
                cout << "Введите значение первой переменной - ", cin >> firstVariable;
                cout << "Введите значение второй переменной - ", cin >> secondVariable;
                
                if (cin.fail())
                {
                    throw 404;
                }

            }
            catch (int error)
            {
                printf("Ошибка. Повторите попытку.");
                cin.clear();
                cin.ignore(32767, '\n');
                Sleep(1000);
                cout << "\033[2J\033[1;1H";
                continue;
            }

            double result;
            if (number == 1)
            {
                result = firstVariable + secondVariable;
            }
            if (number == 2)
            {
                result = firstVariable - secondVariable;
            }
            if (number == 3)
            {
                result = firstVariable * secondVariable;
            }
            if (number == 4)
            {
                result = firstVariable / secondVariable;
            }
            if (number == 5)
            {
                result = fmod(firstVariable, secondVariable);
            }
            
            cout << "Ответ: " << result << "\n";
        }
        else      // число фибоначи
        {
            int iterations, sum{};
            cout << "Введите количество итераций - ", cin >> iterations;
            
            for (int i = 0; i <= iterations; i++)
            {
                int number = Fibonacci(i);
                cout << number << " ";
                sum += number;
            }
            cout << "\nСумма всех чисел Фибоначчи: " << sum;
        }
        cout << "\n";
        system("pause");
        cout << "\033[2J\033[1;1H";
    }
        return 0;
}

int Fibonacci(int i) {
    if (i == 0)
    {
        return 0;
    }
    else if (i == 1)
    {
        return 1;
    }
    else
    {
        return Fibonacci(i - 2) + Fibonacci(i - 1);
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
