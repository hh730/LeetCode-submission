class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1){
            return s;
        }
        vector<string>rows(numRows);
        int j=0,d=0;
        for(int i=0;i<s.size();i++){
            rows[j]+=s[i];
            if(j==numRows-1){
                d=-1;
            }
            else if(j==0){
                d=1;
            }
            j+=d;
        }
        string zigzag="";
        for(int i=0;i<numRows;i++){
            zigzag+=rows[i];
        }
        return zigzag;
    }
};