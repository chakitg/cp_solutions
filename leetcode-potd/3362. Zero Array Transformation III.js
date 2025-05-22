You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most 1.
The amount by which the value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

 

Example 1:

Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]

Output: 1

Explanation:

After removing queries[2], nums can still be converted to a zero array.

Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Example 2:

Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]

Output: 2

Explanation:

We can remove queries[2] and queries[3].

Example 3:

Input: nums = [1,2,3,4], queries = [[0,3]]

Output: -1

Explanation:

nums cannot be converted to a zero array even after using all the queries.

 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= li <= ri < nums.length



/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number}
 */
var maxRemoval = function(nums, queries) {
    const n = nums.length;
    const m = queries.length;

    // Step 1: Sort queries by start point
    queries.sort((a, b) => a[0] - b[0]);

    // Initialize heaps
    const available = new MaxHeap(); // Max-heap for available queries' end points
    const running = new MinHeap();   // Min-heap for running queries' end points

    let queryIndex = 0;

    for (let i = 0; i < n; i++) {
        // Add all queries starting at or before i to available
        while (queryIndex < m && queries[queryIndex][0] <= i) {
            available.insert(queries[queryIndex][1]);
            queryIndex++;
        }

        // Remove queries from running that have ended before i
        while (!running.isEmpty() && running.peek() < i) {
            running.extractMin();
        }

        // Apply queries to reduce nums[i] to zero
        while (nums[i] > running.size()) {
            if (available.isEmpty() || available.peek() < i) {
                return -1;
            }
            running.insert(available.extractMax());
        }
    }

    // Remaining available queries can be removed
    return available.size();
};

// MinHeap implementation
class MinHeap {
    constructor() {
        this.heap = [];
    }

    insert(val) {
        this.heap.push(val);
        this._heapifyUp();
    }

    extractMin() {
        if (this.heap.length === 0) return null;
        const min = this.heap[0];
        const end = this.heap.pop();
        if (this.heap.length > 0) {
            this.heap[0] = end;
            this._heapifyDown();
        }
        return min;
    }

    peek() {
        return this.heap[0] || null;
    }

    size() {
        return this.heap.length;
    }

    isEmpty() {
        return this.heap.length === 0;
    }

    _heapifyUp() {
        let idx = this.heap.length - 1;
        const element = this.heap[idx];
        while (idx > 0) {
            let parentIdx = Math.floor((idx - 1) / 2);
            let parent = this.heap[parentIdx];
            if (element >= parent) break;
            this.heap[idx] = parent;
            idx = parentIdx;
        }
        this.heap[idx] = element;
    }

    _heapifyDown() {
        let idx = 0;
        const length = this.heap.length;
        const element = this.heap[0];
        while (true) {
            let leftIdx = 2 * idx + 1;
            let rightIdx = 2 * idx + 2;
            let swap = null;

            if (leftIdx < length) {
                if (this.heap[leftIdx] < element) {
                    swap = leftIdx;
                }
            }

            if (rightIdx < length) {
                if (
                    (swap === null && this.heap[rightIdx] < element) ||
                    (swap !== null && this.heap[rightIdx] < this.heap[leftIdx])
                ) {
                    swap = rightIdx;
                }
            }

            if (swap === null) break;
            this.heap[idx] = this.heap[swap];
            idx = swap;
        }
        this.heap[idx] = element;
    }
}

// MaxHeap implementation
class MaxHeap {
    constructor() {
        this.heap = [];
    }

    insert(val) {
        this.heap.push(val);
        this._heapifyUp();
    }

    extractMax() {
        if (this.heap.length === 0) return null;
        const max = this.heap[0];
        const end = this.heap.pop();
        if (this.heap.length > 0) {
            this.heap[0] = end;
            this._heapifyDown();
        }
        return max;
    }

    peek() {
        return this.heap[0] || null;
    }

    size() {
        return this.heap.length;
    }

    isEmpty() {
        return this.heap.length === 0;
    }

    _heapifyUp() {
        let idx = this.heap.length - 1;
        const element = this.heap[idx];
        while (idx > 0) {
            let parentIdx = Math.floor((idx - 1) / 2);
            let parent = this.heap[parentIdx];
            if (element <= parent) break;
            this.heap[idx] = parent;
            idx = parentIdx;
        }
        this.heap[idx] = element;
    }

    _heapifyDown() {
        let idx = 0;
        const length = this.heap.length;
        const element = this.heap[0];
        while (true) {
            let leftIdx = 2 * idx + 1;
            let rightIdx = 2 * idx + 2;
            let swap = null;

            if (leftIdx < length) {
                if (this.heap[leftIdx] > element) {
                    swap = leftIdx;
                }
            }

            if (rightIdx < length) {
                if (
                    (swap === null && this.heap[rightIdx] > element) ||
                    (swap !== null && this.heap[rightIdx] > this.heap[leftIdx])
                ) {
                    swap = rightIdx;
                }
            }

            if (swap === null) break;
            this.heap[idx] = this.heap[swap];
            idx = swap;
        }
        this.heap[idx] = element;
    }
}
