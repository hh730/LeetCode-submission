class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>output;
    	sort(intervals.begin(),intervals.end());
    	vector<int>temp=intervals[0];
    	for(int i=0;i<intervals.size();i++){
    		if(intervals[i][0]<=temp[1]){
    			temp[1]=max(intervals[i][1],temp[1]);
    		}
    		else{
    			output.push_back(temp);
    			temp=intervals[i];
    		}
    	}
    	output.push_back(temp);
    	return output;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};