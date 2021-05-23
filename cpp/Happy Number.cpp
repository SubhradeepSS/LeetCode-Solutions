class Solution {
public:
    int sq(int n){
        int r=0;
        while(n){
            r+=(n%10)*(n%10);
            n/=10;
        }
        return r;
    }
    bool isHappy(int n) {
        int slow=n,fast=n;
        do{
            slow=sq(slow);
            fast=sq(sq(fast));
        }while(slow!=fast);
        return (slow==1);
    }
};