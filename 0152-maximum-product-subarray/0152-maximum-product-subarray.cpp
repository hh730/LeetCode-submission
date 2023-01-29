class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=1;
        int mini=1;
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            int temp=maxi;
            maxi=max(nums[i],max(maxi*nums[i],mini*nums[i]));
            mini=min(nums[i],min(temp*nums[i],mini*nums[i]));
            res=max(res,max(maxi,mini));
        }
        return res;
    }
};