// Laba3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
using namespace std;

int** CreateMatrix(int m, int n, HANDLE heaphandle)
{
    int** matrix = (int**)HeapAlloc(heaphandle, HEAP_ZERO_MEMORY, m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int*)HeapAlloc(heaphandle, HEAP_ZERO_MEMORY, n * sizeof(int));
    }
    puts("Ввод элементов матрицы:");
    for (int i = 0; i < m; i++)
       for (int j = 0; j < n; j++)
       {
          printf("Введите элемент [%d][%d]\n", i, j);
          scanf("%d", &matrix[i][j]);
       }
    return matrix;
}
//поиск максимального элэмента среди наименьших элементов каждой строки
void Action(int** matrix, int m, int n)
{
    int minEl = 0;
    int maxEl = NULL;
    int str = 0;
    int col = 0;
    for (int i = 0; i < m; i++)
    {
        //берем 1 элемент i строки и делаем сравнение
        minEl = matrix[i][0];
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] < minEl)
            {
                minEl = matrix[i][j];
            }
        }
        if (maxEl == NULL)
        {
            maxEl = minEl;
            str = i;
        }
        else
        {
            if (minEl > maxEl)
            {
                maxEl = minEl;
                str = i;
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (matrix[str][j] == maxEl)
        {
            col = j;
            break; //выходим так как нашли номер столбца
        }
    }
    printf("\nЭлемент по индексу: %d, %d\n", str, col);
}
void PrintMatrix(int** mat, int m, int n)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}
void DestrMat(int** mat, int m, HANDLE heaphandle)//функция аннулирования матрицы
{
    for (int i = 0; i < m; i++)
    {
        HeapFree(heaphandle, HEAP_NO_SERIALIZE, mat[i]);
    }
    HeapFree(heaphandle, HEAP_NO_SERIALIZE, mat);
}
int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Лабораторная работа #3. Выполнил студент группы 6215 Едавкин Степан\n";
    int m, n;
    puts("Введите M: ");
    scanf("%d", &m);
    puts("Введите N: ");
    scanf("%d", &n);
    printf("\n");
    HANDLE heaphandle = GetProcessHeap();
    int** mat = CreateMatrix(m, n, heaphandle);
    puts("\nВаша матрица: ");
    PrintMatrix(mat, m, n);
    Action(mat, m, n);
    DestrMat(mat, m, heaphandle);
    system("PAUSE");
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
