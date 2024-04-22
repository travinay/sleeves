#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std;

int* Shell_sort(int *numbers, int size)
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
        async(Shell_sort, numbers, j+1);
    }
    if(i<size)
    {
        async(Shell_sort, &numbers[i], size - i);
    }
    return numbers;
}
int main()
{
    int *mas = new int[100];
    for (int i = 0; i < 100; i++)
    {
        mas[i] = rand()%100;
    }
    auto t1  = async(Shell_sort, mas, 100);
    int *mas_sorted;
    mas_sorted = t1.get();
    for (int i = 0; i < 100; i++)
    {
        cout<<mas_sorted[i]<<" ";
    }
    return 0;
}