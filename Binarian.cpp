#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int mass[10];
    int key_word;
    for (int i = 0; i<10; i++) //collecting array mass[10]
    {
        cin>>mass[i];
    }
    sort (mass, mass+10);
    cin>>key_word; //working with key word from the keyboard
    bool indicator = false; //include indicator

    int right = 9;
    int left = 0;
    int centre;
    
    while ((left<=right) && (indicator != true))
    {
        centre = (left+right)/2;
        if (mass[centre] == key_word)
        {
            indicator = true;
        }
        if (mass[centre] > key_word)
        {
            right = centre - 1;
        }
        else 
        {
            left = centre+1;
        }
    }

    if (indicator) 
    {
        cout<<centre;
    }
    else
    {
        cout<<"-1";
    }
    return 0;
}