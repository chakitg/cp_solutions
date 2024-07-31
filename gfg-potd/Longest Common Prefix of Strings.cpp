Given an array of strings arr. Return the longest common prefix among all strings present in the array. If there's no prefix common in all the strings, return "-1".

Examples :

Input: arr[] = ["geeksforgeeks", "geeks", "geek", "geezer"]
Output: gee
Explanation: "gee" is the longest common prefix in all the given strings.
Input: arr[] = ["hello", "world"]
Output: -1
Explanation: There's no common prefix in the given strings.
Expected Time Complexity: O(n*min(|arri|))
Expected Space Complexity: O(min(|arri|))

Constraints:
1 ≤ |arr| ≤ 103
1 ≤ |arr[i]| ≤ 103




string longestCommonPrefix(vector<string> arr)
    {
        string str="";
        int n=arr.size();
        for(int i=0;i<arr[0].size();i++)
        {
            char ch=arr[0][i];
            for(int j=1;j<n;j++)
            {
                if(ch!=arr[j][i])
                {
                    if(str.empty())
                        return "-1";
                    else return str;
                }
            }

            str+=ch;
        } 
        return str;
    }
