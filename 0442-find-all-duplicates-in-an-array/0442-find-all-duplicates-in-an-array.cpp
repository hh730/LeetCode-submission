class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>duplicate;
        for(int i=0;i< nums.size();i++){
            int element=abs(nums[i]);
            if(nums[element-1]<0){
                duplicate.push_back(element);
            }else{
                nums[element-1]=nums[element-1]*-1;
            }
        }
        return duplicate;
    }
};