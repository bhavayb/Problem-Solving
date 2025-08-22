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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* temp = head;
        stack <int> st;
        while(temp != nullptr){
            st.push(temp->val);
            temp = temp->next;
        }
        //if(st.empty()) return nullptr;
        ListNode* newhead= new ListNode(st.top());
        // newhead->prev = nullptr;
        st.pop();
        // newhead->next = new DLL(st.top());
        ListNode* x = newhead;
        while(!st.empty()){
            ListNode* node = new ListNode(st.top());
            st.pop();
            // node->prev = x;
            x->next = node;
            x = node;
        }
        return newhead;
    }
};