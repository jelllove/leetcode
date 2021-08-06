class Solution {
public:
    
    bool parseLog(string &log, int &id, string &operation, int &time)
    {
        size_t pos = log.find(":");
        if (pos == string::npos)
            return false;
        
        id = stoi(log.substr(0, pos));
        
        size_t pos2 = log.find(":", pos + 1);
        if (pos2 == string::npos)
            return false;
        
        operation = log.substr(pos + 1, pos2 - pos - 1);
        
        time = stoi(log.substr(pos2 + 1, log.size() - pos2 - 1));
        
        return true;
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        if (n <= 0 || logs.size() == 0)
            return {};
        
        vector<int> processTime(n, 0);
        stack<int> idStack;
        int preTime = 0;
        for (auto &l : logs)
        {
            int id = 0;
            string operation = "";
            int startTime = 0;
            
            parseLog(l, id, operation, startTime);
            
            if (idStack.empty())
            {
                idStack.push(id);
            }
            else
            {
                
                if (operation == "start")
                {
                    processTime[idStack.top()] += (startTime - preTime);
                    preTime = startTime;
                    idStack.push(id);
                }    
                else
                {
                    processTime[idStack.top()] += (startTime - preTime + 1);
                    preTime = startTime + 1;
                    idStack.pop();
                }
            }
        }
        
        return processTime;
    }
};