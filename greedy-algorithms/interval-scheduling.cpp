#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class interval
{
public : 
    float start;
    float end;

    interval(float x = 0, float y = 0) : start{x}, end{y} {}

    bool operator<(const interval& i)
    {
        return end < i.end;
    }
    friend ostream& operator<<(ostream& out, const interval& a);   
};

ostream& operator<<(ostream& out, const interval& a)
{
    out<<"["<<a.start<<" - "<<a.end<<"]"<<endl;
    return out;
}

void scheduleInterval(vector<interval> &list, int num)
{
    auto i = list.begin();
    while(i+1 != list.end())
    {
        if((*(i+1)).start < (*i).end)
            list.erase(i+1);
        else
            i++;
    }
}

int main()
{
    int num;
    float start, end;
    cout<<endl<<"Enter the number of intervals : ";
    cin>>num;

    vector<interval> list;
    cout<<endl<<"Enter the interval information : "<<endl;
    for(int i = 0; i < num; i++)
    {
        cout<<endl<<"Interval "<<i + 1<<endl;
        cout<<"Start Time : ";
        cin>>start;
        cout<<"End Time : ";
        cin>>end;
        list.push_back(interval(start, end));
    }

    sort(list.begin(), list.end());

    scheduleInterval(list, num);

    cout<<endl<<"The intervals scheduled in the machine are : "<<endl<<endl;
    for(auto i = list.begin(); i < list.end(); i++)
        cout<<(*i)<<endl; 

    return(0);
}