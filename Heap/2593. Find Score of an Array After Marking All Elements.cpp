 Time Complexity : O(nlogN)
 Space Complexity : O(n)


class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> p;

        bool
        solve(vector<int>& nums, ll top, ll i) {
        int n = nums.size();

        if (nums[i] == top) {
            nums[i] = 0;
            if (i == 0) {

                nums[i + 1] = 0;
            } else if (i == n - 1) {

                nums[i - 1] = 0;
            } else {

                nums[i - 1] = 0;
                nums[i + 1] = 0;
            }
            return true;
        }

        return false;
    }
    long long findScore(vector<int>& nums) {
        priority_queue<p, vector<p>, greater<p>> pq;

        int n = nums.size();
        if (n == 1)
            return nums[0];

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        ll sum = 0;

        while (!pq.empty()) {
            ll top = pq.top().first;
            ll index = pq.top().second;
            pq.pop();

            if (solve(nums, top, index)) {

                sum += top;
            }
        }
        return sum;
    }
};
