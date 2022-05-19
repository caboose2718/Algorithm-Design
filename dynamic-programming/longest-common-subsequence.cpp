#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    string s1, s2;
    cout<<endl<<"Enter the first sequence : ";
    getline(cin, s1);
    cout<<"Enter the second sequence : ";
    getline(cin, s2);

    int **table = new int*[s1.length() + 1];
    for(int i = 0; i <= s1.length(); i++)
        table[i] = new int[s2.length() + 1];
    
    for(int i = 0; i <= s1.length(); i++)
        table[i][0] = 0;
    for(int i = 0; i <= s2.length(); i++)
        table[0][i] = 0;

    for(int i = 1; i <= s1.length(); i++)
    {
        for(int j = 1; j <= s2.length(); j++)
        {
            if(s1[i - 1] == s2[j - 1])
                table[i][j] = 1 + table[i - 1][j - 1];
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }
    
    int i = s1.length();
    int j = s2.length();
    string lcs;

    while(i != 0 && j != 0)
    {
        if(table[i][j] != table[i - 1][j] && table[i][j] != table[i][j-1])
        {
            lcs.insert(0,1,s1[i - 1]);
            i--;
            j--;
        }
        else if(table[i][j] == table[i][j - 1])
            j--;
        else if(table[i][j] == table[i - 1][j])
            i--;
    }

    cout<<endl<<"Longest Common Subsequence : "<<lcs;
    cout<<endl<<"Length of the longest common subsequence : "<<table[s1.length()][s2.length()]<<endl;

    for(int i = 0; i <= s1.length(); i++)
        delete table[i];
    delete table;

    return(0);
}