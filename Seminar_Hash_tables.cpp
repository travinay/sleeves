#include <iostream>
#include <unordered_map>
using namespace std;
//фукнция с unordered_map
/*int main()
{
    int n;
    cin>>n;
    unordered_map<string, int>mappy;
 
    for (int i=0; i<n; i++)
    {
        string fair;
        cin>>fair;
        mappy.insert(pair<string, int>(fair, i));
    }
    for (auto& item : mappy)
    {
         cout << item.first << " " << item.second << endl;
    }

}*/
class Hashing_Table //создала класс с индексом и словом
{
public:
    int limit;
    void Finder(int length, string S);
    string word;
    Hashing_Table(int n, string strong)
    {
        limit = n;
        word = strong;
    }
    void print( )
    {
        cout<<limit<<" "<<word<<endl;
    }

};
int main()
{
    int length;
    cin>>length;
    int mass[length];
    string word_mass[length];
    for (int i = 0; i<length; i++)
    {
        int num;
        mass[i] = i;
    }
    for (int i = 0; i<length; i++)
    {
        string fair;
        cin>>fair;
        for (int j=0; j<i; j++)
        {
            if (fair==word_mass[j])
            {
                word_mass[j] = fair;

            }
            else
            {
                word_mass[i] = fair;
                break;
            }

        }
    }

    for (int i = 0; i<length; i++)
    {
        int num = i;
        Hashing_Table Tability(mass[i], word_mass[i]);
        Tability.print();
    }
    string find_word;
    find_word == "key";
    for (int i = 0; i<length; i++)
    {
        int num = i;
        Hashing_Table Tability(mass[i], word_mass[i]);
        if (word_mass[i] == find_word)
        {
            cout<<mass[i];
        }
    }
}
