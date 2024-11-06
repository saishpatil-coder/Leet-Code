#include<iostream>
using namespace std;
class Solution {
public:
    bool isVowel(char c) {
    c = tolower(c); 
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string reverseVowels(string s) {
        int i = 0 , j = s.length()-1 ;
        while(i < j){
            while(i < j && !isVowel(s[i])){
                i++;
            }
            while(i < j && !isVowel(s[j])){
                j--;
            }
            if(i != j){
                char t = s[i] ;
                s[i] = s[j] ;
                s[j] = t ;
            }
            i++;
            j--;
        }
        return s ;
    }
};
int main()
{
    Solution s ;
    cout<<s.reverseVowels("Icecream") ;
    
     
    return 0;
}