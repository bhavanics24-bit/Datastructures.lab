
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
    struct ListNode *prevA = list1;
    struct ListNode *afterB = list1;

    // move prevA to node just before index a
    for (int i = 0; i < a - 1; i++) {
        prevA = prevA->next;
    }

    // move afterB to node just after index b
    for (int i = 0; i <= b; i++) {
        afterB = afterB->next;
    }

    // connect list1 to list2
    prevA->next = list2;

    // find tail of list2
    struct ListNode *tail = list2;
    while (tail->next) {
        tail = tail->next;
    }

    // connect tail of list2 to remaining list1
    tail->next = afterB;

    return list1;
}
