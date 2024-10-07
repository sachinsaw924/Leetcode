

/// testcase : 2
// no of input : 5
// 1 2 1 5 2 
// output : 7 
// logic to samjh hi jayega
// Minimum Gifts


#include <bits/stdc++.h>
using namespace std;


int main() {
  int t ;
  cin>>t;
   
  while(t--)
  {  
   int    count = 1 ;
      int n ;
      cin>>n;
      int arr[n];
     for(int i = 0;i<n;i++) cin>>arr[i];
     
     
     for(int i = 1 ;i<n;i++)
     {
         if(arr[i]>arr[i-1])
         {
             count = count + 2;
         }
         else if(arr[i]<=arr[i-1])
         {
             count = count + 1;
         }
     }
     cout<<count<<endl;
     
      
  }
   

    return 0;
}
