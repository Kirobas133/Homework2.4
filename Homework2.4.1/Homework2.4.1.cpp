// Homework2.4.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <Windows.h>

class Adress {
public:
    std::string city;
    std::string street;
    int house;
    int appartment;

public:
    Adress() {
        city = "unknown";
        street = "unknown";
        house = 0;
        appartment = 0;
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int N;
    std::ifstream ifs("in.txt");

    if (ifs) {
        ifs >> N;
        Adress* adresslist = new Adress[N];
        for (int i = 0; i < N; i++) {
            ifs >> adresslist[i].city;
            ifs >> adresslist[i].street;
            ifs >> adresslist[i].house;
            ifs >> adresslist[i].appartment;
        }
        ifs.close();
        std::ofstream ofs("out.txt");
        ofs << N << std::endl;
        for (int i = (N - 1); i >= 0; i--) {
            ofs << adresslist[i].city << ", "
                << adresslist[i].street << ", "
                << adresslist[i].house << ", "
                << adresslist[i].appartment << std::endl;
        }
        delete[] adresslist;
    }
    else {
        std::cout << "File 'in.txt' not found!\n";
    }

    std::cout << "Hello World!\n";
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
