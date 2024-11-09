

// only passed some test cases  656/765
// time complexity O(n)
// it is working for reasonably  for very small values

class Solution {
public:
    typedef long long ll;
    long long minEnd(int n, int x) {
        int count = 1;
       ll k = x;
       int lastElement = 0 ;

       while(count<=n)
       {
          if((x & k) == x)
          {
            lastElement = k;
            count++;
          }
          k++;
       }
       return lastElement;
    }
};


class Solution {
public:
    long long minEnd(int n, int x) {

       long long num = x;
       for(int i = 1 ;i<n;i++)
       {
        num = (num+1)|x;
       }
       return num;
    }
};
