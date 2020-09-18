#include"leetcode.h"

 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [=](ListNode* a,ListNode* b){if(a->val == b->val){return a<b;}return a->val>b->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> q(cmp);
        int n = lists.size();
        for(int i = 0; i < n; i ++){
            if(lists[i]!= NULL){
                q.push(lists[i]);
            }
        }
        
        ListNode* ans = NULL;
        if(!q.empty()){ans = q.top();q.pop();if(ans->next!=NULL){q.push(ans->next);} }
        else{return NULL;}
        ListNode* node = ans;
        while(!q.empty()){
            node->next = q.top();q.pop();node = node->next;if(node->next!=NULL){q.push(node->next);} 
        }
        if(node!=NULL){
            node->next=NULL;
        }
        return ans;
    }
};

// int main(){
//     Solution s;
//     vector<ListNode*> v(3);
//     v[0] = new ListNode(1);
//     v[0]->next = new ListNode(4);
//     v[0]->next->next = new ListNode(5);
//     v[1] = new ListNode(1);
//     v[1]->next = new ListNode(3);
//     v[1]->next->next = new ListNode(4);
//     v[2] = new ListNode(2);
//     v[2]->next = new ListNode(6);
//     s.mergeKLists(v);
//     return 0;
// }