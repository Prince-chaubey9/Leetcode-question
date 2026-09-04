class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){ //max  heap m fillkia 
            pq.push(stones[i]);
        }
        while(pq.size()>1){ // heap se top ele ko pick kia and pop kiya 
            int x= pq.top();
            pq.pop();
            int y= pq.top();
            pq.pop();
            int z= abs(x-y); // dono k difference liya 
            if(z!=0) pq.push(z); // use wapas push kiya 
        }
        if(pq.size()==0) return 0;
        return pq.top();
    }
};