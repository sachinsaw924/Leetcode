//approach 1

// this approach is taking O(n*n + nlogn) complexity
//  s.c O(n)
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int>chairOccupied(n,-1);
        int chairNumber  = times[targetFriend][0]; 
        sort(times.begin(),times.end());
        int ans = -1;
        for(auto vec : times)
        {
            int arrival = vec[0];
            int depart = vec[1];
            for(int i = 0 ; i<n;i++)
            {
                if(chairOccupied[i]<=arrival)
                {
                    chairOccupied[i] = depart;
                    if(arrival == chairNumber)
                    {
                        ans = i;
                    }
                    break;
                }

            }
        }


        return ans;

    }
};









class Solution {
public:
    typedef pair<int, int> P;

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n = times.size();
        priority_queue<P, vector<P>, greater<P> > occupied; //{departTime, chairNo}
        priority_queue<int, vector<int>, greater<int>> free; //min heap of unoccupied chairs
        
        int targetFriendArrival = times[targetFriend][0];
		
        //Sort based on arrival time
        sort(times.begin(),times.end());
        
		int chairNo = 0;

        for(int i = 0; i < n; i++) {
            int arrival  = times[i][0];
            int depart   = times[i][1];
            
            //free chairs accordingly
            while(!occupied.empty() && occupied.top().first <= arrival) {
                free.push(occupied.top().second); //this chair is now free
                occupied.pop();
            }

            if(free.empty()) {
                occupied.push({depart, chairNo});

                if(arrival == targetFriendArrival)
                    return chairNo;

                chairNo++;
            } else {
                int leastChairAvailable = free.top();
                free.pop();
                if(arrival == targetFriendArrival) {
                    return leastChairAvailable;
                }
                occupied.push({depart, leastChairAvailable});
            }
        }

        return -1;
    }
    
};
