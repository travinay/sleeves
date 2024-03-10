#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int> V, string string)
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

int main()
{
    vector<int> data = {1,2,3,3,3,3};
    Print(data, ",");
}