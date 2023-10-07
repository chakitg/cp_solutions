// Given an array A of N integers. You have to find whether a combination of four elements in the array whose sum is equal to a given value X exists or not.
 

// Example 1:

// Input:
// N = 6
// A[] = {1, 5, 1, 0, 6, 0}
// X = 7
// Output:
// 1

// Explantion:
// 1, 5, 1, 0 are the four elements which makes sum 7.
 


// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function find4Numbers() which takes the array A[], its size N and an integer X as inputs and returns true if combination is found else false. Driver code will print 1 or 0 accordingly.

 

// Expected Time Complexity: O(N3)
// Expected Auxiliary Space: O(1)

 

// Constraints:
// 4 <= N <= 100
// 1 <= A[i] <= 1000



//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, x;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin>>x;
        cout << find4Numbers(a, n, x) << endl;

    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

bool find4Numbers(int A[], int n, int X)  
{
    sort(A,A+n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int l=j+1,h=n-1;
            while(l<h){
                int sum=A[i]+A[j]+A[l]+A[h];
                if(sum==X)
                    return true;
                else if(sum<X)
                    l++;
                else
                    h--;
            }
        }
    }
    return false;
}