Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000



class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        bool ok = 1;
        for(auto x : arr) mp[x]++;
        set<int>s;
        for(auto x : mp) {
            if(s.find(x.second) == s.end()) {
                s.insert(x.second);
            }
            else {
                ok = 0;
            }
        }
        return ok;
    }
};


____________________________________________________________________

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    // 🚀 Optimizing I/O operations for better performance
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 📊 Vector to store the frequencies of each element
    vector<int> freq;

    // 🔄 Sorting the input array for easier frequency counting
    sort(arr.begin(), arr.end());

    // 📏 Counting the occurrences of each element in the sorted array
    int count = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            freq.push_back(count);
            count = 1;
        }
    }
    freq.push_back(count);

    // 🔍 Sorting the frequency vector for comparison
    sort(freq.begin(), freq.end());

    // 🔄 Checking for duplicates in the sorted frequency vector
    int n = freq.size();
    for (int i = 1; i < n; i++) {
        if (freq[i] == freq[i - 1])
            return false;
    }

    // ✅ If no duplicates found, return true
    return true;
}
};
