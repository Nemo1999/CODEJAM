/**
 * Definition for singly-linked list.
**/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // test length
        int cnt = 0;
        ListNode * current = head;
        while(current != nullptr){
            cnt++;
            current = current->next;
        }


        //cout<<"cnt :"<< cnt <<endl;
        ListNode* before_head = new ListNode(0, head);
        current = before_head;
        // navigate to the n+1'th node from the end
        for(int i=0;i<cnt-n;i++){
            current = current->next;
        }

        ListNode* temp = current->next;
        if(current->next){
            current->next = current->next->next;
        }

        //free(temp);
        return before_head->next;
    }
};

int main(){
    ListNode* h = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    Solution sol = *(new Solution());
    ListNode* result = sol.removeNthFromEnd(h, 2);
    while(result!= nullptr){
        cout<<result->val<<" ";
        result = result -> next;
    }
    cout<<endl;
}
