class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int maxi = 1;
        // take every point and find the slope with other points
        for(int i = 0; i < n-1; i++){
            // declare a map which will store the frequency of each slope
            unordered_map<double, int> mp;
            int temp_max = 0;
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1; j < n; j++){                
                int x2 = points[j][0];
                int y2 = points[j][1];
                double nume = y2 - y1;
                double deno = x2 - x1;
                // if denominator will be zero then slope will be INT_MAX
                if(deno == 0){
                    mp[INT_MAX]++;
                    // update temp_max
                    temp_max = max(temp_max, mp[INT_MAX]);
                    continue;
                }
                // find the slope and update frequency
                double slope = nume / deno;
                mp[slope]++;
                temp_max = max(temp_max, mp[slope]);
            }
            // update maxi
            maxi = max(maxi, temp_max + 1);
        }
        return maxi;
    }
};