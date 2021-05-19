#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <memory>

using namespace std;

int main(int argc, char *argv[])
{

    //------------------------------------------------------------------------------------------------
    map<int, string> m;

    m[2] = "jelllove"s;
    m[3] = "ufo"s;
    m[4] = "free"s;


    
    //map using the find functionality
    auto it = m.find(2);

    if (it != m.end())
    {
        cout<<it->first<<":"<<it->second<<endl;
    }

    //using the public find functionality, and using the lamda
    auto it2 = find_if(m.begin(), m.end(), [](const pair<int, string> &a){return a.second == "ufo";});
    if (it2 != m.end())
    {
        cout<<it2->first<<":"<<it2->second<<endl;
    }

    //------------------------------------------------------------------------------------------------
    unordered_map<int, int> um;
    um.insert({3, 4});

    cout<<um[3]<<endl;


    //-------------------------------------------------------------------------------------------------
    


    return EXIT_SUCCESS;
}


