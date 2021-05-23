class Solution {
public:
    bool isPowerOfThree(int n) {
        // double x=log(n)/log(3);
        int a=pow(3,19);
        return (
            (n>0)&&
            (
                a%n==0
            )
        );
    }
};