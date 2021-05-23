class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return double(1);
        double half=myPow(x,n/2);
        if(n%2==0)
            return half*half;
        if(n<0)
            return double(half*half)/double(x);
        return x*half*half;
    }
};