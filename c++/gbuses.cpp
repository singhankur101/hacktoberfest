#include <bits/stdc++.h>
using namespace std;

void func(vector <int> left, vector <int> right, int n, vector <int> &values)
{
    sort(left.begin(), left.end());
    sort(right.begin(),right.end());
    int i=0,j=0, val=0;
    for(int timer=left[0] ; timer<=right[n-1] ; timer++)
    {
        while(i<left.size() && left[i] == timer)
        {
            val++;
            i++;
        }
        while(j<right.size() && right[j] < timer)
        {
            val--;
            j++;
        }
        values[timer]=val;
    }
}

int main()
{
    int t=0,k=0;
    cin>>k;
    while(t<k)
    {
        int n;
        cin>>n;
        vector <int> left(n), right(n), values(5001,0);
        for(int i=0 ; i<n ; i++)
        {
            cin>>left[i]>>right[i];
        }
        func(left, right, n, values);
        int p;
        cin>>p;
        vector <int> querry(p);
        for(int i=0 ; i<p ; i++)
        {
            cin>>querry[i];
        }
        cout<<"Case #"<<t+1<<": ";
        for(int i=0 ; i<p ; i++)
        {
            cout<<values[querry[i]]<<" ";
        }
        cout<<endl;
        t++;
    }
    return 0;
}