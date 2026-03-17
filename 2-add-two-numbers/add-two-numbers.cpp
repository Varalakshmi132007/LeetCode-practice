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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
        //sum - an empty linnked list
        ListNode* sumHead = nullptr;
        ListNode* sumTail = nullptr;
        
         //p1 &p2
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        //start with carry = 0
        int carry = 0;

        //as long as both p1 and p2 are not null
        while(p1 && p2)
        {
            //find digit
            int digit = p1->val + p2->val;
            digit += carry;

            //update digit and carry
            if(digit>9)
            {
                digit = digit%10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            //append this digit at the end of the ll
            if(sumHead==nullptr){
                sumHead = new ListNode(digit);
                sumTail = sumHead;
            }
            else
            {
                ListNode* newNode = new ListNode(digit);
                sumTail->next = newNode;
                sumTail = newNode;
            }

            //move the pointers ahead
            p1 = p1->next;
            p2 = p2->next;
        }

        //if there are digits left in the p1
        while(p1 )
        {
             //find digit
            int digit = p1->val ;
            digit += carry;

            //update digit and carry
            if(digit>9)
            {
                digit = digit%10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            //append this digit at the end of the ll
            if(sumHead==nullptr){
                sumHead = new ListNode(digit);
                sumTail = sumHead;
            }
            else
            {
                ListNode* newNode = new ListNode(digit);
                sumTail->next = newNode;
                sumTail = newNode;
            }

            //move the pointers ahead
            p1 = p1->next;
        }

        //if there are digits left in p2
        while(p2)
        {
             //find digit
            int digit =  p2->val;
            digit += carry;

            //update digit and carry
            if(digit>9)
            {
                digit = digit%10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            //append this digit at the end of the ll
            if(sumHead==nullptr){
                sumHead = new ListNode(digit);
                sumTail = sumHead;
            }
            else
            {
                ListNode* newNode = new ListNode(digit);
                sumTail->next = newNode;
                sumTail = newNode;
            }

            //move the pointers ahead
            p2 = p2->next;
        }

        //append 1 if carry =1
        if(carry == 1)
        {
            //append this digit at the end of the linkedlist 
             if(sumHead==nullptr){
                sumHead = new ListNode(1);
                sumTail = sumHead;
            }
            else
            {
                ListNode* newNode = new ListNode(1);
                sumTail->next = newNode;
                sumTail = newNode;
            }

        }
        return sumHead;
    }
};    