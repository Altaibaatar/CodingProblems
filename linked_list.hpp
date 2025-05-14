#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode* next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode* head;
	SinglyLinkedListNode* tail;

	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head)
			this->head = node;
		else
			this->tail->next = node;

		this->tail = node;
	}
};

void free_singly_linked_list(SinglyLinkedListNode* node) {
	while (node) {
		SinglyLinkedListNode* temp = node;
		node = node->next;

		free(temp);
	}
}

/// <summary>
/// HackerRank
/// Print the Elements of a Linked list
/// </summary>
/// <param name="head"></param>
/// 
/// Usage
//SinglyLinkedList* llist = new SinglyLinkedList();
//int llist_count = 2;
//llist->insert_node(16);
//llist->insert_node(13);
//printLinkedList(llist->head);
void printLinkedList(SinglyLinkedListNode* head) {
	SinglyLinkedListNode* node = head;
	while (node) {
		if (node == nullptr) {
			printf("\n");
			break;
		}

		printf("%d\n", node->data);
		node = node->next;
	}
}