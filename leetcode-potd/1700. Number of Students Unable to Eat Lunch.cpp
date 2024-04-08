The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.

 

Example 1:

Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0 
Explanation:
- Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
- Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
- Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
- Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
- Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
Hence all students are able to eat.
Example 2:

Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
Output: 3
 

Constraints:

1 <= students.length, sandwiches.length <= 100
students.length == sandwiches.length
sandwiches[i] is 0 or 1.
students[i] is 0 or 1.






class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count1 = 0, count0 = 0;
        
        // Count the number of students preferring each type of sandwich
        for (int x : students) {
            if (x)
                count1++;
            else
                count0++;
        }

        // Iterate through the sandwiches
        for (int x : sandwiches) {
            // If the sandwich on top is preferred by a student
            if (x) {
                // If there are still students who prefer this type of sandwich
                if (count1 > 0) {
                    count1--; // Reduce the count of students preferring this type of sandwich
                } else {
                    // If no students prefer this type of sandwich, return the count of students unable to eat
                    return count0;
                }
            } else {
                // If the sandwich on top is not preferred by a student
                // If there are still students who prefer this type of sandwich
                if (count0 > 0) {
                    count0--; // Reduce the count of students preferring this type of sandwich
                } else {
                    // If no students prefer this type of sandwich, return the count of students unable to eat
                    return count1;
                }
            }
        }
        return 0; // If all students can eat, return 0
    }
};
