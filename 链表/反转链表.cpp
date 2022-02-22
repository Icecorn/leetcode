/*
*总结：反转链表画图就好，无论是迭代还是递归都是固定几步
*1.设一个dummy = nullptr,最后返回的就是它
*2.先保存head->next,  next = head->next
*3.head->next = dummy
*4.dummy = head
*5.head = next
*以上四步首尾相接，完成闭环
*/

#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

//迭代法
ListNode* reverseList1(ListNode* head)
{
    ListNode* dummy = nullptr;
    while(head)
    {
        ListNode* next = head->next;
        head->next = dummy;
        dummy = head;
        head = next;
    }

    return dummy;
};

//递归法
ListNode* reverseList2(ListNode* head,ListNode* prey)
{
    if(!head) return prey;
    ListNode* next = head->next;
    head->next = prey;
    return reverseList2(next,head);
}

int main()
{
    ListNode* ListNode1 =new ListNode(1);
    ListNode* ListNode2 =new ListNode(2);
    ListNode* ListNode3 =new ListNode(3);
    ListNode* ListNode4 =new ListNode(4);
    ListNode* ListNode5 =new ListNode(5);

    ListNode1->next = ListNode2;
    ListNode2->next = ListNode3;
    ListNode3->next = ListNode4;
    ListNode4->next = ListNode5;
    

    //ListNode* res = reverseList1(ListNode1);
    ListNode* prey = nullptr;
    ListNode* res = reverseList2(ListNode1,prey);

    while(res)
    {
        cout<< res->val <<"aaa"<< endl;
        res = res->next;
    }
}
