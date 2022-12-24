class Solution {
public:
    bool static sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b)
{
        if(a.first>b.first){
            return true;
        }
        else if(a.first==b.first){
            return a.second<b.second;
        }
        else{
            return false;
        }
}
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string,int>positiveMap;
        unordered_map<string,int>negativeMap;
        for(int i=0;i<positive_feedback.size();i++){
            positiveMap[positive_feedback[i]]++;
        }
        for(int i=0;i<negative_feedback.size();i++){
            negativeMap[negative_feedback[i]]++;
        }
        vector<pair<int,int>>score;
        for(int i=0;i<report.size();i++){
            int points=0;
            for(int j=0;j<report[i].size();j++){
                string word="";
                while(j<report[i].size()&&report[i][j]!=' '){
                    word+=report[i][j];
                    j++;
                }
                if(positiveMap.find(word)!=positiveMap.end()){
                    points+=3;
                }
                else if(negativeMap.find(word)!=negativeMap.end()){
                    points=points-1;
                }
            }
            score.push_back({points,student_id[i]});
        }
        vector<int>ranks(k);
        sort(score.begin(),score.end(),sortbysecdesc);
        for(int i=0;i<k;i++){
            ranks[i]=score[i].second;
        }
        return ranks;
    }
};