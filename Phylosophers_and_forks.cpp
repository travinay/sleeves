#include <iostream>
#include <thread>
#include <mutex>
#include "windows.h"

using namespace std;

thread threads[5]; //поточные филоСОФЫ
mutex regural_fork[5]; //вилочки (с мьютаксами)
mutex fork_lock;//мьютакс блочит вилки
 
 
bool Getting_fork(int left, int right) 
{
    if (regural_fork[left].try_lock()) {
        if (regural_fork[right].try_lock()) {
            return true;
        }
        else {
            regural_fork[left].unlock();
        }
    }
    return false;
}
 
void Leave_fork(int left, int right) 
{
    regural_fork[left].unlock();
    regural_fork[right].unlock();
}
 
void run(int philisopher) 
{
    int right = philisopher%4;
    int left = philisopher - 1;
    while (true) {
        if (Getting_fork(left, right)) 
        {
            fork_lock.lock();
            cout << "Философ " << philisopher << " кушает"<<endl;
            fork_lock.unlock();
 
            Sleep(100);
            Leave_fork(left, right);
        }
        else 
        {
            fork_lock.lock();
            cout << "Философ " << philisopher << " думает"<<endl;
            fork_lock.unlock();
            Sleep(100);
        }
    }
}
int main() 
{
    for (int i = 1; i <= 5; i++) 
    {
        threads[i - 1] = thread(run, i);
 
    }

    for (int i = 1; i <= 5; i++) 
    {
            threads[i - 1].join();
    }

    return 0;
}