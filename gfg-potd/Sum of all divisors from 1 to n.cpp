class Solution {
public:
    long long sumOfDivisors(int N) {
        long long out = 0;
        for (int i = 1; i <= N; ++i) {
            out += (N / i) * i;
        }
        return out;
    }
};


class Solution {
public:
    long long sumOfDivisors(int N) {
        long long out = 0;
        for (int i = 1; i <= N; ++i) {
            out += (N / i) * i;
        }
        return out;
    }
};
