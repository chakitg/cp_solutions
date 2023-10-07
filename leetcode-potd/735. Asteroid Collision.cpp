We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0




class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> stk;
        
        for(int i = 0; i < n; i++){
            if(stk.empty() || asteroids[i] > 0){
                stk.push(asteroids[i]);
            }else{
                while(!stk.empty() && stk.top() > 0 && stk.top() < abs(asteroids[i])){
                    stk.pop();
                }

                if(!stk.empty() && stk.top() == abs(asteroids[i])){
                    stk.pop();
                }else{
                    if(stk.empty() || stk.top() < 0){
                        stk.push(asteroids[i]);
                    }
                } 
            }
        }
        vector<int> ans(stk.size(), 0);
        int size = stk.size();
        while(!stk.empty()){
            ans[--size] = stk.top();
            stk.pop();
        }
        return ans;
    }
};
