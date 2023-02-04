#include<iostream>
#include<vector>
#include<memory>

using namespace std;
/**
 * Definition for singly-linked list.
 **/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* k_ckpt = nullptr;
        ListNode* next_k_ckpt = nullptr;
        ListNode* current = head;
        ListNode* stack = nullptr;
        head = nullptr;
        while(true){
            for(int i=0;i<k;i++)
            {
                    if(i==0){
                        next_k_ckpt = current;
                        stack = nullptr;
                    }
                    if(!current){
                        ListNode *tail  = nullptr;
                        while(stack){
                            ListNode *temp = stack->next;
                            stack->next = tail;
                            tail = stack;
                            stack = temp;
                        }
                        k_ckpt -> next = tail;
                        return head;
                    }

                    ListNode* temp = current -> next;
                    current -> next = stack;
                    stack = current;
                    current = temp;
            }
            if(!head){
                head  = stack;
            }
            else{
                k_ckpt -> next = stack;
            }
            k_ckpt = next_k_ckpt;
        }
    }
};


int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    unique_ptr<ListNode> head(new ListNode());
    auto current = head.get();
    for(auto it=arr.begin(); it<arr.end();it++){
        current->val = *it;
        if(it < arr.end()-1){
            current->next = new ListNode();
        }
        current = current -> next;
    }
    current = head.get();
    while(current){
        cout<<  current->val<< " ";
        current = current->next;
    }
    cout<<endl;

    Solution sol;

    current = sol.reverseKGroup(head.get(), 3);
    while(current){
        cout<<  current->val<< " ";
        current = current->next;
    }
    cout<<endl;

}
