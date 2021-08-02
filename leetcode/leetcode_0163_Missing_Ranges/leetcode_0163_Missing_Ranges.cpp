
void fillData(vector<string> &ans, int first, int second)
{
    if (first == second)
    {
        ans.push_back(to_string(first));
    }
    else
    {
        ans.push_back(to_string(first) + "->"s + to_string(second));
    }
}

vector<string> helper(vector<int> &data, int lower, int upper)
{
    int l = lower;
    
    vector<string> ans;
    int r = 0;
    for (; r < data.size(); ++r)
    {
        if (r == 0)
        {
            if (data[r] > l)
            {
                fillData(ans, l, data[r] - 1);
            }
        }
        else
        {
            if (data[r] - l > 1)
            {
                fillData(ans, l + 1, data[r] - 1);
            }
        }
        l = data[r];
    }

    if (upper - l >= 1)
    {
        fillData(ans, l + 1, upper);
    }

    return ans;
}

