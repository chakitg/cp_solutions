//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int count(int N, vector<int> A,int X)
    {int msb = __lg(X), ans = N, temp = 0, vis[N] = {0};
	for (int i = 30; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (!vis[j] && ((X >> i) & 1) && !((A[j] >> i) & 1) )temp++, vis[j] = 1;
			if (!((A[j] >> i) & 1) && !vis[j])cnt++;
		}
		if (!((X >> i) & 1))ans = min(ans, temp + cnt);
	}
	return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends