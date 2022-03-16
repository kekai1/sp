#include <iostream>
#include <ctime>
#include <random>

using namespace std;



extern "C" {

        const int size = 10;
        int size_asm = size;
        int arr[size];
        int arr2[size];
        int sum;
};


int main()
{
    srand(time(0));


    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 51;
        arr2[i] = rand() % 51;
    }
    //Код на ассемблере
        __asm
        (
        R"(
                .intel_syntax noprefix ; //используем синтаксис intel

                mov esi, 0                              ; //Регистр где храним адрес элементов одномерного массива
                mov dl, 0                                                               ; //Регистр где считаем количество пройденных элемент>
                        Start:
                mov ecx, arr[esi]  //ложим в регистр ecx значение массива
                imul ecx, arr2[esi] // перемножаем ecx на значение из второго массива, то есть ecx = ecx * arr2[esi]
                add sum, ecx ; // результат умножения лежит в ecx, его ложим в sum
                add esi, 4                  ; // Переход к другому элементу массива
                        CheckEnd:
                add dl, 1                   ; // Увеличиваем количество пройденых строк
                cmp dl, BYTE PTR size_asm ; // Сравнение, есть ли ещё строки
                jl Start                                        ; // Если есть, опять идем к функции Start

                .att_syntax
        )"
        );

   cout << sum << endl;
   return 0;
}
