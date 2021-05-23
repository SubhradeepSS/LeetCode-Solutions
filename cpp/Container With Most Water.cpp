class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxA=min(height[0],height[n-1])*(n-1);
        int l=0,r=n-1;
        while(l<r){
            if(height[l]<height[r]){
                maxA=max(maxA,height[l]*(r-l));
                l++;
            }
            else{
                maxA=max(maxA,height[r]*(r-l));
                r--;
            }
        }
        return maxA;
    }
};