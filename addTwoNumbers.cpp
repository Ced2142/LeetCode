/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */ class Solution { public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
  ListNode* sumHead;
  int carr = 0;
  if((l1->val+l2->val)/10==0){
    sumHead = new ListNode(l1->val+l2->val);
  } else {
    sumHead = new ListNode((l1->val+l2->val)%10);
    carr = (l1->val+l2->val)/10;
}
  ListNode* currNode = sumHead;
  while((l1->next!=NULL||l2->next!=NULL) || carr!=0){
    currNode->next = new ListNode(0);
    currNode = currNode->next;
    if(l1->next!=NULL&&l2->next==NULL){
      l1 = l1->next;
      currNode->val = (l1->val+carr)%10;
      carr=(l1->val+carr)/10;
    }
    else if(l2->next!=NULL&&l1->next==NULL){
      l2=l2->next;
      currNode->val = (l2->val+carr)%10;
      carr=(l2->val+carr)/10;
    }else if(l1->next!=NULL&&l2->next!=NULL){
      l1 = l1->next;
      l2 = l2->next;
      if((l1->val+l2->val+carr)/10==0){
        currNode->val = l1->val+l2->val+carr;
        carr=0;
      } else {
        currNode->val = ((l1->val+l2->val+carr)%10);
        carr = (l1->val+l2->val+carr)/10;
      }
    }else {
      currNode->val = carr;
      carr = 0;
    }
    }
return sumHead;
        
        
        
    }
};
