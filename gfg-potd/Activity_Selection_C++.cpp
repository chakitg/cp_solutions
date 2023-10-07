// Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
// Note : Duration of the activity includes both starting and ending day.


// Example 1:

// Input:
// N = 2
// start[] = {2, 1}
// end[] = {2, 2}
// Output: 
// 1
// Explanation:
// A person can perform only one of the
// given activities.
// Example 2:

// Input:
// N = 4
// start[] = {1, 3, 2, 5}
// end[] = {2, 4, 3, 6}
// Output: 
// 3
// Explanation:
// A person can perform activities 1, 2
// and 4.

// Your Task :
// You don't need to read input or print anything. Your task is to complete the function activityselection() which takes array start[ ], array end[ ] and integer N as input parameters and returns the maximum number of activities that can be done.


// Expected Time Complexity : O(N * Log(N))
// Expected Auxilliary Space : O(N)

// Constraints:
// 1 ≤ N ≤ 2*105
// 1 ≤ start[i] ≤ end[i] ≤ 109




#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        #define mp make_pair
        #define pb push_back
        typedef typename std::pair<int,int> ip;
        vector<vector<int>> a{};
        for(int i=0;i<n;++i){
            a.pb(vector<int>{start[i],end[i]});
        }
        sort(a.begin(),a.end(),[](auto&& x,auto&& y){
            return x[1]<y[1];
        });
        int c{1};
        int last{a.at(0).at(1)};
        int i{1};
        while(i<n){
            auto nx{a.at(i).at(0)};
            if(nx>last){
                last=a.at(i).at(1);
                ++c;
            }
            ++i;
        }
        return c;
    }
};


int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
