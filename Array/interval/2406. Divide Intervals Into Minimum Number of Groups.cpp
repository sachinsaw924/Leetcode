
// Revision mark : 0
// always sort the interval based problem 
// may be some time look for use of max heap or min heap 
// second thing which I mistake had done not approaching the problem in good way like not ananlysing 
// third thing always draw the diagram 
// here i had done overlapping region which is not ideal way of solution 
// bhaii easy tha banna chayie tha 
// T.c O(n)


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals),end(intervals));
        priority_queue<int,vector<int>,greater<int>>que;
        for(int i = 0;i<n;i++)
        {
            if(!que.empty() && intervals[i][0]>que.top())
            {
                que.pop();
            }
            que.push(intervals[i][1]);
        }
        return que.size();
    }
};






/// how to sort based on ending points 
// Sort intervals by their end points
sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1]; // Compare based on the end points (second value of each interval)
});

