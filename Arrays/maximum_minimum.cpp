//Maximum and minimum number in the array
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
    sort(a,a+n);
    cout<<a[0]<<endl;
    cout<<a[n-1];
}


//Maximum and minimum number in the array without sorting
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100],min=999,max=0;
    cout<<"enter the number of elements in the array";
    cin>>n;
    cout<<"Enter the array elements";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
    
        if(a[i]>max)
        {
            max=a[i];
        }
       
    }
      for(int i=0;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    cout<<max<<min;
}
