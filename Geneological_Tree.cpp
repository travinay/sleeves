#include <iostream>
#include <map>
#include <cstring>
#include <string>

using namespace std;

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
    map<string, int> Gen_tree{};
    int quantity=8;
    char namesline[30];
    string names[2];
    for (int i=0; i<quantity; i++)
    {
        cin.getline(namesline, 30);
        char* pch = strtok(namesline, " .,-");
        int j = 0;
        while (pch != NULL)
        {
            names[j] = pch;
            pch = strtok(NULL, " ,.-");
            j++;
        }
        string child_name = names[0];
        string parent_name = names[1];
        if (Gen_tree.contains(parent_name))
        {
            Gen_tree[child_name] = Gen_tree[parent_name]+1;
        }
        else
        {
            Gen_tree[parent_name]= 0;
            Gen_tree[child_name]= 1;

        }
    }
    Print_map(Gen_tree);
    return 0;
}
