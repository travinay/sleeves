#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std;

int func(int *mas)
{
    int index = mas[0];
    for (int i = 0; i<10; i++ )
    {
        if (mas[i]>index)
        {
            index = mas[i];
        }
    }
    this_thread::sleep_for(chrono::seconds(2));
    return index;

}

int main()
{
    int *mas1 = new int[10];
    int *mas2 = new int[10];
    int *mas3 = new int[10];
    for (int i = 0; i < 10; i++)
    {
        mas1[i] = rand()%100;
    }
    for (int i = 0; i < 10; i++)
    {
        mas2[i] = rand()%100;
    }
    for (int i = 0; i < 10; i++)
    {
        mas3[i] = rand()%100;
    }
    auto t1  = async(func, mas1);
    auto t2  = async(func, mas2);
    auto t3  = async(func, mas3);
    int sum = t1.get() + t2.get() +t3.get();
    cout<<sum;
    return 0;
}