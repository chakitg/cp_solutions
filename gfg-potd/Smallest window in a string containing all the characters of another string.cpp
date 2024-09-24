Given two strings s and p. Find the smallest window in the string s consisting of all the characters(including duplicates) of the string p.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.
Note : All characters are in Lowercase alphabets. 

Examples:

Input: s = "timetopractice", p = "toc"
Output: toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Input: s = "zoomlazapzo", p = "oza"
Output: apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(n), n = len(p)

Constraints: 
1 ≤ |s|, |p| ≤ 105




class Solution
{
public:
    string smallestWindow(string s, string p)
    {
        vector<int> mpp(26, 0);
        for (char ch : p)
        {
            mpp[ch - 'a']++;
        }
        int req = p.length();
        int i = 0;
        int j = 0;
        int n = s.length();
        if (req > n)
            return "-1";
        int minSize = INT_MAX;
        int sp = 0;
        while (j < n)
        {
            if (mpp[s[j] - 'a'] > 0)
                req--;
            mpp[s[j] - 'a']--;
            while (req == 0)
            {
                int currSize = j - i + 1;
                if (currSize < minSize)
                {
                    minSize = currSize;
                    sp = i;
                }
                mpp[s[i] - 'a']++;
                if (mpp[s[i] - 'a'] > 0)
                {
                    req++;
                }
                i++;
            }
            j++;
        }
        return minSize == INT_MAX ? "-1" : s.substr(sp, minSize);
    }
};
