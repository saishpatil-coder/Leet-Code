#include<iostream>
using namespace std;
class So
{
    
};
void bin(int n){
    while(n > 0){
        if(n%2 == 1){
            cout<<n%2;
        }
        n /= 2 ;
    }
}
int main()
{
    
    bin(15) ;
    return 0;
}