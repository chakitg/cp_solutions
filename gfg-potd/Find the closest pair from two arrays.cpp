class Solution {
public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        vector<int> out;
        int nin = INT_MAX;
        
        int a = 0, b = m - 1;
        while (a < n && b >= 0) {
            int sum = arr[a] + brr[b];
            if (abs(sum - x) < nin) {
                out = {arr[a], brr[b]};
                nin = abs(sum - x);
            }
            if (sum > x)
                --b;
            else
                ++a;
        }
        return out;
    }
};
