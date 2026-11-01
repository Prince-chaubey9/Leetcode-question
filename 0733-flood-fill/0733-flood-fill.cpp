class Solution {
public:
    unordered_map<int, set<int>> st;  // yes map of int nad set h jisme kis row k kis colum ko visit kr chuke h store kia h 
    void helper(vector<vector<int>>& image, int i, int j, int color){
        st[i].insert(j); // current indx ko map m update kia that visited 
        if(i>0 && image[i-1][j]==image[i][j]&& st[i-1].find(j)==st[i-1].end()){ // condition chaeck and uper wala already visited n ho 
            helper(image,i-1,j,color);
        } // a same for all 
        if(i<image.size()-1 && image[i+1][j]==image[i][j]&& st[i+1].find(j)==st[i+1].end()){
            helper(image,i+1,j,color);
        }
        if(j>0 && image[i][j-1]==image[i][j]&& st[i].find(j-1)==st[i].end()){
            helper(image,i,j-1,color);
        }
         if(j<image[0].size()-1 && image[i][j+1]==image[i][j]&& st[i].find(j+1)==st[i].end()){
            helper(image,i,j+1,color);
        }
        image[i][j]= color; // all return k bad color ko update kia 
        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        helper(image,sr,sc,color);
        return image;
    }
};