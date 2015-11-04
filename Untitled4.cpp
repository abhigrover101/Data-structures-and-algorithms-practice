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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        ListNode *start=head,*current=head,*prev=head;

        while(current!=NULL)
        {
            flag=0;
            while(current->next && start->val==current->next->val)
            {
                current=current->next;
                flag=1;
            }

            if(flag==0)
            {
                prev->next=start;
                prev=start;
                start=current->next;
            }

            if(flag==1 && start->val==head->val)
            {
                head=current->next;
                prev=current->next;
            }
            else if(flag==1 && start->val!=head->val)
            {
                prev->next=current->next;
                start=current->next;
            }
            else if(flag==1 && )
            {
                prev->next=current->next;
                prev=current->next;
            }
            start=current->next;

        }
    }
};
