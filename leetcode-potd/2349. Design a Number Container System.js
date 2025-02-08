Design a number container system that can do the following:

Insert or Replace a number at the given index in the system.
Return the smallest index for the given number in the system.
Implement the NumberContainers class:

NumberContainers() Initializes the number container system.
void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.
 

Example 1:

Input
["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
[[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
Output
[null, -1, null, null, null, null, 1, null, 2]

Explanation
NumberContainers nc = new NumberContainers();
nc.find(10); // There is no index that is filled with number 10. Therefore, we return -1.
nc.change(2, 10); // Your container at index 2 will be filled with number 10.
nc.change(1, 10); // Your container at index 1 will be filled with number 10.
nc.change(3, 10); // Your container at index 3 will be filled with number 10.
nc.change(5, 10); // Your container at index 5 will be filled with number 10.
nc.find(10); // Number 10 is at the indices 1, 2, 3, and 5. Since the smallest index that is filled with 10 is 1, we return 1.
nc.change(1, 20); // Your container at index 1 will be filled with number 20. Note that index 1 was filled with 10 and then replaced with 20. 
nc.find(10); // Number 10 is at the indices 2, 3, and 5. The smallest index that is filled with 10 is 2. Therefore, we return 2.
 

Constraints:

1 <= index, number <= 109
At most 105 calls will be made in total to change and find.



  var NumberContainers = function() {
	/** @type {Map<number, Set<number>>} */
    this.indicesMap = new Map();
	/** @type {Map<number, number>} */
	this.numberMap = new Map();
	/** @type {Map<number, number>} */
	this.minIndexMap = new Map();
};

/**
 * @param {number} index
 * @param {number} number
 * @return {void}
 */
NumberContainers.prototype.change = function(index, number) {
	if (this.numberMap.has(index)) {
		/** @type {number} */
		const old_num = this.numberMap.get(index);
		const set = this.indicesMap.get(old_num);
		if (set.size === 1) {
			this.indicesMap.delete(old_num);
		} else {
			this.indicesMap.get(old_num).delete(index);
		}
		if (index === this.minIndexMap.get(old_num)) {
			this.minIndexMap.set(old_num, -1); // marked as dirty
		}
	}

	this.numberMap.set(index, number);
	if (!this.indicesMap.has(number)) {
		this.indicesMap.set(number, new Set());
	}
	this.indicesMap.get(number).add(index);
	if (!this.minIndexMap.has(number) || index < this.minIndexMap.get(number)) {
		this.minIndexMap.set(number, index);
	}
};

/**
 * @param {number} number
 * @return {number}
 */
NumberContainers.prototype.find = function(number) {
	if (!this.indicesMap.has(number)) {
		return -1;
	}

	if (this.minIndexMap.get(number) === -1) {
		let min = Number.MAX_SAFE_INTEGER;
		for (let x of this.indicesMap.get(number)) {
			min = Math.min(x, min);
		}
		this.minIndexMap.set(number, min);
		return min;
	} else {
		return this.minIndexMap.get(number);
	}
};

/** 
 * Your NumberContainers object will be instantiated and called as such:
 * var obj = new NumberContainers()
 * obj.change(index,number)
 * var param_2 = obj.find(number)
 */
