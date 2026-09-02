class Solution {
public:
    void push(int val, vector<int>& v) { // push fun , push values maintainig heap condition
        v.push_back(val);
        int i = v.size() - 1;
        int parent = (i - 1) / 2;
        while (v[i] < v[parent]) {
            swap(v[i], v[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
        return;
    }
    void pop(vector<int>& v) { // pop values from heap 
        swap(v[0],v[v.size()-1]);
        v.pop_back();
        int i=0;
        while(true){
            int lft= i*2+1;
            int rt=i*2+2;
            if(lft>=v.size()) break; // agr left child nhi h to vo leaf node h 
            if(rt>=v.size()){ // agr right child nhi h to left check kro and break kro
                if(v[i]>v[lft]) swap(v[i],v[lft]);
                break;
            }
            if(v[lft]<v[rt]&& v[i]>v[lft]){ // dono child h to lft or rt m se jo chhota ho usase compare kro and swap kia  
                swap(v[i],v[lft]);
                i=lft;
            }else if(v[i]>v[rt]){
                swap(v[i],v[rt]);
                i=rt;
            }else {
                break; // agr kisi k sath swap nhi hua means sahi jgh h 
            }
        }
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> v;// made a temporary vector it will work as heap

        for (int i = 0; i<nums.size(); i++) { // all values to that 
            push(nums[i], v);
        }
        for (int i = 0; i < nums.size(); i++) { // take all values from that
            nums[i] = v[0];
            pop(v);
        }
        return nums;
    }
};