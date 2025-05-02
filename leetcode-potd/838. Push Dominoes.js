There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.

 

Example 1:

Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Example 2:


Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
 

Constraints:

n == dominoes.length
1 <= n <= 105
dominoes[i] is either 'L', 'R', or '.'.




  var pushDominoes = function(dominoes) {
    function replaceCharAtIndex(str, index, newChar) {
        if (index < 0 || index >= str.length) {
            throw new Error("Index out of range.");
        }
        return str.substring(0, index) + newChar + str.substring(index + 1);
    }

     str = dominoes;

    for ( step = 0; step < dominoes.length; step++) {
         next = str;
         changed = false;
        for ( i = 0; i < dominoes.length; i++) {
            // Push right
            if (str[i] === 'R') {
                if (i + 1 < dominoes.length && str[i + 1] === '.') {
                    if (i + 2 >= dominoes.length || str[i + 2] !== 'L') {
                        // Only apply if still untouched in this step
                        if (next[i + 1] === '.') {
                            next = replaceCharAtIndex(next, i + 1, 'R');
                            changed = true;
                        }
                    }
                }
            }
            // Push left
            if (str[i] === 'L') {
                if (i - 1 >= 0 && str[i - 1] === '.') {
                    if (i - 2 < 0 || str[i - 2] !== 'R') {
                        if (next[i - 1] === '.') {
                            next = replaceCharAtIndex(next, i - 1, 'L');
                            changed = true;
                        }
                    }
                }
            }
        }

        if (!changed) break;
        str = next;
    }

    return str;
};
