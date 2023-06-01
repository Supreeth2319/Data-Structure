//kadans algorithm to find maximum subarray sum
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
   int max_till_now=0,max_sum=0;
   for(int i=0;i<n;i++)
   {
       max_till_now=max_till_now+a[i];
       if(max_till_now<0)
       {
           max_till_now=0;
       }
        if(max_sum<max_till_now)
       {
           max_sum=max_till_now;
       }
   }
   cout<< max_sum;
}
