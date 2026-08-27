class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;

        unordered_map<char,int>mp1; // first word every character freq
        unordered_map<char,int>mp2; // same for 2
        for (int i=0; i<word1.size();i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++; // sabhi character ki freq 
        }

        unordered_map<int,char> fr1;// ab freq and char ko key value k term m palt diya 
        unordered_map<int,char>fr2;// kisi freq pr kon konse char h
        // agr word 1 k sabhi char 2 m or 2 k sabhi char 1 m nhi h to close nhi ho sakte 

        for(auto x:mp1){
            if(mp2.find(x.first)==mp2.end()) return false; 
            // agr mp1 k ele mp2 m nhi h to 
            fr1[x.second]++; // freq1 map m freq key ki bhi freq map kri 
        }
        for(auto y:mp2){
             if(mp1.find(y.first)==mp1.end()) return false;
            // agr mp2 k ele mp1 m nhi h to return false
            fr2[y.second]++; // frq2 map m freq key ki bhi freq map kri 
        }

        // ab freq map m frq match kro agr sabhi fr1 freq fr2 mm nhi h to false 
        // same for fr2 freq
        for(auto x:fr1){
            if(fr2.find(x.first)==fr2.end()) return false; // agr fr1 ki frq key fr2 m n ho 
            if(fr1[x.first]!=fr2[x.first]) return false; // agr freq ki bhi freq same n ho to
        }
         for(auto x:fr2){
            if(fr1.find(x.first)==fr1.end()) return false; // agr fr2 ki frq key fr1 m n ho 
            if(fr2[x.first]!=fr1[x.first]) return false; // agr freq ki bhi freq same n ho to
        }
        return true;
    }
};
// agr dono string m jo same char h and dono m char same ho y n ho but freq same h to vo close string h 