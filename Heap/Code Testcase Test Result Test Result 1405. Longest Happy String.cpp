//dekh maine bhut socha pr maine dono use kiya maxHeap or minHeap dono starting me mere se nhi hua 
// bad mughe ye samjh nhi aaya ki last ke do element ko kaise compare krenge wanha logic me glti hua hai 
// bad me maine solution dekha tab samjh aaya isko ek bar wapas revise krna parega improve tu hua
// T.c O(a+b+c * log3 )
// a.c O(3) 

class Solution {
public:
    typedef pair<int, char> p;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<p, vector<p>> pq;

        if (a > 0) {
            pq.push({a, 'a'});
        }

        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }
        string result = "";

        while (!pq.empty()) {
            int currCount = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();
            if (result.length() >= 2 &&
                result[result.length() - 1] == currChar &&
                result[result.length() - 2] == currChar) {

                    if(pq.empty())  {break;};

                int nextCount = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();
                result.push_back({nextChar});
                nextCount--;

                if (nextCount > 0)
                    pq.push({nextCount, nextChar});
            } else {
                currCount--;
                result.push_back(currChar);
            }
            if (currCount > 0)
                pq.push({currCount, currChar});
        }
        return result;
    }
};
