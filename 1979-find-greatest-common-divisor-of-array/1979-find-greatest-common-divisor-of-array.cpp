class Solution {
public:
    int gcdFinder(int num1,int num2){
        int result=min(num1,num2);
        while(result>0){
            if(num1%result==0&&num2%result==0){
                break;
            }
            result--;
        }
        return result;
    }
    int findGCD(vector<int>& nums) {
        int smallestNumber=INT_MAX;
        int largestNumber=INT_MIN;
        for(int i=0;i<nums.size();i++){
            smallestNumber=min(smallestNumber,nums[i]);
            largestNumber=max(largestNumber,nums[i]);
        }
        return gcdFinder(smallestNumber,largestNumber);
    }
};