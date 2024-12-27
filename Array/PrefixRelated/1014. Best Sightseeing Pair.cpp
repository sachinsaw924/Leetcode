class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int  n = values.size();
        vector<int>result(n,0);
        result[0] = values[0] + 0 ;

        for(int i= 1 ; i < n ;i++)
        {
            result[i] = max(values[i]+i,result[i-1] );
        }

        int maxi = INT_MIN;


        for(int j = 1 ; j < n ; j++)
        {
            int x = values[j]-j;
            int y = result[j-1];

           maxi = max(maxi, x+y);

        }
        return maxi ;
    }
};











class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxval = INT_MIN; 
        int maxi = INT_MIN ;

        for(int i = 1 ; i < n ; i++)
        {   int x = values[i-1] + i-1 ;
                if(x>maxval)
               {
                maxval  = x ; 
               }
               int y = values[i]-i;

               maxi = max(maxi,maxval+y);
        }
        return maxi ;
    }
}; 












class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxi = INT_MIN;
        priority_queue<int>pq;
        pq.push(values[0] );

        for(int i = 1 ; i< n ; i++)
        {   if(!pq.empty())
          {
             maxi = max(pq.top()+values[i]- i, maxi);
          }
          pq.push(values[i]+i);
             
        }
        return maxi ;
    }
};
