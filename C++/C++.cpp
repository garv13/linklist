// C++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include <string>
#include<conio.h>

using namespace std;	

struct list1
{
	int data;
	struct list1* next;
};
list1 *root;
void menu();
int main()
{
	cout << "enter root node";
	list1 *ptr = new list1;
	cin >> ptr->data;
	ptr->next = NULL;
	root = ptr;
	cout << "root node added successfully ... \n press any key to continue";
	_getch();
	menu();
}

void show()
{
	list1 *node = root;
	while (node->next != NULL)
	{
		cout << node->data << endl;
		node = node->next;
	}
	cout << node->data << endl;
	cout << "press any key to continue.." << endl;
	_getch();
	menu();
}
void insertEnd()
{
	list1 *node = root;
	while (node->next != NULL)
	{
		node = node->next;
		continue;
	}
	list1* newNode = new list1;
	cin >> newNode->data;
	node->next = newNode;
	newNode->next = NULL;
	cout << "added done..." << endl;
	_getch();
	menu();
}
void insertFront() 
{
	list1 *ptr = new list1;
	cin >> ptr->data;
	ptr->next = root;
	root = ptr;
	cout << "added new node ...\n press any key.." << endl;
	_getch();
	menu();
}

void insertPos()
{
	int p;
	cout << "enter position" << endl;
	cin >> p;
	cout << "enter data" << endl;
	list1 *temp = NULL;
	list1 *ptr = new list1;
	cin >> ptr->data;
	for (int i = 0; i < p-2; i++)
			temp = root->next;
	ptr->next = temp->next;
	temp->next = ptr;
	cout << "data added .... " << endl;
	_getch();
	menu();
}

void deleteEnd()
{
	list1 *temp = root;
	list1 *tempv = NULL;
	while (temp->next != NULL)
	{
		tempv = temp;
		temp = temp->next;
	}
	tempv->next = NULL;
	delete(temp);
	cout << "node deleted.." << endl;
	_getch();
	menu();
}

void deleteFront()
{
	list1 *temp = root;
	root = root->next;
	delete(temp);
	cout << "deleted element ... " << endl;
	_getch();
	menu();
}

void deletePos()
{
	int p;
	cout << "enter position" << endl;
	cin >> p;
	list1 *temp = root;
	list1 *tempv = NULL;
	for (int i = 0; i < p - 1; i++)
	{
		tempv = temp;
		temp = root->next;
	}
	tempv->next = temp->next;
	delete(temp);
	cout << "node deleted.." << endl;
	_getch();
	menu();
}

void menu()
{
	cout << "1  insert at end" << endl;
	cout << "2  insert at front" << endl;
	cout << "3  insert at position" << endl;
	cout << "4  delete at end" << endl;
	cout << "5  delete at front" << endl;
	cout << "6  delete at position" << endl;
	cout << "7  Show" << endl;
	int m;
	cin >> m;
	switch (m)
	{
	case 1: {
		insertEnd();
		break;
	}
	case 2: {
		insertFront();
		break;
	}
	case 3: {
		insertPos();
		break;
	}
	case 4: {
		deleteEnd();
		break;
	}
	case 5: {
		deleteFront();
		break;
	}
	case 6: {
		deletePos();
		break;
	}
	case 7: {
		show();
		break;
	}
	default: {
		exit(1);
	}
	};
}