#include <iostream>
#include <list>
using namespace std;

void Print(list<int> V, string string)
{
    for (auto& item: V)
    {
        if (&item == &V.back())
        {
            cout<<item;
        }
        else
        {
            cout<<item<<string;
        }
    }
    cout<<"\n";
}

void Check_Print (list<int> List)
{
    list<int> numbers_positive = {};
    list<int> numbers_negative = {};
    for (auto &item: List)
    {
        if (item>=0)
        {
        numbers_positive.push_back(item);

        }
        
        else
        {
        numbers_negative.push_back(item);
        }
    }
    numbers_positive.sort();
    numbers_negative.sort();
    Print(numbers_positive, ",");
    Print(numbers_negative, ",");
}

int main()
{
    list<int> numbers = {1,2,3,4,5,-1,-2,-2,-3, 5, 8, -100};
    Check_Print(numbers);
}