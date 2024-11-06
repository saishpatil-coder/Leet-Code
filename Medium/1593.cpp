#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    // Function to check if a string already exists in the vector
    bool check(const vector<string>& v, const string& s){
        for(const string& i : v){
            if(s == i) return false;
        }
        return true;
    }
    
    // Recursive function to split the string and maximize unique splits
    int split(const string& s, string t, vector<string>& v, int loc){
        // Base case: if we've processed the entire string
        if(loc >= s.length()) {
            for(string i : v){
                cout << i << " ";
            }
            cout << endl;
            return v.size();
        }
        
        int length = 0;
        
        // If the temporary string `t` is non-empty, try splitting here
        if(!t.empty()){
            if(check(v, t)){   // Check if the substring `t` is unique
                v.push_back(t); // Push the unique substring
                t = "";         // Reset `t`
                int l = split(s, t + s[loc], v, loc + 1); // Recurse with next character
                length = max(l, length);
                v.pop_back();  // Backtrack after recursion
            }
        }
        
        // Try adding the current character to the temp string `t`
        length = max(split(s, t + s[loc], v, loc + 1), length);
        
        return length;
    }
    
    // Function to start the process of finding the maximum unique splits
    int maxUniqueSplit(string s) {
        vector<string> v;
        string temp = "";
        return split(s, temp, v, 0);
    }
};

int main() {
    Solution s;
    cout << "Max unique splits: " << s.maxUniqueSplit("addbsd") << endl;
    return 0;
}
