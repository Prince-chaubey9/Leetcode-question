/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void helper(Node* node,unordered_map<Node*,Node*>&mp){ // sabhi purani nod k iy new node baniy aur use map m store kia ki kis node ki new node konsi h 
        if(node==NULL) return ;
        Node* temp= new Node(node->val); // new temp node create ki 
        mp[node]= temp; // map m assign ki 
        for(auto x:node->neighbors){ // neighbors check kiy kis kis ki new node create honi h 
            if(mp.find(x)==mp.end()){  // agr x th neighbors ki new node nhi bani h to 
                helper(x,mp);
            }
        }
        return ;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*>mp;
        helper(node, mp);
        for(auto x:mp){ // mp se original node ko access kia 
            vector<Node*> temp; // original node k neighbors ko access kia 
            temp= x.first->neighbors; // 
            vector<Node*> n; // new node k liy neoghbors k liy vector creat kia 
            for(auto i:temp){ // original k neighbors ko iterate kia 
                n.push_back(mp[i]); // un node k liy map m jo new  nodes created h unhe new node k neighbors vector m push kia 
            }
            x.second->neighbors=n; // new node k neighbors ko n vector diya 
        }
        return mp[node]; // mp m node indx k liy jo vlue store h vah new node h 
        
    }
};