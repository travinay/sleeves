#include <iostream>
using namespace std;

int Square_func(int num)
{
    int a = num/100;
    int b = (num%100 - num%10)/10;
    int c = num%10;
    return (a*a + b*b + c*c);
}

int Checking_Happiness(int num)
{
    if (num == 1)
    {
        cout<<"Happy number";
    }
    if (num == 37)
    {
        cout<<"Unhappy number";
    }
    return 0;
}
int main()
{
    int main_number;
    cin>>main_number;

    do
    {
        int num = Square_func(main_number);
        cout<<num<<" ";
        Checking_Happiness(num);
        main_number = num;
    } while (main_number != 1 && main_number != 37 );
    return 0;
}

