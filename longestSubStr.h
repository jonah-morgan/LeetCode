#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // maybe use a vector to store all the chars you cant use in the future???
        int i, j, k;
        int maxCount = 0;
        int thisCount = 1;
        int size;
        bool usedB = false;
        for (i = 0; i < (int)s.size()-1; i++)
        {
            vector<char> used;
            thisCount = 1;
            for(j = i; j < (int)s.size(); j++)
            {
                
                used.push_back(s[j]);
                for (k = 0; k < (int)used.size(); k++)
                {
                    if (used[k] == s[j + 1])
                    {
                        k = (int)used.size();
                        usedB = true;
                    }
                        
                }
                if (!usedB)
                    thisCount++;
                else
                {
                    j = (int)s.size();
                    thisCount = 1;
                }
                usedB = false;
            }
            if (thisCount > maxCount)
                maxCount = thisCount;
        }
        return maxCount;
    }
};

