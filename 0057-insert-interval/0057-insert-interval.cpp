class Solution {
public:
    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     vector<vector<int>>output;
    // 	sort(intervals.begin(),intervals.end());
    // 	vector<int>temp=intervals[0];
    // 	for(int i=0;i<intervals.size();i++){
    // 		if(intervals[i][0]<=temp[1]){
    // 			temp[1]=max(intervals[i][1],temp[1]);
    // 		}
    // 		else{
    // 			output.push_back(temp);
    // 			temp=intervals[i];
    // 		}
    // 	}
    // 	output.push_back(temp);
    // 	return output;
    // }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // intervals.push_back(newInterval);
        // return merge(intervals);
        vector<vector<int>>ans;
        for(auto &&i:intervals){
    //  the new interval is after the range of other interval
            if(i[1]<newInterval[0])ans.push_back(i);
    // the new interval's range is before the other
            else if(newInterval[1]<i[0]){
                ans.push_back(newInterval);
                newInterval=i;//updating the new interval
            }
    // the new interval is in the range of the other interval
            else{
                newInterval[0]=min(newInterval[0],i[0]);
                newInterval[1]=max(newInterval[1],i[1]);
            }    
        }
    //At the end after the loop just add the updated newIntervals
        ans.push_back(newInterval);
        return ans;
    }
};