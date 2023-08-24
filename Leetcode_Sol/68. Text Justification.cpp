Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 

Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth




class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        int curr = 0, oglen = 0;
        vector<string>aux;
        //stores the words for the current row
        for(string s : words)
        {
            int l = s.length();
            // checking if the word can be taken in the current row or not
            if(maxWidth-curr>l) 
            {
                curr+=s.length()+1;
                oglen+=s.length();
                aux.push_back(s);
            }
            else if(maxWidth-curr==l)
            {
                curr+=s.length();
                oglen+=s.length();
                aux.push_back(s);
            }
            else
            {
                curr = 0;
                string help = "";
                int totspaces = maxWidth-oglen; // total spaces needed to fit in the row
            
                oglen=0;
                int pos = aux.size()-1;
                //SIMULATION
                for(string x : aux)
                {
                    int spaces=0;
                    if(pos!=0)
                        spaces = (ceil)(totspaces*1.00/pos);
                    string sp="";
                    for(int i=0;i<spaces;i++)
                        sp+=" ";
                    help+=x+sp;
                    totspaces-=spaces;
                    pos--;
                }
                aux.clear();
                help=help.substr(0,maxWidth);
                int extra=maxWidth-help.length();
                for(int i=0;i<extra;i++)
                    help+=" ";
                res.push_back(help);

                aux.push_back(s);
                curr+=s.length()+1;
                oglen+=s.length();
            }
        }
        string help = "";
        for(string x : aux)
        {
            help+=x+" ";
        }
        int spaces=maxWidth-help.length();
        for(int i=0;i<spaces;i++)
            help+=" ";
        help = help.substr(0, maxWidth);
        res.push_back(help);
        return res;
    }
};
