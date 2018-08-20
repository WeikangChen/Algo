class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        const int N = nums.size();
        for (int j = 0, i = 0; i < N; ++i) {
            int cur = nums[i];
            while(!dq.empty() && dq.back() < cur) 
                dq.pop_back();
            dq.push_back(cur);
            if (i - j + 1 == k) { // when window size == i - j + 1 == k 
                res.push_back(dq.front());
                if (nums[j++] == dq.front())
                    dq.pop_front();
            }
        }
        return res;
    }
};
