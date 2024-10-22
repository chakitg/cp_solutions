Given an array arr[] and two integers say, x and y, find the number of sub-arrays in which the number of occurrences of x is equal to the number of occurrences of y.

Examples:

Input: arr[] = [1, 2, 1] , x= 1 , y = 2
Output: 2
Explanation: The possible sub-arrays have same equal number of occurrences of x and y are:
1) [1, 2], x and y have same occurrence(1).
2) [2, 1], x and y have same occurrence(1).
Input: arr[] = [1, 2, 1] , x = 4 , y = 6
Output: 6
Explanation: The possible sub-arrays have same equal number of occurrences of x and y are:
1) [1], x and y have same occurrence(0).
2) [2], x and y have same occurrence(0).
3) [1], x and y have same occurrence(0).
4) [1, 2], x and y have same occurrence(0).
5) [2, 1], x and y have same occurrence(0).
6) [1, 2, 1], x and y have same occurrence(0).
Input: arr[] = [1, 2, 1] , x= 1 , y = 4
Output: 1
Explanation: The possible sub-array have same equal number of occurrences of x and y is: [2], x and y have same occurrence(0)
Constraints: 
1 <= arr.size() <= 106
1 <= arr[i], x, y<=106





class Solution {
  public:
    int sameOccurrence(vector<int>& a, int x, int y) {
        int n=a.size();
        
        for(int i=0;i<n;i++){
            if(a[i]==x) a[i]=1;
            else if(a[i]==y) a[i]=-1;
            else a[i]=0;
        }
        
        int s=0,c=0;
        unordered_map<int,int> m;
        
        m[0]++;
        
        for(int i=0;i<n;i++){
            s=s+a[i];
            if(m.find(s)!=m.end()) c=c+m[s];
            m[s]++;
        }
        
        return c;
    }
};
