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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL || head -> next == NULL) return NULL;

        ListNode* temp = head;
        int cnt = 0;

        while(temp){
            cnt++;
            temp = temp -> next;
        }

        // head
        if(cnt == n){
            ListNode* newHead = head;
            head = head -> next;
            delete newHead;

            return head; 
        }
        
        temp = head;
        for(int i=0 ; i<cnt-n-1; i++){
            temp = temp -> next;
        }

        ListNode* dlt = temp -> next;
        temp -> next = temp -> next -> next;
        delete dlt;

        return head;
    }
};
