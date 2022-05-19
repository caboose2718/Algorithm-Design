#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class item
{
public:

    int value;
    int weight;
    bool included;

    item(int x = 0, int y = 0) : value{x}, weight{y}, included{false}{}
    friend ostream& operator<<(ostream& out, const item& a); 
};

ostream& operator<<(ostream& out, const item& a)
{
    out<<endl<<"Value : "<<a.value<<endl<<"Weight : "<<a.weight<<endl<<"Included : "<<a.included<<endl;
    return out;
}

int main()
{
    int capacity, num, value, weight;
    cout<<endl<<"Enter the capacity of the knapsack : ";
    cin>>capacity;
    cout<<"Enter the number of items : ";
    cin>>num;
    
    vector<item> list;
    cout<<endl<<"Enter the item information : "<<endl;
    for(int i = 0; i < num; i++)
    {
        cout<<endl<<"Value of Item "<<i + 1<<" : ";
        cin>>value;
        cout<<"Weight of Item "<<i + 1<<" : ";
        cin>>weight;
        list.push_back(item(value, weight));
    }
    
    int **matrix = new int*[num + 1];
    for(int i = 0; i <= num; i++)
        matrix[i] = new int[capacity + 1];

    for(int i = 0; i <= num; i++)
        matrix[i][0] = 0;
    for(int i = 0; i <= capacity; i++)
        matrix[0][i] = 0;

    for(int i = 1; i <= num; i++)
        for(int j = 1; j <= capacity; j++)
        {
            if(list.at(i - 1).weight <= j)
                matrix[i][j] = max(matrix[i - 1][j], (matrix[i - 1][j - list.at(i - 1).weight] + list.at(i - 1).value));
            else
                matrix[i][j] = matrix[i - 1][j];
        }
    
    int i = num, j = capacity;


    while(i != 0 && j != 0)
    {
        if(matrix[i][j] == matrix[i - 1][j])
        {
            list.at(i - 1).included  = false;
            i--;
        }
            
        else if(matrix[i][j] == list.at(i - 1).value + matrix[i-1][j - list.at(i - 1).weight])
        {
            list.at(i - 1).included = true;
            j = j - list.at(i-1).weight;
            i--;
        }
        
    }

    cout<<endl<<"Items included in the knapsack : "<<endl<<endl;
    for(int i = 0; i < num; i++)
        cout<<endl<<"Item "<<i + 1<<list.at(i);
    cout<<endl<<"Total Value : "<<matrix[num][capacity]<<endl;

    return(0);
}