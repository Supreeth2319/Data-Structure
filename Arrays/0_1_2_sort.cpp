// given the array of zero one and two sort the array without any sorting algorithm
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100],cnt0=0,cnt1=0,cnt2=0;
    cout<<"enter the number of elements in the array";
    cin>>n;
    cout<<"Enter the array elements";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            cnt0++;
        }
        else if(a[i]==1)
        {
            cnt1++;
        }
        else {
            cnt2++;
        }
    }
    int i=0;
    while(cnt0>0)
    {
        a[i]=0;
        i++;
        cnt0--;
    }
    while(cnt1>0)
    {
        a[i]=1;
        i++;
        cnt1--;
    }
    while(cnt2>0)
    {
        a[i]=2;
        i++;
        cnt2--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
}
