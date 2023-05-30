#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100];
    cout<<"enter the number of elements in the array";
    cin>>n;
    cout<<"Enter the array elements";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int i=0;
    int j=n-1;
    while(i<j)
    {
        swap(a[i],a[j]);
        i++;
        j--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
