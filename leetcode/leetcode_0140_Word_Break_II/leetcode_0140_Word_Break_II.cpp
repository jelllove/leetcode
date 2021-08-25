class Solution {
public:

	unordered_set<string> S;

	void dfs(vector<string> &ans, string wsf, int x, string s)
	{
		if(x >= s.length()){
			wsf.pop_back();
			cout << wsf << endl;
			ans.push_back(wsf);

			return;
		}


		for(int i=x; i<=s.length()-1; i++){

			string word = s.substr(x, i-x+1);
			if(S.find(word) != S.end()){
				int len = wsf.length();
				wsf += word;
				wsf += " ";
				dfs(ans, wsf, i+1, s);
				wsf.erase(len, word.length()+1);

			}
		}

	}

	vector<string> wordBreak(string s, vector<string>& wordDict) {

		vector<string> ans;

		int n = wordDict.size();
		for(int i=0; i<n; i++){
			S.insert(wordDict[i]);
		}

		string empty = "";
		dfs(ans, empty, 0, s);

		return ans;

	}
};