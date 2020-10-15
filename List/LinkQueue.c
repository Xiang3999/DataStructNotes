#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
//使用双重指针来修改*ptr,**ptr的值，以达到修改头节点的目的
void Enqueue(ListNode** ptr, int x) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->val = x;
	if ((*ptr) == NULL) {
		(*ptr) = p;
		(*ptr)->next = p;
	}
	else {
		p->next = (*ptr)->next;
		(*ptr)->next = p;
		(*ptr) = p;
	}
}

int Dequeue(ListNode** ptr) {
	if ((*ptr)==NULL) { printf("error"); return 0; }
	else {
		ListNode* p;
		p = (*ptr)->next;
		int temp;
		if (p == (*ptr)) {
			temp = p->val;
			free(*ptr);
			*ptr = NULL;
		}
		else {
			(*ptr)->next = p->next;
			temp = p->val;
			free(p);
		}

		return temp;
	}
}

int main() {
	ListNode* rear;
	ListNode** ptr;
	ptr = &rear;
	rear = NULL;
	Enqueue(ptr,1);
	Enqueue(ptr, 2);
	Enqueue(ptr, 13);
	printf("%d  ", Dequeue(ptr));
	printf("%d  ", Dequeue(ptr));
	printf("%d  ", Dequeue(ptr));
	printf("%d  ", Dequeue(ptr));
	printf("%d  ", Dequeue(ptr));
	return 0;
}
