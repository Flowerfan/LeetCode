#include<iostream>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 //MY SOLUTION
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL)
			return NULL;
		int list_len = 1;
		ListNode *ss = head->next;
		while (ss != NULL) {
			list_len++;
			ss = ss->next;
		}
		if (n > list_len)
			return NULL;
		else if (n == list_len)
			return head->next;
		int m = list_len - n;
		ss = head;
		ListNode *curr;
		while (--m != 0)
			ss = ss->next;
		curr = ss->next->next;
		ss->next = curr;
		return head;
	}
};

/* 4ms solution
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* p = new ListNode(0);
		p->next = head;
		ListNode* q = p;
		while (n--) head = head->next;
		while (head != NULL)
		{
			head = head->next;
			q = q->next;
		}
		head = q->next;
		q->next = q->next->next;
		delete head;
		head = p->next;
		delete p;
		return head;
	}
};
*/
