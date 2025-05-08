There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.

 

Example 1:

Input: moveTime = [[0,4],[4,4]]

Output: 7

Explanation:

The minimum time required is 7 seconds.

At time t == 4, move from room (0, 0) to room (1, 0) in one second.
At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
Example 2:

Input: moveTime = [[0,0,0,0],[0,0,0,0]]

Output: 6

Explanation:

The minimum time required is 6 seconds.

At time t == 0, move from room (0, 0) to room (1, 0) in one second.
At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
At time t == 3, move from room (1, 1) to room (1, 2) in one second.
At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.
Example 3:

Input: moveTime = [[0,1],[1,2]]

Output: 4

 

Constraints:

2 <= n == moveTime.length <= 750
2 <= m == moveTime[i].length <= 750
0 <= moveTime[i][j] <= 109


/**
 * @param {number[][]} moveTime
 * @return {number}
 */
var minTimeToReach = function(moveTime) {
    const m = moveTime.length;
    const n = moveTime[0].length;
    const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    const memo = Array.from({ length: m }, () => new Array(n).fill(Number.MAX_VALUE));
    const queue = new MinHeap ([0, 0, 0, 0]);

    while (!queue.isEmpty()) {
        const [cost, i, j, step] = queue.dequeue();

        if (cost > memo[i][j]) continue;
        if (i === m - 1 && j === n - 1) return cost;

        for (const [row, col] of directions) {
            const x = i + row;
            const y = j + col;

            if (x < 0 || x >= m || y < 0 || y >= n) continue;

            const stepCost = step % 2 === 0 ? 1 : 2;
            const newCost = cost + stepCost + Math.max(0, moveTime[x][y] - cost);

            if (memo[x][y] > newCost) {
                memo[x][y] = newCost;
                queue.enqueue([newCost, x, y, step + 1]);
            }

        }
    }

    return -1;
};

class MinHeap {
    constructor(tuple) {
        this.heap = [tuple];
    }

    parent(index) {
        return Math.floor((index - 1) / 2);
    }

    leftChild(index) {
        return 2 * index + 1;
    }

    rightChild(index) {
        return 2 * index + 2;
    }

    swap(i, j) {
        [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];
    }

    enqueue(tuple) {
        this.heap.push(tuple);
        this.bubbleUp(this.heap.length - 1);
    }

    dequeue() {
        if (this.heap.length === 1) return this.heap.pop();
        const root = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown(0);
        return root;
    }

    bubbleUp(i) {
        while (i > 0 && this.heap[this.parent(i)][0] > this.heap[i][0]) {
            this.swap(i, this.parent(i));
            i = this.parent(i);
        }
    }

    bubbleDown(i) {
        let smallest = i;
        const left = this.leftChild(i);
        const right = this.rightChild(i);

        if (left < this.heap.length && this.heap[left][0] < this.heap[smallest][0]) {
            smallest = left;
        }

        if (right < this.heap.length && this.heap[right][0] < this.heap[smallest][0]) {
            smallest = right;
        }

        if (smallest !== i) {
            this.swap(i, smallest);
            this.bubbleDown(smallest);
        }
    }

    isEmpty() {
        return this.heap.length === 0;
    }

    peek() {
        return this.heap[0];
    }

    size () {
        return this.heap.length;
    }
}
