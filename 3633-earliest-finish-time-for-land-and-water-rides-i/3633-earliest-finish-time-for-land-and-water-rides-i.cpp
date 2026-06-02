class Solution {
public:
    int earliestFinishTime(vector<int>& landtime, vector<int>& landduration, vector<int>& watertime, vector<int>& waterduration) {
        int time = 0;
        int min_time = INT_MAX;
        for(int i=0;i<landtime.size();i++){
            for(int j=0;j<watertime.size();j++){
                time =0;
                int t1 = landtime[i];
                int t2 = watertime[j];
                if(t1<t2){
                    time+=(landtime[i]+landduration[i]);
                    if(t2>time){
                        time+=t2-time;
                    }
                    time+=waterduration[j];
                }else{
                    time+=(watertime[j]+waterduration[j]);
                    if(t1>time){
                        time+=t1-time;
                    }
                    time+=landduration[i];
                }
                if(time<min_time){
                    min_time = time;
                }
            }
        }
        return min_time;
    }
};