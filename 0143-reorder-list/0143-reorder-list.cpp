class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        // find middle

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse nodes

        ListNode* curr = slow->next;
        while (curr->next != nullptr) {
            ListNode* nextPtr = curr->next;
            curr->next = nextPtr->next;
            nextPtr->next = slow->next;
            slow->next = nextPtr;
        }

        // merge

        ListNode* prev = head;
        curr = slow->next;

        while (curr != nullptr) {
            ListNode* nextPrev = prev->next;
            ListNode* nextCurr = curr->next;
            slow->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;

            curr = nextCurr;
            prev = nextPrev;
        }
    }
};