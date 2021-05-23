class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        if(n<3)
            return 0;
        int ans=0,curr=0;
        for(int i=2;i<n;i++){
            if(A[i]-A[i-1]==A[i-1]-A[i-2]){
                curr++;
            }
            else{
                ans+=curr*(curr+1)/2;
                curr=0;
            }
        }
        ans += curr*(curr+1)/2;
        return ans;
    }
};