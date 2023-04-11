// Homework2.4.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

class Adress {
private:
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
    /*Adress(std::string city, std::string street, int house, int appartment) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->appartment = appartment;
    }*/
    void Adress_changing(std::string city, std::string street, int house, int appartment) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->appartment = appartment;
    }
    std::string Adress_output() {
        std::string Out_string;
        Out_string = city + ", " + street + ", "
            + std::to_string(house) + ", "
            + std::to_string(appartment) + "\n";
        return Out_string;
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
        std::string temp_city;
        std::string temp_street;
        int temp_house;
        int temp_appartment;
        Adress* adresslist = new Adress[N];
        for (int i = 0; i < N; i++) {
            ifs >> temp_city;
            ifs >> temp_street;
            ifs >> temp_house;
            ifs >> temp_appartment;
            adresslist[i].Adress_changing(temp_city, temp_street, temp_house, temp_appartment);
        }
        ifs.close();
        std::ofstream ofs("out.txt");
        ofs << N << std::endl;
        for (int i = (N - 1); i >= 0; i--) {
           /* ofs << adresslist[i].city << ", "
                << adresslist[i].street << ", "
                << adresslist[i].house << ", "
                << adresslist[i].appartment << std::endl;*/
            ofs << adresslist[i].Adress_output();
        }
        delete[] adresslist;
    }
    else {
        std::cout << "File 'in.txt' not found!\n";
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
