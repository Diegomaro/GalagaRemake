#pragma once
#include "Entity.hpp"

class DoubleLinkedList {
public:
	class Node {
	public:
		Entity entity;
		Node *next;
        Node* prev;
		Node();
		Node(Entity nEntity);
	};
	DoubleLinkedList();
	~DoubleLinkedList();
	bool insertHead(Entity nEntity);
	bool insertTail(Entity nEntity);
	bool deleteHead();
	bool deleteTail();
	bool deleteNode(std::string entityName);
	Entity* getNode(std::string entityName);
	bool isEmpty();
	bool clear();
private:
	Node *_head;
	Node *_tail;
};