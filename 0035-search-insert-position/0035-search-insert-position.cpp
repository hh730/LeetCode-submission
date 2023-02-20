class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos=-1;
        int low=0;
        int high=nums.size();
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>target){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};