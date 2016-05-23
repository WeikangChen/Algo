#include <iostream>
#include <vector>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    if(nums.size() < 2) return nums;
    int maj1 = 0;
    int maj2 = 1;
    int cnt1 = 0;
    int cnt2 = 0;
        
    for(int x: nums) {
        if(maj1 == x) 
            cnt1 ++;
        else if(maj2 == x) 
            cnt2 ++;
        else if(cnt1 == 0) {
            cnt1 = 1;
            maj1 = x;
        }
        else if(cnt2 == 0) {
            cnt2 = 1;
            maj2 = x;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }
        
    cnt1 = cnt2 = 0;
    for(int x: nums) {
        if(x == maj1) cnt1++;
        else if(x == maj2) cnt2++;
    }
    vector<int> res;
    if(cnt1 > nums.size() / 3) res.push_back(maj1);
    if(cnt2 > nums.size() / 3) res.push_back(maj2);
        
    return res;
}

int main(int argc, char ** argv)
{
    int arr[] = {1,2,2,3,2,1,1,3};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    vector<int> res = majorityElement(nums);
    for(int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << endl;
    }
    return 0;
}
