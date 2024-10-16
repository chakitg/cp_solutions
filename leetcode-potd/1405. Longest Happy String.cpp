A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
 

Constraints:

0 <= a, b, c <= 100
a + b + c > 0


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
     string ans="";
     int limit_a=min(2,a),limit_b=min(b,2),limit_c=min(2,c);
     while(limit_a || limit_b || limit_c){
        int mx=max({limit_a,limit_b,limit_c});
        priority_queue<pair<int,char>>pq;
        char i;
        if(mx==limit_a)pq.push({a,'a'});
        if(mx==limit_b)pq.push({b,'b'});
        if(mx==limit_c)pq.push({c,'c'});
        i=pq.top().second;
        if(i=='a'){
            ans+='a';
            limit_a--;
            limit_b=min(b,2),limit_c=min(2,c);
            a--;
            if(a>b+c && limit_a){ans+='a';limit_a--;a--;}//push the limit to 0 if we know element is going 
            //to be wasted
        }
        else if(i=='b'){
            ans+='b';
            limit_b--;
            limit_a=min(a,2),limit_c=min(2,c);
            b--;
            if(b>a+c && limit_b){ans+='b';limit_b--;b--;}
        }
        else{
            ans+='c';
            limit_c--;
            limit_a=min(a,2),limit_b=min(2,b);
            c--;
            if(c>b+a && limit_c){ans+='c';limit_c--;c--;}
        }
     }
     return ans;
    }
};
