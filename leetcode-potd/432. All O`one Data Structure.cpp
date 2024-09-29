Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.

 

Example 1:

Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output
[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"
 

Constraints:

1 <= key.length <= 10
key consists of lowercase English letters.
It is guaranteed that for each call to dec, key is existing in the data structure.
At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.



class AllOne {
public:
    int mx = -1e9, mn = 1e9;
    string mx_a, mn_b;
    unordered_map<string, int> mp;
    AllOne() {}

    void inc(string key) {
        mp[key]++;
        if (mp[key] >= mx) {
            mx = mp[key];
            mx_a = key;
        }
        updateMinKey();
    }

    void dec(string key) {
        if (mp[key] >= 2) {
            mp[key]--;
            if (mp[key] <= mn) {
                mn = mp[key];
                mn_b = key;
            }
        } else {
            mp.erase(key);
        }
        if (mp.size() > 0) {
            if (key == mx_a || key == mn_b) {
                updateMaxMin();
            }
        } else {
            mx = -1e9;
            mn = 1e9;
            mx_a = "";
            mn_b = "";
        }
    }
    void updateMinKey() {
        mn = 1e9;
        for (auto& it : mp) {
            if (it.second < mn) {
                mn = it.second;
                mn_b = it.first;
            }
        }
    }
     void updateMaxMin() {
        mx = -1e9;
        mn = 1e9;
        for (auto& it : mp) {
            if (it.second >= mx) {
                mx = it.second;
                mx_a = it.first;
            }
            if (it.second <= mn) {
                mn = it.second;
                mn_b = it.first;
            }
        }
    }
    string getMaxKey() {
        return mx_a;
    }

    string getMinKey() {
        return mn_b;
    }
};
