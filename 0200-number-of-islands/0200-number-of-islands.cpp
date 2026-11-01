// brut force 
// this is optimized code isme kis bhi indx ko rivisit nhi kr hr eh 

class Solution {
public:
     unordered_map<int, set<int>> st;
     void helper(vector<vector<char>>& image, int i, int j){
        st[i].insert(j); // current indx ko map m update kia that visited 
        if(i>0 && image[i-1][j]=='1'&& st[i-1].find(j)==st[i-1].end()){
            helper(image,i-1,j);
        } // a same for all 
        if(i<image.size()-1 && image[i+1][j]=='1'&& st[i+1].find(j)==st[i+1].end()){
            helper(image,i+1,j);
        }
        if(j>0 && image[i][j-1]=='1'&& st[i].find(j-1)==st[i].end()){
            helper(image,i,j-1);
        }
         if(j<image[0].size()-1 && image[i][j+1]=='1'&& st[i].find(j+1)==st[i].end()){
            helper(image,i,j+1);
        }
         
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){ // grid k sabhi ele ko check kro 
            for(int j=0; j<m;j++){
                if(grid[i][j]=='1' &&st[i].find(j)==st[i].end()){  // jo indx '1' h aur visit nhi huy means new island 
                    helper(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};