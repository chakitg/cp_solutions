Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104




class Solution {
  public:
    // Function to count inversions in the array.
    int ans=0;
     void merge(vector<int> &arr,int low, int high, int mid){
        int n1=mid-low+1;
        int n2=high-mid;
        int arr1[n1];
        int arr2[n2];
        
        for(int i=0;i<n1;i++) arr1[i]=arr[i+low];
        for(int i=0;i<n2;i++) arr2[i]=arr[i+mid+1];
        int i=0,j=0,k=low;
        while(i<n1 && j<n2){
            if(arr1[i]<=arr2[j]) arr[k++]=arr1[i++];
            else {
                arr[k++]=arr2[j++];
                ans+=n1-i;
            }
        }
        while(i<n1) arr[k++]=arr1[i++];
        while(j<n2) arr[k++]=arr2[j++];
        
    }
    
    int mergeSort(vector<int> &arr,int low, int high){
        if(low>=high) return 0;
        int mid=low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,high,mid);
        return ans;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int N=arr.size();
        return mergeSort(arr,0,N-1);
    }
};
