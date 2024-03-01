#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int Factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    int factorial = 1;
    for (int i = 1; i <= num; i++)
    {
        int split = factorial*i;
        factorial = split;
    }
    return factorial;
}

int main()
{
    int leng;
    cin>>leng;
    vector<int> N;
    int n;
    for(int i = 0; i < leng; i++) {
        cin >> n; //строку вводить так: каждое число через пробел
        N.push_back(n);
    }

    int Fin_number=0;
    for (int i = 0; i<leng; i++)
    {
        Fin_number +=  N[i]*(Factorial(leng - i));
    }
    cout<<Fin_number;
}