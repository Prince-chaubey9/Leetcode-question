class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans=0;
        unordered_map<int, int> mp; // jo number rabit bol rha use coluor consider kre aur uski frq map ki 
        for(int i=0; i<answers.size();i++){
            if(mp.find(answers[i])==mp.end()){ // jo no batay vo exit nhi krta map m
                ans+=answers[i]+1; //jitne rabit n batay + vo khud
            }
            mp[answers[i]]++; // freq inc kro

            if(mp[answers[i]]==answers[i]+1){ // us group m jitne mx rabit ho sakte h sab mil gye to 
                mp.erase(answers[i]); // unhe hata do , may be use no wale diff colour k dusre rabit age ho unhe alag count krna h 
            }

        }
        return ans;
    }
};

// isme same no k agr us number+1 se jyada freq h means vo alag group honge , us group m mx vo num+1 hi ho sakte h 
