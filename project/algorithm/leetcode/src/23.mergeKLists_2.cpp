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
private:
    ListNode* merge(ListNode *a,ListNode *b){
        ListNode* ans=nullptr;
        if(a!=nullptr&&b!=nullptr){
            if(a->val<=b->val){ans = a;a = a->next;}
            else{ans = b;b = b->next;}
        }
        else if(a!=nullptr){ans = a;a = a->next;}
        else if(b!=nullptr){ans = b;b = b->next;}
        else{return nullptr;}
        ListNode* node = ans;
        while(a!=nullptr && b!=nullptr){
            if(a->val<=b->val){node->next = a;node = a;a = a->next;}
            else{node->next = b;node = b;b = b->next;}
        }
        if(a!=nullptr){node->next = a;}
        else{node->next = b;}
        return ans;
    }
    ListNode* mergeLists(vector<ListNode*>& lists,int start,int end){
        int n = lists.size();
        if(start == end){return nullptr;}
        else if(end - start == 1){return lists[start];}
        else if(end - start == 2){return merge(lists[start],lists[start+1]);}
        int mid = (start+end)>>1;
        return merge(mergeLists(lists,start,mid),mergeLists(lists,mid,end));
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){return nullptr;}
        return mergeLists(lists,0,lists.size());
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
//     ListNode* ans = s.mergeKLists(v);
//     return 0;
// }