// Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

// Example 1:
// Input:
// N = 4
// mat[][] =     {{16, 28, 60, 64},
//                   {22, 41, 63, 91},
//                   {27, 50, 87, 93},
//                   {36, 78, 87, 94 }}
// K = 3
// Output: 27
// Explanation: 27 is the 3rd smallest element.
 

// Example 2:
// Input:
// N = 4
// mat[][] =     {{10, 20, 30, 40}
//                   {15, 25, 35, 45}
//                   {24, 29, 37, 48}
//                   {32, 33, 39, 50}}
// K = 7
// Output: 30
// Explanation: 30 is the 7th smallest element.


// Your Task:
// You don't need to read input or print anything. Complete the function kthsmallest() which takes the mat, N and K as input parameters and returns the kth smallest element in the matrix.
 

// Expected Time Complexity: O(N*Log(N))
// Expected Auxiliary Space: O(N)

 

// Constraints:
// 1 <= N <= 50
// 1 <= mat[][] <= 10000
// 1 <= K <= N*N


// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends




int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    //Your code here
    priority_queue<int> pq;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int curr = mat[i][j];
            if(pq.size() < k)
                pq.push(curr);
            else
            {
                if(curr < pq.top())
                {
                    pq.pop();
                    pq.push(curr);
                }
            }
        }
    }
    return pq.top();
}


