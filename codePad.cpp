#include <iostream>
using namespace std;

// To execute C++, please define "int main()"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x=0): val(x) {}
};

class Solution {
public:
  void deleteNode(ListNode *node) {
    if(node == NULL)
      return;
    
    ListNode *tmp = node -> next;
    node -> val = tmp -> val;
    node -> next = tmp -> next;
    //free(tmp);
    return;
  }
  
  void printList(ListNode *node) {
    while(node) {
      cout << node->val << "->";
      node = node->next;
    }
    cout << "NULL" << endl;
  }
  
  ListNode *reverseList(ListNode *head)
  {
    if(head == NULL) return NULL;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *pre, *cur, *aft;
    pre = &dummy;
    cur = head;
    aft = cur -> next;
    while(aft)
    {
        cur -> next = aft -> next;
        aft -> next = pre -> next;
        pre -> next = aft;
        aft = cur -> next;
    }
    return pre->next;
    
  }
};

int main() {

  const int N = 10;
  ListNode list[N];

  list[0].val = 0;
  for(int i = 1; i < N; ++i)
  {
    list[i] = i;
    list[i-1].next = &list[i];
  }
  list[N-1].next = NULL;
  
  Solution s;
  s.printList(&list[0]);
  s.deleteNode(&list[6]);
  ListNode *head = s.reverseList(list);
  s.printList(head);
  return 0;
}

