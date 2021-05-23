class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        vector<int> n1;
        vector<int> n2;
        n1=(nums1.size()<nums2.size()?nums1:nums2);
        n2=(nums1.size()>=nums2.size()?nums1:nums2);
        for(int i=0;i<n1.size();i++){
            auto it=find(n2.begin(),n2.end(),n1[i]);
            if(it!=n2.end()){
                v.push_back(n1[i]);
                n2.erase(it);
            }
        }
        return v;
    }
};