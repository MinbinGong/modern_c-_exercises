struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *n) : val(x), next(n) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode *dummy = new ListNode(0, head);
  ListNode *first = head;
  ListNode *second = dummy;
  for (int i = 0; i < n; ++i) {
    first = first->next;
  }
  while (first) {
    first = first->next;
    second = second->next;
  }
  second->next = second->next->next;
  ListNode *ans = dummy->next;
  delete dummy;
  return ans;
}