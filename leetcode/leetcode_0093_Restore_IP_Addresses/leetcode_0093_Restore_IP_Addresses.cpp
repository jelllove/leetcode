class Solution {
public:
    
void ip_dfs(vector<string> &retVector, string leftString, int field, string strCurrentIP)
{

	//如果长度以已经不够
	if (leftString.length() > 3 * (4 - field))
	{
		return;
	}

	if (field == 4 && leftString == "")
	{
		retVector.push_back(strCurrentIP);
		return;
	}

	
	//Fetch 1 byte
	if (leftString.length() < 1)
	{
		return;
	}

	string strSubIP = leftString.substr(0, 1);
	string strLeftSub = leftString.substr(1, leftString.length() - 1);
	string strTmpIP = strCurrentIP;
	if (field != 0)
	{
		strTmpIP += ".";
	}
	strTmpIP += strSubIP;

	ip_dfs(retVector, strLeftSub, field + 1, strTmpIP);



	//Fetch 2 byte
	if (leftString.length() < 2)
	{
		return;
	}
	if (leftString[0] == '0')
		return;

	strSubIP = leftString.substr(0, 2);
	strLeftSub = leftString.substr(2, leftString.length() - 2);
	strTmpIP = strCurrentIP;
	if (field != 0)
	{
		strTmpIP += ".";
	}
	strTmpIP += strSubIP;

	ip_dfs(retVector, strLeftSub, field + 1, strTmpIP);


	//Fetch 3 byte
	if (leftString.length() < 3)
	{
		return;
	}
	if (leftString[0] == '0')
		return;

	strSubIP = leftString.substr(0, 3);
	if (atoi(strSubIP.c_str()) > 255)
		return;
	strLeftSub = leftString.substr(3, leftString.length() - 2);
	strTmpIP = strCurrentIP;
	if (field != 0)
	{
		strTmpIP += ".";
	}
	strTmpIP += strSubIP;

	ip_dfs(retVector, strLeftSub, field + 1, strTmpIP);

}
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> retVector;
	    string strCurrentIP = "";

	    ip_dfs(retVector, s, 0, strCurrentIP);
        return retVector;
    }
};