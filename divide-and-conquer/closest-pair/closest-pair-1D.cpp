#include<iostream>
#include<algorithm>

#define INF ((unsigned) ~0)

using namespace std;

int x, y;
unsigned int minDistance = INF;

void compareMid(int *A, int mid)
{
    if(abs(A[mid] - A[mid + 1]) < minDistance)
    {
        minDistance = abs(A[mid] - A[mid + 1]);
        x = mid;
        y = mid + 1;
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
        if(abs(A[left] - A[right]) < minDistance)
        {
            minDistance = abs(A[left] - A[right]);
            x = left;
            y = right;
        }
    }
    compareMid(A, mid);
}

int main()
{   
    int size;
    cout<<endl<<"Enter the number of inputs : ";
    cin>>size;

    cout<<endl<<"Enter the distinct inputs : ";
    int *A = new int[size];
    for(int i = 0; i < size; i++)
        cin>>A[i];

    sort(A, A + size);

    closestPair(A, 0, size);

    cout<<endl<<"The closest pair of points are : ("<<A[x]<<", "<<A[y]<<")"<<endl;
    cout<<endl<<"The distance between the pair of points is : "<<minDistance<<endl<<endl;

    system("pause");
    return(0);
}
