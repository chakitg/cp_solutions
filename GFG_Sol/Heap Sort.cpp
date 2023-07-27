Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.

Example 1:

Input:
N = 5
arr[] = {4,1,3,9,7}
Output:
1 3 4 7 9
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1,3,4,7,9.
Example 2:

Input:
N = 10
arr[] = {10,9,8,7,6,5,4,3,2,1}
Output:
1 2 3 4 5 6 7 8 9 10
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1, 2,3,4,5,6,7,8,9,10.
Your Task :
You don't have to read input or print anything. Your task is to complete the functions heapify(), buildheap() and heapSort() where heapSort() and buildheap() takes the array and it's size as input and heapify() takes the array, it's size and an index i as input. Complete and use these functions to sort the array using heap sort algorithm.
Note: You don't have to return the sorted list. You need to sort the array "arr" in place.

Expected Time Complexity: O(N * Log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 106
1 ≤ arr[i] ≤ 106




class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int cur = arr[i];
        int par = arr[(i - 1) / 2];
        
        while(i > 0 and par < cur){
            swap(arr[(i - 1) / 2], arr[i]);
            i = (i - 1) / 2;
            
            cur = arr[i];
            if(i > 0)
                par = arr[(i - 1) / 2];
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i = 1; i < n; i++){
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        
        int last = n;
        
        while(last > 0){
            swap(arr[0], arr[--last]);
            
            int ind = 0;
            int cur = arr[ind];
            int c1, c2;
            c1 = c2 = -1;
            
            if(ind * 2 + 1 < last)    
                c1 = arr[ind * 2 + 1];
            if(ind * 2 + 2 < last)
                c2 = arr[ind * 2 + 2];
                
            while(c1 > cur or c2 > cur){
                if(c1 > cur and c1 > c2){
                    swap(arr[ind * 2 + 1], arr[ind]);
                    ind = ind * 2 + 1;
                }
                else if(c2 > cur){
                    swap(arr[ind * 2 + 2], arr[ind]);
                    ind = ind * 2 + 2;
                }
                
                c1 = c2 = -1;
                
                if(ind * 2 + 1 < last)    
                    c1 = arr[ind * 2 + 1];
                if(ind * 2 + 2 < last)
                    c2 = arr[ind * 2 + 2];
            }
        }
    }
};
