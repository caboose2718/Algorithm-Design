#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class item
{
public:

    int value;
    int weight;
    int id; 
    double fraction;
    
    item(int x = 0, int y = 0, int z = 0, double f = 0)
    {
        value = x;
        weight = y;
        id = z;
        fraction = f;
    }
    bool operator < (const item& i)
    {
        return (double)value/weight < (double)i.value/i.weight;
    }
    friend ostream& operator<<(ostream & out, const item& a);
};

ostream& operator<<(ostream& out, const item& a)
{
    out<<"Item "<<a.id<<endl<<"Value : "<<a.value<<endl<<"Weight : "<<a.weight<<endl<<"Fraction Included : "<<a.fraction<<endl;
    return out;
}

double fractionalKnapsack(vector<item> &list, int capacity, int num)
{
    int currCapacity = 0;
    double total;

    for(int i = 0; i < num; i++)
    {
        if(currCapacity + list.at(i).weight <= capacity)
        {
            currCapacity = currCapacity + list.at(i).weight;
            total = total + list.at(i).value;
            list.at(i).fraction = 1; 
        }
        else
        {
            int left = capacity - currCapacity;
            double fraction = (double)left/list.at(i).weight;
            total = total + (double)list.at(i).value*fraction;
            list.at(i).fraction = fraction;
            break;
        }
    }
    return total;
}

int main()
{
    int num, weight, value, capacity;
    cout<<endl<<"Enter the capacity of the knapsack : ";
    cin>>capacity;
    cout<<endl<<"Enter the number of items : ";
    cin>>num;

    vector<item> list;
    cout<<endl<<"Enter the item information : "<<endl;
    for(int i = 0; i < num; i++)
    {
        cout<<endl<<"Value of Item "<<i + 1<<" : ";
        cin>>value;
        cout<<"Weight of Item "<<i + 1<<" : ";
        cin>>weight;
        list.push_back(item(value, weight, i + 1));
    }

    sort(list.rbegin(), list.rend());

    double total = fractionalKnapsack(list, capacity, num);

    cout<<endl<<"Items included in the knapsack : "<<endl<<endl;
    for(int i = 0; i < num; i++)
        cout<<list.at(i)<<endl;
    cout<<endl<<"Total Value : "<<total<<endl;
    
    return(0);
}