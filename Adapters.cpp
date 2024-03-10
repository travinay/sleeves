#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main ()
{
    char skobki[] = "([])}[]";
    deque<char> Whore_House = {};
    for (auto item:skobki)
    {
        if (item == '\0')
            continue;
        if (item=='(' || item=='[' || item=='{')
        {
            Whore_House.push_back(item);
        }
        else if (Whore_House.empty())
        {
            Whore_House.push_back('e');
            break;
        }
        else if (Whore_House.back() == '(' && item ==')')
                {
                    Whore_House.pop_back();
                }
        else if (Whore_House.back() == '[' && item ==']')
                {
                    Whore_House.pop_back();
                }
        else if (Whore_House.back() == '{' && item =='}')
                {
                    Whore_House.pop_back();
                }
        /*for (auto i : Whore_House) {
            cout << i;
        }
        cout << "\n";*/
    }
    if (Whore_House.empty())
    {
        cout<<"Nice string bro"<<endl;
    }
    else
    {
        cout<<"Wrong string";
    }
}