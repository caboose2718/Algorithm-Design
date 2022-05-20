#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int len;
    cout<<endl<<"Enter the length of the rod : ";
    cin>>len;
    cout<<endl<<"Enter the prices of each pieces : "<<endl<<endl;

    int *price = new int[len];
    for(int i = 0; i < len; i++)
    {
        cout<<"Length "<<i + 1<<" : ";
        cin>>price[i];
    }

    int *optimalprice = new int [len + 1];
    optimalprice[0] = 0;
    int *cut = new int [len];

    for(int i = 1; i <= len; i++)
    {   
        int costcurr = -1;
        for(int j = 1; j <= i; j++)
        {
            if(costcurr < price[j - 1] + optimalprice[i - j])
            {
                costcurr = price[j - 1] + optimalprice[i - j];
                cut[i - 1] = j;
            }
        }   
        optimalprice[i] = costcurr; 
    }
    cout<<endl<<"Optimal Decomposition : "<<endl<<endl;
    int i = len - 1;
    while(i > 0)
    {
        static int count = 1;
        cout<<"Piece "<<count<<endl;
        cout<<"Length : "<<cut[i]<<endl;
        cout<<"Price : "<<price[cut[i] - 1]<<endl<<endl;
        i = i - cut[i];
        count++;
    }
    cout<<"Optimal Price : "<<optimalprice[len]<<endl;

    delete price;
    delete optimalprice;
    delete cut;

    return(0);
}