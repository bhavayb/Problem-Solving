/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> mpp;
        if(head == nullptr) return false;
        ListNode* temp = head;
        mpp[temp] = true;
        temp = temp->next;
        while(temp != nullptr){
            if(mpp.find(temp) == mpp.end()){
                mpp[temp] = true;
                temp = temp->next;
            }else{
                return true;
            }
        }
        return false;
    }
};