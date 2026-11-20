class Solution {
public:
    vector<vector<string>> ans;
    void helper(string &s, int i, vector<string> &temp){
        if(i==s.size()){ // all character che k ed 
            ans.push_back(temp); // temp ko ans m push kiya 
            return; // return 
        }
        string t="";
        int n=1; // kitni size ki substring banani h 
        while(i+n <= s.size()){
            t= s.substr(i,n); // index i k bad remain string m check krte h 
            string rev= t; // use revers  kia 
            reverse(rev.begin(),rev.end());
            if(t==rev){ // reverse check kiya palindrome h y nhi 
                temp.push_back(t); // temp m push kiya 
                helper(s,i+n,temp); // remaining string m move forward kia 
                temp.pop_back(); // current temp vector se use pop kiya so next substring k sath chekc kr sake 
            }
            n++; // next check substring k size inc kiya 
        }
    }
    vector<vector<string>> partition(string s) { 
        vector<string> temp; // vector jisme current substring ko store kiya 
        helper(s,0,temp);
        return ans;
         }
};