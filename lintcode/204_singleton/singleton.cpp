/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/singleton
@Language: C++
@Datetime: 16-04-25 03:15
*/

class Solution {
private:
    static Solution* instance;
    
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        if (!instance)
            instance = new Solution();
        return instance;
    }
};

Solution* Solution::instance = NULL;