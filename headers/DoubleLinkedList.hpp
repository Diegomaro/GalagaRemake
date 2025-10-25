#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

template <typename T>
class DoubleLinkedList {
public:
	class Node {
	public:
		T data;
		Node *next;
        Node* prev;
		Node();
		Node(T nData);
	};
	DoubleLinkedList();
	~DoubleLinkedList();
	bool insertHead(T nData);
	bool insertTail(T nData);
	bool deleteHead();
	bool deleteTail();
	bool deleteNode(T nData);
	bool deleteNode(Node* node);
	bool hasNext();
	T &getNextNodeData();
	void addVelToNode(sf::Vector2f velocity);
	bool isEmpty();
	bool clear();
private:
	Node *_head;
	Node *_tail;
	Node *_curNode;
};
#include "DoubleLinkedList.tpp"