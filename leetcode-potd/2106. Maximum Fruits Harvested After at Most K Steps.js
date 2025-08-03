var maxTotalFruits = function(fruits, startPos, k) {
    let n = fruits.length;
    let maxFruits = 0;
    
    // Skip all positions that are too far left
    let left = 0;
    while (left < n && fruits[left][0] < startPos - k) left++;

    let right = left;
    let total = 0;

    // Sliding window
    while (right < n && fruits[right][0] <= startPos + k) {
        total += fruits[right][1];

        while (left <= right) {
            const lPos = fruits[left][0], rPos = fruits[right][0];
            const leftToRight = (startPos - lPos) + (rPos - lPos); // Go left then right
            const rightToLeft = (rPos - startPos) + (rPos - lPos); // Go right then left
            const minSteps = Math.min(leftToRight, rightToLeft);
            
            if (minSteps <= k) break;  // Valid window
            total -= fruits[left][1];  // Shrink window
            left++;
        }

        maxFruits = Math.max(maxFruits, total);
        right++;
    }

    return maxFruits;
};
