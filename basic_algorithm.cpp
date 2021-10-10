#include "include/public.h"

void helper(const char *fileName)
{

    unordered_map<string, int> hash;

    if (fileName == nullptr)
    {
        return;
    }

    ifstream ifile(fileName);
    if (ifile.good())
    {
        while (!ifile.eof())
        {
            string str;
            if (getline(ifile, str) && str.size() > 0)
            {
                size_t pos = str.find("(NSB");
                if (pos == string::npos)
                {
                    pos = str.find("(Nokia");
                }

                if (pos == string::npos)
                {
                    pos = str.find("(NSN");
                }

                if (pos == string::npos)
                {
                    continue;
                }

                size_t posEnd = str.find(")", pos);

                if (posEnd == string::npos)
                    continue;

                string name = str.substr(0, pos);
                name.erase(name.find_last_not_of(" \n\r\t") + 1);
		        name.erase(0, name.find_first_not_of(" \n\r\t"));

                if (name.size() <= 3)
                    continue;

                hash[name]++;
                //cout<<name<<endl;
                
            }
        }
    }

    ofstream ofile("output.txt");
    for (auto &i : hash)
    {
        ofile<<i.first<<"\t"<<i.second<<endl;
    }
    ofile.close();
} 

//(NSB
//(Nokia
//(NSN


int main(int argc, char *argv[])
{

    helper("mail.txt");
    

    return EXIT_SUCCESS;
}