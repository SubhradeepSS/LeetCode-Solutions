class Solution {
public:
    bool isPowerOfFour(int num) {
        return num&&(ceil(log(num)/log(4))==floor(log(num)/log(4)));
    }
};