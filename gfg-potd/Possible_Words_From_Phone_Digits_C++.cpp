//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    map<int,string> mmap;
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        mmap[2]="abc",mmap[3]="def",mmap[4]="ghi",mmap[5]="jkl";
        mmap[6]="mno",mmap[7]="pqrs",mmap[8]="tuv",mmap[9]="wxyz";
        
        vector<string> ans;
        
        recursion(a,N,ans,0,"");
        
        return ans;
    }
    
    void recursion(int a[],int n,vector<string> &ans,int index,string str)
    {
        if(index>n)
        return;
        
        string s=mmap[a[index]];
        
        if(index==n-1)
        {
            for(int i=0; i<s.size(); i++)
            ans.push_back(str+s[i]);
            
        }
        else
        {
            for(int i=0; i<s.size(); i++)
            {
                recursion(a,n,ans,index+1,str+s[i]);
            }
        }
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends