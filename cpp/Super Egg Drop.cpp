class Solution {
public:
    int s(int k,int x,int n){
        int sum=0,r=1;
        for(int i=1;i<=k;++i){
            r*=x-i+1;
            r/=i;
            sum+=r;
            if(sum>=n)
                break;
        }
        return sum;
    }
    int superEggDrop(int K, int N) {
        int l=1,h=N;
        while(l<h){
            int m=(l+h)/2;
            if(s(K,m,N)<N)
                l=m+1;
            else
                h=m;
        }
        return l;
    }
};