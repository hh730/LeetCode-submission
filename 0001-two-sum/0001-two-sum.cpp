class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        int size=nums.size();
        for(int i=0;i<size;i++){
            m[nums[i]]=i;
        }
        vector<int>ans;
        for(int i=0;i<size;i++){
            int find=target-nums[i];
            if(m[find]&&m[find]!=i){
                ans.push_back(i);
                ans.push_back(m[find]);
                break;
            }
        }
        return ans;
    }
};