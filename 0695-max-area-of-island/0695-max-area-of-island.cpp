class Solution {
public:
      unordered_map<int, set<int>> st;
     int helper(vector<vector<int>>& image, int i, int j){
        st[i].insert(j); // current indx ko map m update kia that visited 
        int ans=0;
        if(i>0 && image[i-1][j]==1&& st[i-1].find(j)==st[i-1].end()){
            ans+=helper(image,i-1,j); // uper bale kitne box h 
        } // a same for all 
        if(i<image.size()-1 && image[i+1][j]==1&& st[i+1].find(j)==st[i+1].end()){
            ans+=helper(image,i+1,j);
        }
        if(j>0 && image[i][j-1]==1&& st[i].find(j-1)==st[i].end()){
           ans+=helper(image,i,j-1);
        }
         if(j<image[0].size()-1 && image[i][j+1]==1&& st[i].find(j+1)==st[i].end()){
            ans+=helper(image,i,j+1);
        }
         // charo trf box count +1 current 
        return ans+1; 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){ // grid k sabhi ele ko check kro 
            for(int j=0; j<m;j++){
                if(grid[i][j]==1 &&st[i].find(j)==st[i].end()){  // jo indx '1' h aur visit nhi huy means new island 
                   count= max(count,helper(grid,i,j));
                    
                }
            }
        }
        return count;
    }
};