Given two integer array A and B of size N each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid sum combinations from all the possible sum combinations.

Note : Output array must be sorted in non-increasing order.

Example 1:

Input:
N = 2
K = 2
A [ ] = {3, 2}
B [ ] = {1, 4}
Output: {7, 6}
Explanation: 
7 -> (A : 3) + (B : 4)
6 -> (A : 2) + (B : 4)
Example 2:

Input:
N = 4
K = 3
A [ ] = {1, 4, 2, 3}
B [ ] = {2, 5, 1, 6}
Output: {10, 9, 9}
Explanation: 
10 -> (A : 4) + (B : 6)
9 -> (A : 4) + (B : 5)
9 -> (A : 3) + (B : 6)
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxCombinations() which takes the interger N,integer K and two integer arrays A [ ] and B [ ] as parameters and returns the maximum K valid distinct sum combinations .

Expected Time Complexity: O(Nlog(N))
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤  105
1 ≤ K ≤  N
1 ≤ A [ i ] , B [ i ] ≤ 104


class Solution {
public:
    struct Trip {
        int value, a, b;

        bool operator<(const Trip& other) const { // Comparator for comparing the greater values
            if (value == other.value) {
                if (a == other.a)
                    return b > other.b;
                return a > other.a;
            }
            return value > other.value;
        }
    };

    vector<int> maxCombinations(int N, int K, vector<int>& A, vector<int>& B) {
        // Sort the arrays in ascending order
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        // Create a set to store combinations
        set<Trip> st;
        st.insert({A[N - 1] + B[N - 1], N - 1, N - 1});
        
        vector<int> out;
        while (K--) {
            int value = st.begin()->value;
            int a = st.begin()->a;
            int b = st.begin()->b;
            st.erase(st.begin());
            out.push_back(value);
            
            if (a > 0)
                st.insert({A[a - 1] + B[b], a - 1, b});
            if (b > 0)
                st.insert({A[a] + B[b - 1], a, b - 1});
        }
        
        return out;
    }
};
