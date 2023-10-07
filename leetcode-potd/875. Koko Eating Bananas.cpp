Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109



class Solution {
public:
    bool ok(long long x , vector<int> &a , int k) {
      long long H = k;
      for(auto t : a) {
        H -= (t + x - 1)/x;
      }
      return H >= 0;
    }

    int minEatingSpeed(vector<int>& a, int k) {
        long long l = 1;
        long long r = 1;
        while(!ok(r,a,k)) r *= 2;
        while(r > l + 1) {
         long long m = (l+r) >> 1;
         if(ok(m,a,k)) {
          r = m;
         } else {
          l = m;
         }
        }
        return r;
    }
};
