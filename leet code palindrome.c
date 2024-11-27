/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdbool.h>
    struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode* left = head;
    struct ListNode* right = head;
    
    while (right != NULL && right->next != NULL) {
        left = left->next;
        right = right->next->next;
    }
    
    return left;
}
  struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* nextNode = NULL;
    
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    return prev;
}  
bool isPalindrome(struct ListNode* head)
 {
    if (head == NULL || head->next == NULL) 
    {
        return true; 
    }
    struct ListNode* middle = findMiddle(head);
    struct ListNode* secondHalf = reverseList(middle);
    struct ListNode* firstHalf = head;
     while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val) {
            return false; // If values do not match, it's not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    
    return true;
}

