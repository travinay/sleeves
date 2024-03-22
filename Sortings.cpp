#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

int rand(void);

void Bubble_sort(int *numbers, int size)
{
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            if (numbers[j]>numbers[j+1])
            {
                int val = numbers[j+1];
                numbers[j+1] = numbers[j];
                numbers[j] = val; 
            }
        }
    }
}

void Shell_sort(int *numbers, int size)
{
    int i = 0;
    int j = size-1;
    int mid = numbers[size/2];
    do
    {
        while (numbers[i] < mid)
        {
            i++;
        }
        while (numbers[j] > mid)
        {
            j--;
        }
        if (i<=j)
        {
            int val = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = val;
            i++;
            j--;
        }
    } while (i<=j);

    if(j>0)
    {
        Shell_sort(numbers, j+1);  
    }
    if(i<size)
    {
        Shell_sort(&numbers[i], size - i);
    }
}

void Print(int *V)
{
    for (int i = 0; i<10000; i++)
    {
            cout<<V[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    srand(time(0));
    int numbers1[10000];
    for (int i = 0; i<10000; i++)
    {
        numbers1[i] = rand();
    }
    int numbers2[10000];
    for (int i = 0; i<10000; i++)
    {
        numbers2[i] = rand();
    }
    auto start1 = chrono::high_resolution_clock::now();
    Bubble_sort(numbers1, 10000);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff1 = end1 - start1;

    auto start2 = chrono::high_resolution_clock::now();
    Shell_sort(numbers2, 10000);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff2 = end2 - start2;
    if (diff1>diff2)
    {
        cout<<diff2<<"   Ракушечная сортировка быстрее, чем сортировка пузырьком"<<endl;
    }
    else if (diff1<diff2)
    {
        cout<<diff1<<"Сортировка пузырьком быстрее, чем Ракушечная сортировка"<<endl;
    }
    else
    {
        cout<<diff2<<"Сортировки динаковы по времени"<<endl;
    }
    return 0;
}
