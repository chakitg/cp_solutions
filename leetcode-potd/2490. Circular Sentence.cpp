class Solution {
public:
    bool isCircularSentence(string sentence) {
        // Step 1: Append a space to handle the last word properly
        sentence += " ";
        
        string s;
        vector<string> v;
        
        // Step 2: Split sentence into words and check conditions
        for (int i = 0; i < sentence.size(); i++) {
            if (!isalpha(sentence[i])) { // End of a word
                if (!v.empty()) {
                    string prev = v.back();
                    if (s[0] != prev[prev.size() - 1]) { // Check continuity
                        return false;
                    }
                }
                v.push_back(s); // Store the current word
                s = ""; // Reset for the next word
            } else {
                s.push_back(sentence[i]); // Build the current word
            }
        }
        
        // Step 3: Check if the first and last words form a circular sequence
        string last = v[v.size() - 1];
        if (v[0][0] != last[last.size() - 1]) return false;
        
        return true;
    }
};
