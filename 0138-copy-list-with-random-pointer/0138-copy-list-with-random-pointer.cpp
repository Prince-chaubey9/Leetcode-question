 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* copy =new Node(NULL);
        Node* temp = head;
        Node* tempC= copy;
        unordered_map<Node*,Node*> mp;// first node is original list node and second node is colpy list node

        while(temp){
            Node*n= new Node(temp->val);// new node original node ki value k sath
            tempC->next=n; // new node ko copy list m add kia 
            mp[temp]=n; // original node ko new node k sath map kia 
            temp=temp->next; // original ko next kia
            tempC=tempC->next; // copy ko last node of copy list pr bheja 
        }

        for(auto x:mp){

            Node* a= x.first; // original node from map
            Node* b= x.second; // copy list node from map
            if(a->random!=NULL){// agr original k random null nhi h to 
                Node* Oran= a->random; // original k random find kia 
                Node* Dran= mp[Oran]; // original random map m key k form m hoga use call krenge to copy list se node mil jaygi jo copy m random hogi current node ki 
                b->random=Dran;
            }

        }
        return copy->next;
    }
};