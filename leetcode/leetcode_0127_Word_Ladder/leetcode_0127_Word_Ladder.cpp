class Solution {
public:
    
    //function to check if 'a' is one character away from 'b'
    bool diff(string &a, string &b)
    {
        int count=0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i]) ++count;
        }
        return count==1 ? true : false;
    }
    
    int ladderLength(string word1, string word2, vector<string>& wordlist) {
        bool a = false;
        int answer=INT_MAX, n = wordlist.size(), c=0;
        map<string, vector<string>> adj;
        map<string, int> vis; 
        queue<string> q;
        string s;
        for(auto i : wordlist)
            if(i==word2)
            {
                a = true;
                break;
            }
        if(!a) return 0;
        
        //populate adjacent nodes for beginWord (a.k.a word1) 
        for(int i=0;i<n;i++)
            if(diff(wordlist[i], word1)==1)
                adj[word1].push_back(wordlist[i]);

        //populate adjacent nodes for words in wordList (a.k.a wordlist) 
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(diff(wordlist[i], wordlist[j])==1)
                {
                    adj[wordlist[i]].push_back(wordlist[j]);
                    adj[wordlist[j]].push_back(wordlist[i]);
                }
            }
        }
        
        //BFS algorithm
        //q.first = level number
        //q.second = adjacent node
        q.push(word1);
        while(!q.empty())
        {
            c++;
            int si = q.size();
            for(int j=0;j<si;j++)
            {
                s = q.front();
                q.pop();
                if(!vis[s])
                {
                    for(int i=0;i<adj[s].size();i++)
                    {
                        if(adj[s][i]==word2)
                            return c+1;
                        q.push(adj[s][i]);
                    }
                }
                vis[s]=1;
            }
        }
        return 0;
    }
};