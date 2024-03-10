#include <iostream>
#include <set>
#include <list>
#include <cstring>
#include <map>

using namespace std;

void Print(list<string> V, string string)
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

void Print_map(map<string, int> V)
{
    for(auto iter{V.begin()}; iter != V.end(); iter++)
    {

        cout << iter->first << "\t" << iter->second << endl;
    }

    cout<<"\n";
}

int main()
{
    ///set<string> check_words = {};
    map<string, int> Counter_words{};
    int index = 1;
    string index_word;
    list<string> text = {};
    char str[] = "здесь мог бы быть ваш текст, но это всего лишь текст для проверки программы здесь";
    char *pch  = strtok (str, " .,-");
     while (pch != NULL)
    {
        ///check_words.insert(pch);
        string word = pch;
        if (Counter_words.contains(word))
        {
            Counter_words[word]++;
            if (index<Counter_words[word])
            {
                index = Counter_words[word];
                index_word = word;
            }
        }
        else
        {
            Counter_words[word] = 1;
        }
        text.push_back(pch);
        pch = strtok (NULL, " ,.-");
    }

    list<string> Sorting = {};
    for(auto iter{Counter_words.begin()}; iter != Counter_words.end(); iter++)
    {
        if (iter->second == index)
        {
            Sorting.push_back(iter->first);
        }
        Sorting.sort();
    }

    cout<<Sorting.front()<<"\n";
  return 0;  
}
