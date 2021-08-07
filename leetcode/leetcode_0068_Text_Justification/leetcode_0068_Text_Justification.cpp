class Solution {
public:
    string justifyString(vector<string>& words, int counter, int left, int right, int maxWidth) {
        int wordCount = right - left;
        
        if (wordCount == 1) {
            string spaces(maxWidth - words[left].size(), ' ');
            return words[left] + spaces;
        }

        int spaceCount = wordCount - 1;
        int spaceLen = maxWidth - counter;
        int eachSpace = spaceLen/spaceCount;
        int remainderSpace = spaceLen%spaceCount;
        
        string out = words[left];
        
        for (int i = left + 1; i < right; ++i) {
            string spaces(remainderSpace > 0 ? 1 + eachSpace : eachSpace, ' ');
            out += spaces + words[i];
            remainderSpace--;
        }

        return out;
    }
    
    string leftJustify(vector<string>& words, int left, int right, int maxWidth) {
        string out = words[left];
        
        for (int i = left + 1; i < right; ++i) {
            out += ' ' + words[i];
        }
        
        string spaces(maxWidth - out.size(), ' ');
        
        return out + spaces;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> out;
        int left = 0, right = 0;
        int counter = 0;

        while (right < words.size()) {
            string word = words[right];
            
            if (counter + (right - left) + word.size() > maxWidth){
                out.push_back(justifyString(words, counter, left, right, maxWidth));
                left = right;
                counter = 0;
            }
            
            counter += word.size();
            right++;
        }
        
        out.push_back(leftJustify(words, left, right, maxWidth));
        
        return out;
    }
};