Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

 

Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
Example 2:

Input: arr = [1,1,1,1,1]
Output: 10
 

Constraints:

1 <= arr.length <= 300
1 <= arr[i] <= 108






class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int n = arr.size(), ans = 0, Xor = 0;
        unordered_map<int, pair<int, int>> mp;

        for(int i = 0 ; i < n ; i++){
            Xor ^= arr[i];
            
            if(!Xor){
                ans += i;
            }

            if(mp.contains(Xor)){
                auto [count, sum] = mp[Xor];
                ans += count * i - count - sum;
            }

            mp[Xor].first++;
            mp[Xor].second += i;
        }

        return ans;
    }
};
