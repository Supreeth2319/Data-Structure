//approach one using store and move elements
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a[100],b[100];
    cout<<"Enter the numberr of array elements";
    cin>>n;
    cout<<"ENter the array elements";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x,i=0,j=n-1;
    x=a[j];
   for(int i=n-1;i>0;i--)
   {
       a[i]=a[i-1];
   }
    a[0]=x;
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    
}

//approach 2 swap
//approach one using store and move elements
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a[100];
    cout<<"Enter the numberr of array elements";
    cin>>n;
    cout<<"ENter the array elements";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x,i=0,j=n-1;
    while(i!=j)
    {
        swap(a[i],a[j]);
        i++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
}
