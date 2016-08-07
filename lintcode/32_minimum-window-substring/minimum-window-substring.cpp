/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/minimum-window-substring
@Language: C++
@Datetime: 16-05-22 18:57
*/

class Solution {
public:
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        if (source.empty() || target.empty()) return "";
        const int m = source.size();
        int dict[256] = {0};
        int found[256] = {0};
        int tar_sum = target.size(), fnd_sum = 0;
        int min_pos = -1, min_len = INT_MAX;
        for (auto &c : target) dict[c]++;

        int l = 0, r = 0;
        while (r < m) {
            while (r < m && fnd_sum < tar_sum) {
                char c = source[r++];
                found[c]++;
                if (found[c] <= dict[c]) fnd_sum++;
            }

            if (fnd_sum < tar_sum) continue;

            while (fnd_sum >= tar_sum) {
                char c = source[l++];
                found[c]--;
                if (found[c] < dict[c]) fnd_sum--;
            }
            
            int cur_len = r - l + 1;
            if (cur_len < min_len) {
                min_pos = l - 1;
                min_len = cur_len;
            }
        }

        return min_pos == -1 ? "" : source.substr(min_pos, min_len);
    }
};
