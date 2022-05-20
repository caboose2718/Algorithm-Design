#include<iostream>
#include<algorithm>

#define INF ((unsigned) ~0)

using namespace std;

void printSolution(int **record, int i, int j)
{
    if(i == j)
        cout<<"M"<<i + 1;
    else
    {
        cout<<"(";
        printSolution(record, i, record[i][j]);
        printSolution(record, record[i][j] + 1, j);
        cout<<")";
    }
}

int main()
{
    int num;
    cout<<endl<<"Enter the number of matrices to multiply : ";
    cin>>num;

    int *dim = new int[num + 1];
    cout<<endl<<"Enter the dimensions of the matrices (m x n) : "<<endl<<endl;
    for(int i = 1; i <= num; i++)
    {
        int temp = dim[i - 1];
        cout<<"M"<<i<<" : ";
        cin>>dim[i - 1]>>dim[i];
        if(i > 1 && temp != dim[i - 1])
        {
            cout<<endl<<"Matrix "<<i<<" has invalid dimensions ! ";
            return(0);
        }
    }

    unsigned int **table = new unsigned int*[num];
    for(int i = 0; i < num; i++)
        table[i] = new unsigned int[num];

    for(int i = 0; i < num; i++)
        table[i][i] = 0;

    int **record = new int*[num];
    for(int i = 0; i < num; i++)
        record[i] = new int[num];

    for(int len = 2; len <= num; len++)
    {
        for(int i = 0; i <= num - len; i++)
        {
            int j = i + len - 1;
            table[i][j] = INF;
            for(int k = i; k < j; k++)
            {
                int cost = table[i][k] + table[k + 1][j] + dim[i]*dim[k + 1]*dim[j + 1];
                if(cost < table[i][j])
                {
                    table[i][j] = cost;
                    record[i][j] = k;
                }
            }
        }
    }

    cout<<endl<<"Optimal Parenthesization : ";
    printSolution(record, 0, num - 1);
    cout<<endl<<"Optimal Cost : "<<table[0][num - 1]<<" scalar multiplications."<<endl;

    for(int i = 0; i < num; i++)
    {
        delete table[i];
        delete record[i];
    }
    delete table;
    delete record;
    delete dim;

    return(0);
}