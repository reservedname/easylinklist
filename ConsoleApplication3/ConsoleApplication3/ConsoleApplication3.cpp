// ConsoleApplication3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

typedef struct node {
	int ele;
	struct node *next;
}linklist;


//倒序插入
linklist* create_list_1(vector<int> list) {
	linklist *head = nullptr, *t = nullptr;
	auto i = list.begin();

	while (i != list.end()) {
		t = new linklist;
		t->ele = *i;
		t->next = head;
		head = t;
		++i;
	}
	return head;
}

linklist * create_list_2(vector<int> list)
{
	linklist *head = nullptr, *t = nullptr, *s = nullptr;
	auto i = list.begin();
	t = new linklist;
	t->ele = *i;
	head = t;
	s = t;
	++i;

	while (i != list.end()) {
		t = new linklist;
		t->ele = *i;
		s->next = t;
		s = t;
		++i;
	}
	if (s != nullptr) {
		s->next = nullptr;
	}
	return head;
}

int isEmpty(const linklist * head)
{
	if (head == nullptr) return 1;
	return 0;
}

linklist * insert_list(linklist * head, int index, int insert)
{
	linklist* t = new linklist;
	linklist* s = head->next;	//游标
	t->ele = insert;
	if (isEmpty(head)) return t;
	if (head->ele == index)
	{
		t->next = head->next;
		head->next = t;
		return t;
	}
	else
	{
		while (s != nullptr) {
			if (s->ele == index)
			{
				t->next = s->next;
				s->next = t;
				return t;
			}
			else
			{
				s = s->next;
			}
		}
		return nullptr;
	}
}

linklist * push_back_list(linklist * head, int insert)
{
	linklist* t = new linklist;
	t->ele = insert;
	t->next = nullptr;
	if (isEmpty(head)) return t;
	linklist* s = head->next;
	while (s != nullptr) {
		s = s->next;
	}
	s = t;
	return t;
}

linklist * push_head_list(linklist * head, int insert)
{
	linklist* t = new linklist;
	t->ele = insert;
	t->next = head;
	return t;
}

linklist * erase_list(linklist * head, int index)
{
	linklist* t = head->next;
	linklist* pr = head;
	if (isEmpty(head)) return nullptr;
	if (pr->ele == index) {
		delete pr;
		return t;
	}
	while (t != nullptr) {
		if (t->ele == index)
		{
			pr->next = t->next;
			delete t;
			return pr;
		}
		pr = t;
		t = t->next;
	}
	return nullptr;
}

int show_all(const linklist *head)
{
	linklist* t = head->next;
	int count = 0;
	if (isEmpty(head)) cout << "List is Empty" << endl;
	else cout << count++ << " " << head->ele << endl;
	while (t != nullptr) {
		cout << count++ << " " << t->ele << endl;
		t = t->next;
	}
	return 1;
}

int delete_list(linklist * head)
{
	linklist *t = head->next;
	linklist *s = head;
	while (s != nullptr) {
		delete s;
		s = t;
		t = t->next;
	}
	return 1;
}

int main()
{
	vector<int> a = { 0,1,2,3,4,5 };
	linklist* head1 = create_list_1(a);
	linklist* head2 = create_list_2(a);
	show_all(head1);
	cout << "---------------------" << endl;
	show_all(head2);
    return 0;
}

