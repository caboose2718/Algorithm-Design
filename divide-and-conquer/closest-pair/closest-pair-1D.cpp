#include<iostream>
#include<algorithm>
#include<vector>

#define INF ((unsigned) ~0)

using namespace std;

vector <int> x;
vector <int> y;

unsigned int minDistance = INF;

void storeMin(int *A, int adr)
{
    if(x.empty() && y.empty())
    {
        x.push_back(adr);
        y.push_back(adr + 1);       
    }
    else
    {
        if(abs(A[x.front()] - A[y.front()]) > minDistance)
        {
            x.clear();
            x.push_back(adr);
            y.clear();
            y.push_back(adr + 1);
        }
        else if(abs(A[x.front()] - A[y.front()]) == minDistance)
        {
            if(A[x.back()] != A[adr] && A[y.back()] != A[adr + 1])
            {
                x.push_back(adr);
                y.push_back(adr + 1);                
            }
        }
    }
}

void compareMid(int *A, int mid)
{
    if(abs(A[mid] - A[mid + 1]) <= minDistance)
    {
        minDistance = abs(A[mid] - A[mid + 1]);
        storeMin(A, mid);
    }
}

void closestPair(int *A, int left, int right)
{
    if(left >= right)
        return;
   
    int mid = (left + right)/2;
    closestPair(A, left, mid);
    closestPair(A, mid + 1, right);

    if(right = left + 1)
    {
        if(abs(A[left] - A[right]) <= minDistance)
        {
            minDistance = abs(A[left] - A[right]);
            storeMin(A, left);
        }
    }
    compareMid(A, mid);
}

int main()
{   
    int size;
    cout<<endl<<"Enter the number of inputs : ";
    cin>>size;

    if(size < 2)
    {
        cout<<endl<<"Insufficient Input ! "<<endl;
        return(0);
    }

    cout<<endl<<"Enter the distinct inputs : ";
    int *A = new int[size];
    for(int i = 0; i < size; i++)
        cin>>A[i];

    sort(A, A + size);

    closestPair(A, 0, size);
    
    cout<<endl<<endl<<"The closest pair of points are : ";
    for(int i = 0; i < x.size(); i++)
        cout<<"("<<A[x.at(i)]<<", "<<A[y.at(i)]<<") ";
    cout<<endl<<"The distance between the pair of points is : "<<minDistance<<endl<<endl;

    return(0);
}
