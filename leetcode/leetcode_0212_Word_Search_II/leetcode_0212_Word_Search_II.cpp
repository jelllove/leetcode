//Method 1: using the dfs + trie
/*

class Trie {

private:
    Trie* next[256] = {nullptr};//因为char的范围是0-255
    bool isEnd = false;
    bool hasGot = false;
    
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie *root = (Trie *)this;
        
        for (auto &c : word)
        {
            if (root->next[c] == nullptr)
                root->next[c] = new Trie();
            root = root->next[c];
        }
        
        root->isEnd = true;
    }
    
    bool search(string word) {
        Trie *root = (Trie *)this;
        
        for (auto &c : word)
        {
            if (root->next[c] == nullptr)
                return false;
            root = root->next[c];
        }
        
        if (!root->isEnd)
        {
            return false;
        }
        else
        {
            if (root->hasGot)
                return false;
            else
            {
                root->hasGot = true;
                return true;
            }
        }
        
    }
    
    bool startsWith(string prefix) {
        Trie *root = (Trie *)this;
        
        for (auto &c : prefix)
        {
            if (root->next[c] == nullptr)
                return false;
            root = root->next[c];
        }
        
        return true;
    }
    
};



class Solution {
private:
    Trie dictTree;
public:
    void dfs(int i, int j, vector<vector<char>>& board, string &str, vector<vector<bool>> &visited, int maxLen, vector<string> &ans)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j])
            return;
        
        visited[i][j] = true;
        str.push_back(board[i][j]);
        
        if (str.size() > maxLen || !dictTree.startsWith(str))
        {
            str.pop_back();
            visited[i][j] = false;
            return;
        }
        
        if (dictTree.search(str))
            ans.push_back(str);
        
        dfs(i + 1, j, board, str, visited, maxLen, ans);
        dfs(i, j + 1, board, str, visited, maxLen, ans);
        dfs(i - 1, j, board, str, visited, maxLen, ans);
        dfs(i, j - 1, board, str, visited, maxLen, ans);
        
        
        str.pop_back();
        
        visited[i][j] = false;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        if (words.size() == 0 || board.size() == 0 || board[0].size() == 0)
            return {};
        
        for (auto &w : words)
            dictTree.insert(w);
        
        sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() > b.size();});
        int maxLen = words[0].size();
        
        
        
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        string str = "";
        
        vector<string> ans;
        
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                dfs(i, j, board, str, visited, maxLen, ans);
            }
        }
        
        
        
        return ans;
        
    }
};
*/

class Solution {
public:
    
    vector<vector<int>> direction = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    
    
    bool seekWord(vector<vector<char>>& board, int i, int j, vector<vector<bool>> &visited, string &searchWord, int index)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        
        if (index >= searchWord.size())
            return false;
        
        if (visited[i][j])
            return false;
        
        if (board[i][j] == searchWord[index])
        {
            if (index == searchWord.size() - 1)
                return true;
            
            visited[i][j] = true;
            
            for (auto &direct : direction)
            {
                if (seekWord(board, i + direct[0], j + direct[1], visited, searchWord, index + 1))
                {   
                    return true;
                }
                
            }
            
            visited[i][j] = false;
            
        }
        return false;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        vector<string> res;
        
        vector<string> tmpWords = words;
        
        if (board.size() == 0 || board[0].size() == 0 || words.size() == 0)
            return res;
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                
                
                for (int m = tmpWords.size() - 1; m >= 0; m--)
                {
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                    
                    if (seekWord(board, i, j, visited, tmpWords[m], 0))
                    {
                        res.push_back(tmpWords[m]);
                        tmpWords.erase(tmpWords.begin() + m);
                    }
                }
            }
        }
        
        
        return res;
        
    }
};