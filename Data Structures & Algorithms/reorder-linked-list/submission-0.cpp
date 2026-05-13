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

    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            ListNode* front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* l1 = head;
        ListNode* l2 = reverse(slow);

        ListNode dummy(0);
        ListNode* tail = &dummy;

        int cnt = 0;

        while(l1 && l2){
            if(cnt % 2 == 0){
                tail -> next = l1;
                l1 = l1 -> next;
            }
            else{
                tail -> next = l2;
                l2 = l2 -> next;
            }
            cnt++;
            tail = tail -> next;
        }
    }
};
