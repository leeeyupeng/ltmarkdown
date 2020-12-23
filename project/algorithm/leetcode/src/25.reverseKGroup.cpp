/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include"leetcode.h"
#include"leetcodenode.h"
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* left=nullptr;
        ListNode* right = nullptr;
        ListNode* l = nullptr;
        ListNode* r = nullptr;

        ListNode* node = nullptr;

        ListNode* ll = nullptr;
        ListNode* rr = nullptr;

        int counter = k;

        right = head;
        head = nullptr;
        while(right != nullptr){
            counter = k;
            node = right;
            while(counter>0 && node != nullptr){
                node = node->next;
                counter--;
            }
            
            if(counter == 0){
                l = right;
                r = right;
                ll = right;
                rr = right->next;
                right->next = nullptr;
                right = node;
                while(rr!=right){
                    l = rr;
                    node = rr->next;                    
                    rr->next = ll;
                    ll = rr;
                    rr = node;                    
                }

                if(left==nullptr){
                    head = l;
                }
                else{
                    left->next = l;
                }
                
                left = r;                
            }
            else{
                left->next = right;
                right = nullptr;
            }
        }

        return head;
    }
};

// int main(){
//     Solution solution;
//     ListNode* head;
//     head = new ListNode(1);
//     ListNode* node = head;
//     node->next = new ListNode(2);
//     node = node->next;
//     node->next = new ListNode(3);
//     node = node->next;
//     node->next = new ListNode(4);
//     node = node->next;
//     // node->next = new ListNode(5);
//     // node = node->next;
//     node = solution.reverseKGroup(head,1);

//     return 0;
// }