#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    vector<int> id;
    vector<int> size;
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        const int n = nums.size();
        size = vector<int>(n, 1);
        for (int i = 0; i < n; ++i)
            id.push_back(i);
            
        unordered_map<int, int> index;    
        for (int i = 0; i< n; ++i) {
            int cur = nums[i];
            cout << "index size = " << index.size() << endl;
            cout << "id[1] = " << id[1] << endl;
            if (index.find(cur) != index.end()) 
                continue;
            index[cur] = i;
            if (index.find(cur-1) != index.end())
                Union(i, index[cur-1]);
            if (index.find(cur+1) != index.end())
                Union(i, index[cur+1]);          
        }
        return *max_element(size.begin(), size.end());
    }
    
    int find(int p) {
        if (id[p] != p)
            id[p] = find(id[p]);
        return id[p];
    }
    
    void Union(int i, int j) {
        int p = find(i);
        int q = find(j);
        cout << i << "<>" << j << endl;
        cout << p << "--" << q << endl;
         if (p < q) {
            size[p] += size[q]; 
            id[q] = p;
        }
        else {
            size[q] += size[p];
            id[p] = q;
        }
    }
};

int main(int argc, char ** argv)
{
    Solution sol;
    vector<int> test = {1, 0, -1};
    cout << sol.longestConsecutive(test) << endl;
    return 0;
}
