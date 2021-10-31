// A prime number is a Circular Prime Number if all of its possible rotations are itself prime numbers. Now given a number N check if it is Circular Prime or Not.
 

// Example 1:

// Input: N = 197
// Output: 1
// Explanation: 197 is a Circular Prime because
// all rotations of 197 are 197, 719, 971 all of 
// the 3 are prime number's hence 197 is a 
// circular prime.
// Example 2:

// Input: N = 101
// Output: 0
// Explanation: 101 and 11 is prime but 110 is
// not a prime number.
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function isCircularPrime() which takes N as input parameter and returns 1 if it is Circular Prime otherwise returns -1.
 

// Expected Time Complexity: O(Nlog(log(N))
// Expected Space Complexity: O(N)
 

// Constraints:
// 1 <= N <= 105




#include<bits/stdc++.h>
using namespace std;
class Solution{

 // } Driver Code Ends

	public:
	bool isPrime(int n)
{
    if(n==0 || n==1)
        return false;
   if(n==2||n==3)
        return true;
   if(n%2==0 || n%3==0)
        return false;
   for(int i=5;i*i<=n;i=i+6)
   {
       if((n%i==0)||(n%(i+2)==0))
            return false;
   }
   return true;
}
int isCircularPrime(int n) 
{
    // Code here
    if(n<10)
        return isPrime(n);
    string str = to_string(n);
    for(int i=0;i<str.length();i++)
    {
       char temp = str[str.length()-1];
       str.pop_back();
       str = temp + str;
       if(!isPrime(stoi(str)))
            return false;
    }
    return true;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.isCircularPrime(n);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends