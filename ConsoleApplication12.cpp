// ConsoleApplication11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <fstream>


class Adress {
public:
    Adress() {}
    Adress(std::string city, std::string st, int num1, int num2) {
        this->city = city;
        this->st = st;
        this->num1 = num1;
        this->num2 = num2;

    }
    std::string get_city() { return city; }
    void get_output_address(std::ofstream& fout) {
        fout << city << ", " << st << ", " << num1 << ", " << num2 << "\n";
        std::cout << city << ", " << st << ", " << num1 << ", " << num2 << "\n";

    }
private:
    std::string city;
    std::string st;
    int num1;
    int num2;


};
int main()
{
    int num = 0;
    std::ifstream fin("in2.txt");
    std::ofstream fout("out2.txt");

    fin >> num;
    std::string city;

    std::string st;

    int num1 = 1;

    int num2 = 1;

    Adress* arr = new Adress[num];
 
    for (int i = 0; i < num; i++) {

        std::string city;
        fin >> city;
     
        std::string st;
        fin >> st;
        int num1 = 1;
        fin >> num1;
        int num2 = 1;
        fin >> num2;
        Adress adress(city, st, num1, num2);
        arr[i] = adress;

    }
    int nuh = num;
    while (nuh--) {
        bool swapped = false;
        for (int i = 0; i < num-1; i++) {

            if (arr[i].get_city() > arr[i + 1].get_city() ){
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (swapped = false) {
            break;
        }
   }
    
    for (int i = 0; i  < num; i++) {
        arr[i].get_output_address(fout);
    }



    delete[]arr;


}

