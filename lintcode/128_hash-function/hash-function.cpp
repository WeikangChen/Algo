/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/hash-function
@Language: C++
@Datetime: 16-04-23 03:59
*/

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key, int HASH_SIZE) {
        long long res = 0;
        int magic = 33;
        for (auto c : key) {
            res = 33 * res + c;
            res %= HASH_SIZE;
        }
        return res;
    }
};