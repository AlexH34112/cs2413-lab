// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
      struct ListNode *a = head;
      struct ListNode *b = head->next;
      struct ListNode *rest = b->next;

      struct ListNode *newhead = b;

      b->next = a;
      a->next = rest;

      struct ListNode *Ltale = a;
    while (rest != NULL && rest->next != NULL) {
      a = rest;
      b = a->next;
      rest = b->next;
      Ltale->next = b;
      b->next = a;
      a->next = rest;
      Ltale = a;
    }

    return newhead;
}