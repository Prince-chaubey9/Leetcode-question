class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<int> pq;
        unordered_map<int,int> mp; // score and rank
        vector<string> ans(n);
        for (int i = 0; i < score.size(); i++) {
            pq.push(score[i]); // score ko descending m find krne k liy heap m push kia
        }
        int j = 1;
        while(pq.size()>0){
            mp[pq.top()]=j; // score ko rank se map kia 
            j++;
            pq.pop();
        }
        for(int i=0; i<score.size();i++){
            int rank= mp[score[i]]; // rank find ki 
            if(rank==1) ans[i]="Gold Medal";
            else if(rank==2) ans[i]="Silver Medal";
            else if(rank==3) ans[i]="Bronze Medal";
            else{
                ans[i]= to_string(rank);
            }
        }
        return ans;
    }
};