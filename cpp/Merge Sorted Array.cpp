class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=nums1.size()-1;
        for(int i=m-1;i>=0;i--){
                nums1[j--]=nums1[i];
        }
        j++;
        int k=0,i=0;
        while(i<n&&j<nums1.size()){
            if(nums2[i]<nums1[j]){
                nums1[k++]=nums2[i++];
            }
            else
                nums1[k++]=nums1[j++];
        }
        while(i<n)
            nums1[k++]=nums2[i++];
        while(j<nums1.size()-1)
            nums1[k++]=nums1[j++];
    }
};