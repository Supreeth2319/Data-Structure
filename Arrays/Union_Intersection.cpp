//Union of two sorted array
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
    cout<<"Enter the numberr of array elements";
    cin>>m;
    cout<<"ENter the array elements";
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(a[i]>b[j])
        {
            cout<<b[j];
            j++;
        }
        else if(a[i]<b[j])
        {
            cout<<a[i];
            i++;
        }
        else if(a[i]==b[j])
        {
            cout<<a[i];
            i++;
            j++;
        }
    }
    while(i<n)
    {
        cout<<a[i];
        i++;
    }
    while(j<m)
    {
        cout<<b[j];
        j++;
    }
    
}



//Intersection of two sorted arrays

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
    cout<<"Enter the numberr of array elements";
    cin>>m;
    cout<<"ENter the array elements";
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(a[i]>b[j])
        {
            j++;
        }
        else if(a[i]<b[j])
        {
            i++;
        }
        else if(a[i]==b[j])
        {
            cout<<a[i];
            i++;
            j++;
        }
    }
    
}
