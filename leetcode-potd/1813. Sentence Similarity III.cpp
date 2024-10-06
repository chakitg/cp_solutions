You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.

For example,

s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

 

Example 1:

Input: sentence1 = "My name is Haley", sentence2 = "My Haley"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".

Example 2:

Input: sentence1 = "of", sentence2 = "A lot of words"

Output: false

Explanation:

No single sentence can be inserted inside one of the sentences to make it equal to the other.

Example 3:

Input: sentence1 = "Eating right now", sentence2 = "Eating"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.

 

Constraints:

1 <= sentence1.length, sentence2.length <= 100
sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
The words in sentence1 and sentence2 are separated by a single space.






class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        
        if(s1.size() > s2.size())return areSentencesSimilar(s2, s1);

        bool l_common = false, r_common = false;
        int n1 = s1.size(), n2 = s2.size(), i_1 = 0, i_2 = 0, j_1 = n1 - 1, j_2 = n2 - 1;

        while(i_1 < n1){
            int i = i_1;
            string str_1 = "", str_2 = "";
            
            while(i_1 < n1){
                if(s1[i_1] != ' ')str_1 += s1[i_1++];
                else {i_1++; break;}
            }

            while(i_2 < n2){
                if(s2[i_2] != ' ')str_2 += s2[i_2++];
                else {i_2++; break;}
            }

            if(str_1 != str_2){i_1 = i; break;}
        }

        if(i_1 == n1)return true;

        while(i_1 <= j_1){
            int j = j_1;
            string str_1 = "", str_2 = "";
            
            while(j_1 >= i_1){
                if(s1[j_1] != ' ')str_1 += s1[j_1--];
                else {j_1--; break;}
            }

            while(j_2 >= 0){
                if(s2[j_2] != ' ')str_2 += s2[j_2--];
                else {j_2--; break;}
            }

            if(str_1 != str_2){j_1 = j; break;} 
        }

        return j_1 + 1 == i_1;
    }
};
