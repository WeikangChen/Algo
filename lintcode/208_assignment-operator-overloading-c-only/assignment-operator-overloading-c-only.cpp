/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/assignment-operator-overloading-c-only
@Language: C++
@Datetime: 16-04-23 02:26
*/

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        if (this != &object) {
            if(m_pData) delete m_pData;
            if(object.m_pData) {
                m_pData = new char[strlen(object.m_pData)+1];
                strcpy(m_pData, object.m_pData);
            }
            else {
                m_pData = NULL;
            }
        }
        return *this;
    }
};