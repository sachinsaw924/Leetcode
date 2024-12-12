


class Solution {
public:
typedef long long ll;
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<ll>pq;
        int n = gifts.size();

        for(int i = 0 ; i  < n;  i++)
        {
            pq.push(gifts[i]);
        }


        while(k>0)
        {
            int top = pq.top();
            pq.pop() ;
            int ans = sqrt(top);
             
            pq.push(ans);
              

              k--;
        }
         ll sum = 0 ; 
        while(!pq.empty())
        { 
            cout << pq.top()<<endl;
            sum +=pq.top();
            pq.pop();
        }
        return sum ;
    }
};
