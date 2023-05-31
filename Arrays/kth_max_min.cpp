// kth Maximum and minimum number in the array
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100],k;
    cout<<"enter the number of elements in the array";
    cin>>n;
    cout<<"enter k";
    cin>>k;
    cout<<"Enter the array elements";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<"kth largest number is"<<a[n-k]<<endl;
    cout<<"kth smallest number is"<<a[k-1];
}
