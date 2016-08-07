/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/left-pad
@Language: C++
@Datetime: 16-04-25 20:34
*/

class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        if (size > originalStr.size())
            return string(size-originalStr.size(), padChar) + originalStr;
        return originalStr;
    }
};