//
//  main.cpp
//  KMP
//
//  Created by Jinglun Zhou on 2021/2/7.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        /*
         haystack is pattern string
         needle is target string
         */
        
        int n = haystack.size();
        int m = needle.size();
        if(m == 0) {
            return 0;
        }
        if(n == 0) {
            return -1;
        }
        vector<int> suffix = getSuffix(needle);
        vector<int> dp(n,0);
        
        dp[0] = haystack[0] == needle[0];
        if(m == 1 && dp[0]) return 0;
        // iterate over haystack, try to match haystack's current suffix with prefix of needle
        for(int i = 1; i < n; i++) {
            int j = dp[i-1];
            while(j >= 1 && haystack[i] != needle[j]) {
                j = suffix[j - 1];
            }
            dp[i] = j + (haystack[i] == needle[j]);
            if(dp[i] == needle.size()) {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
    i - x + 1 = k
    /*
     max len such that needle[0:k-1] = needle[i-k+1:i]
     This is used to calculate needle's suffix
     */
    vector<int> getSuffix(string& needle) {
        int n = needle.size();
        vector<int> dp(n,0);
        for(int i = 1; i < n; i++) {
            int j = dp[i-1];
            while(j >= 1 && needle[j] != needle[i]) {
                j = dp[j - 1];
            }
            dp[i] = j + (needle[j] == needle[i]);
        }
        return dp;
    }
};
