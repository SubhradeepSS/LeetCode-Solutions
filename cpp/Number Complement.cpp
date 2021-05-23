class Solution {
public:
    int findComplement(int N) {
        if(N==0)
            return 1;
        int bit_l=log2(N)+1;
        int ans=pow(2,bit_l)-1;
        return ans^N;
    }
};