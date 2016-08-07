/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/interleaving-string
@Language: Java
@Datetime: 16-08-07 20:25
*/

public class Solution {
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true or false.
     */
    public boolean isInterleave(String s1, String s2, String s3) {
    
        int m=s1.length();
        int n=s2.length();
        boolean [][] dp = new boolean [m+1][n+1];
        
        if ((m+n) != s3.length()) return false;
        
        dp[0][0] = true;
        
        for (int i=1;i<m+1;i++) {
            if (s1.charAt(i-1) == s3.charAt(i-1)){ 
                dp[i][0] = true;
            } else {
                break;
            }
        }
        
        for (int i=1;i<n+1;i++) {
            if (s2.charAt(i-1) == s3.charAt(i-1)){ 
                dp[0][i] = true;
            } else {
                break;
            }
        }
        
        for (int i=1; i<m+1;i++) {
            for (int j=1; j<n+1;j++) {
                if (s1.charAt(i-1)==s3.charAt(i+j-1) && dp[i-1][j] == true) dp[i][j] = true; 
                if (s2.charAt(j-1)==s3.charAt(i+j-1) && dp[i][j-1] == true) dp[i][j] = true; 
            }
        }
        
        return dp[m][n];
    }
    
    
    
}