You are given an array nums of n positive integers and an integer k.

Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:

Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
Multiply your score by x.
Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive.

The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.

Return the maximum possible score after applying at most k operations.

Since the answer may be large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [8,3,9,3,8], k = 2
Output: 81
Explanation: To get a score of 81, we can apply the following operations:
- Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 1, but nums[2] has the smaller index. Hence, we multiply the score by nums[2]. The score becomes 9 * 9 = 81.
It can be proven that 81 is the highest score one can obtain.
Example 2:

Input: nums = [19,12,14,6,10,18], k = 3
Output: 4788
Explanation: To get a score of 4788, we can apply the following operations: 
- Choose subarray nums[0, ..., 0]. nums[0] is the only element in this subarray. Hence, we multiply the score by nums[0]. The score becomes 1 * 19 = 19.
- Choose subarray nums[5, ..., 5]. nums[5] is the only element in this subarray. Hence, we multiply the score by nums[5]. The score becomes 19 * 18 = 342.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 2, but nums[2] has the smaller index. Hence, we multipy the score by nums[2]. The score becomes 342 * 14 = 4788.
It can be proven that 4788 is the highest score one can obtain.
 

Constraints:

1 <= nums.length == n <= 105
1 <= nums[i] <= 105
1 <= k <= min(n * (n + 1) / 2, 109)


class Modulo {
    constructor(modulo) {
        this.modulo = modulo;
        this._phi = modulo - 1;
    }

    getPhi() {
        return this._phi;
    }

    getInverse(a) {
        return this.pow(a, this.getPhi() - 1);
    }

    add(...numbers) {
        let result = 0;
        for (let number of numbers) {
            result = (result + (number % this.modulo)) % this.modulo;
        }
        if (result < 0) result += this.modulo;
        return result;
    }

    _quickMul(a, b) {
        a = ((a % this.modulo) + this.modulo) % this.modulo;
        b = ((b % this.modulo) + this.modulo) % this.modulo;
        if (a === 0 || b === 0) return 0;
        let result = 0;
        while (b) {
            while (b % 2 === 0) {
                a = (a * 2) % this.modulo;
                b /= 2;
            }
            if (b % 2 !== 0) {
                result = (result + a) % this.modulo;
                b--;
            }
        }
        return result;
    }

    mul(...numbers) {
        let result = 1;
        for (let number of numbers) {
            if (number > 0 && number < 1)
                number = this.getInverse(Math.round(1 / number));
            result = this._quickMul(result, number);
            if (result === 0) return 0;
        }
        if (result < 0) result += this.modulo;
        return result;
    }

    div(a, b) {
        return this._quickMul(a, this.getInverse(b));
    }

    pow(a, b) {
        a = ((a % this.modulo) + this.modulo) % this.modulo;
        if (a === 0) return 0;
        let result = 1;
        while (b) {
            while (b % 2 === 0) {
                a = this._quickMul(a, a);
                b /= 2;
            }
            if (b % 2 !== 0) {
                result = this._quickMul(result, a);
                b--;
            }
        }
        return result;
    }
}
const mod = new Modulo(1000000007);

function initEratosthenesSieve(n) {
    let eratosthenesSieve = Array(n + 1).fill(0);
    eratosthenesSieve[1] = 0;
    for (let i = 2; i <= n; i++) {
        if (!eratosthenesSieve[i]) {
            for (let j = i; j <= n; j += i) {
                eratosthenesSieve[j]++;
            }
        }
    }
    return eratosthenesSieve;
}
let eratosthenesSieve = initEratosthenesSieve(100000);
var maximumScore = function (nums, k) {
    const n = nums.length;
    const pre = Array(n).fill(0);
    const pos = Array(n).fill(n);
    function isMorePriority(l, r) {
        return eratosthenesSieve[nums[l]] >= eratosthenesSieve[nums[r]];
    }
    let st = [];
    for (let i = 0; i < n; i++) {
        while (st.length && !isMorePriority(st[st.length - 1], i)) st.pop();
        pre[i] = st.length ? st[st.length - 1] : -1;
        st.push(i);
    }
    st = [];
    for (let i = n - 1; i >= 0; i--) {
        while (st.length && isMorePriority(i, st[st.length - 1])) st.pop();
        pos[i] = st.length ? st[st.length - 1] : n;
        st.push(i);
    }
    const indices = Array.from(Array(n), (_, i) => i);
    indices.sort((a, b) => nums[b] - nums[a]);
    let result = 1;
    for (let i = 0; i < n; i++) {
        const ind = indices[i];
        const pow = Math.min((ind - pre[ind]) * (pos[ind] - ind), k);
        result = mod.mul(result, mod.pow(nums[ind], pow));
        k -= pow;
        if (!k) return result;
    }
};
