/**
 * @param {string} num
 * @return {number}
 */
var countBalancedPermutations = function (num) {
  const MOD = 1000000007;
  const n = num.length;

  // Count frequency of each digit
  const cnt = new Array(10).fill(0);
  let total = 0;
  for (let ch of num) {
    cnt[parseInt(ch)]++;
    total += parseInt(ch);
  }

  // If total sum is odd, no balanced permutation is possible
  if (total % 2) return 0;

  // Memoization cache
  const memo = new Map();

  // Updated combination calculation with modulo
  const comb = (n, r) => {
    if (r > n) return 0;
    if (r === 0 || r === n) return 1;
    if (r > n - r) r = n - r;

    let ans = 1n; // Using BigInt for intermediate calculations
    for (let i = 0; i < r; i++) {
      ans = ans * BigInt(n - i);
      ans = ans / BigInt(i + 1);
    }
    return Number(ans % BigInt(MOD));
  };

  // DFS function
  const dfs = (i, odd, even, balance) => {
    if (odd === 0 && even === 0 && balance === 0) return 1;
    if (i < 0 || odd < 0 || even < 0 || balance < 0) return 0;

    const key = `${i},${odd},${even},${balance}`;
    if (memo.has(key)) return memo.get(key);

    let res = 0;
    for (let j = 0; j <= cnt[i]; j++) {
      // Handle multiplication with modulo to prevent overflow
      const ways =
        (BigInt(comb(odd, j)) * BigInt(comb(even, cnt[i] - j))) % BigInt(MOD);
      const next = BigInt(
        dfs(i - 1, odd - j, even - (cnt[i] - j), balance - i * j)
      );
      res = (res + Number((ways * next) % BigInt(MOD))) % MOD;
    }

    memo.set(key, res);
    return res;
  };

  return dfs(9, n - Math.floor(n / 2), Math.floor(n / 2), total / 2);
};
