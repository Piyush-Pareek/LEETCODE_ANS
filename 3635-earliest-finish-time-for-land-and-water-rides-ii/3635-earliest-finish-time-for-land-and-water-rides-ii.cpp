class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<pair<int,pair<int,int>>>num1;
        vector<pair<int,pair<int,int>>>num2;
        for(int i=0;i<landStartTime.size();i++){
            num1.push_back({landStartTime[i]+landDuration[i],{landStartTime[i],i}});
         
        }
         for(int i=0;i<waterStartTime.size();i++){
            num2.push_back({waterStartTime[i]+waterDuration[i],{waterStartTime[i],i}});
        }
        sort(num1.begin(),num1.end());
        sort(num2.begin(),num2.end());
        int time=0;
        int min_time =INT_MAX;
        for(int i=0;i<waterDuration.size();i++){

        if(num1[0].second.first>num2[i].second.first){
            time = num2[i].second.first+waterDuration[num2[i].second.second];
            if(time<num1[0].second.first) time+= (num1[0].second.first-time);time+=landDuration[num1[0].second.second];

        }else{
            time = num1[0].second.first+landDuration[num1[0].second.second];
            if(time<num2[i].second.first) time+= (num2[i].second.first-time);time+=waterDuration[num2[i].second.second];
        }
        min_time = min(time,min_time);
        }
for(int i=0;i<landDuration.size();i++){

        if(num1[i].second.first>num2[0].second.first){
            time = num2[0].second.first+waterDuration[num2[0].second.second];
            if(time<num1[i].second.first) time+= (num1[i].second.first-time);time+=landDuration[num1[i].second.second];

        }else{
            time = num1[i].second.first+landDuration[num1[i].second.second];
            if(time<num2[0].second.first) time+= (num2[0].second.first-time);time+=waterDuration[num2[0].second.second];
        }
        min_time = min(time,min_time);
        }
        return min_time;
    }
};