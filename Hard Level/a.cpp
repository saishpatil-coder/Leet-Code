#include<iostream>
using namespace std;
class Solution {
public:
    string invert(string a){
        string ans ;
        for(int i = a.length()-1 ; i >= 0 ; i--){
            char temp ;
            string t = "0" ;
            if(a[i] == t[0]){
                temp = '1';
            }else temp = '0' ;
            ans = ans + temp ;
        }
        return ans ;
    }
    char findKthBit(int n, int k) {
        string a = "0" ;
        if(n == 1) return '0';
        while(n-1 > 0){
            a = a + "1" + invert(a) ;
            cout << a <<endl ;
            if(a.length() >k){
                return a[k-1] ;
            }
        }
        char ab = '-';
        return  ab;
    }
};
int main()
{
    Solution s ;
    cout<<s.findKthBit(3,1) ;
     
    return 0;
}