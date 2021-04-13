#include "../../include/public.h"

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *genGraph(vector<vector<int>> vec)
{
    unordered_multimap<Node *, Node *> mpA;
    unordered_map<int, Node *> mp;
    for (int i = 0; i < vec.size(); ++i)
    {
        if (mp.count(vec[i][0]) <= 0)
        {
            mp[vec[i][0]] = new Node(vec[i][0]);
        }

        if (mp.count(vec[i][1]) <= 0)
        {
            mp[vec[i][1]] = new Node(vec[i][1]);
        }

        auto seek = mpA.find(mp[vec[i][0]]);
        bool bFound = false;
        if (seek != mpA.end())
        {
            for (auto it = seek->first; it != seek->second; ++it)
            {
                if (it == mp[vec[i][1]])
                {
                    bFound = true;
                    break;
                }
            }
        }

        if (!bFound)
        {
            mpA.insert({mp[vec[i][0]],mp[vec[i][1]]});
            mpA.insert({mp[vec[i][1]],mp[vec[i][0]]});
            mp[vec[i][0]]->neighbors.push_back(mp[vec[i][1]]);
            mp[vec[i][1]]->neighbors.push_back(mp[vec[i][0]]);
        }

        
    }

    return mp[vec[0][0]];
}

int main()
{

    vector<vector<int>> vec = {{2,4},{1,3},{2,4},{1,3}};
    Node *node = genGraph(vec);

    return 0;
}