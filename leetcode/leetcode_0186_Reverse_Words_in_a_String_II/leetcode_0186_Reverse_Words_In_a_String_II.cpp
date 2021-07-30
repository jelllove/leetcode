
void reverseWords(vector<char> &str) 
{
    if (str.size() <= 1)
        return;

    reverse(str.begin(), str.end());

    int left = -1;
    int right = -1;

    while (++right < str.size())
    {
        if (isalpha(str[right]))
        {
            if (left == -1)
                left = right;
        }
        else
        {
            if (left != -1)
            {
                reverse(str.begin() + left, str.begin() + right);
                left = -1;
            }
        }
        
    }

    if (left != -1)
    {
        reverse(str.begin() + left, str.begin() + right - 1);
    }
}
