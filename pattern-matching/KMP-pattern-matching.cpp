#include<iostream>
#include<vector>

using namespace std;

int* prefixTable(string pattern)
{
    int *fpattern = new int[(int)pattern.size()];
    for(int i = 0, j = 1; j < pattern.size(); j++)
    {
        while(i > 0 && pattern[i] != pattern[j])
            i = fpattern[i - 1];
        if(pattern[i] == pattern[j])
            i++;
        fpattern[j] = i;
    }
    return fpattern;
}

vector <int> patternFind(string search, string pattern, int* fpattern, int &count)
{
    vector <int> indices;
    int i = 0, j = 0;
    while(i < search.size())
    {
        if(search[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j != 0)
                j = fpattern[j - 1];
            else
                i++;
        }

        if(j == pattern.size())
        {
            count++;
            indices.push_back(i - j);
            j = fpattern[j - 1];
        }
    }
    return indices;
}

int main()
{   
    int count = 0;
    string search, pattern;
    cout<<endl<<"Enter the text to be searched : ";
    getline(cin, search);
    cout<<endl<<"Enter the pattern to search : ";
    getline(cin, pattern);

    int* fpattern = prefixTable(pattern);

    vector <int> indices = patternFind(search, pattern, fpattern, count);

    if(count)
    {
        cout<<endl<<"Total Match Found : "<<count;
        cout<<endl<<"Indices of the matches found : ";
        for(auto i = indices.begin(); i < indices.end(); i++)
            cout<<"["<<*i + 1<<", "<<(*i) + (int)pattern.size()<<"]  ";  
    }
    else
        cout<<endl<<"No Match Found !";

    return(0);    
}