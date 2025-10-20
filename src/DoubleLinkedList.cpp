#include <iostream>
#include "DoubleLinkedList.hpp"

DoubleLinkedList::Node::Node(Entity nEntity): entity(nEntity), next(nullptr), prev(nullptr) {}

DoubleLinkedList::DoubleLinkedList(): _head(nullptr), _tail(nullptr) {}

DoubleLinkedList::~DoubleLinkedList() {
	clear();
}

bool DoubleLinkedList::insertHead(Entity nEntity) {
	Node *newNode = nullptr;
	newNode = new(std::nothrow) Node(nEntity);
	if(!newNode)
		return false;

	newNode->next = _head;
	if(_head){
		_head->prev = newNode;
	}
	_head = newNode;
	if(!_head->next){
		_tail = _head;
	}
	return true;
}

bool DoubleLinkedList::insertTail(Entity nEntity){
	Node* newNode = new(std::nothrow) Node(nEntity);
	if(!newNode) return false;
	
	if(!_head){
		_head = newNode;
		_tail = _head;
		return true;
	}
	_tail->next = newNode;
	newNode->prev = _tail;
	_tail = newNode;
    return true;
}

bool DoubleLinkedList::deleteHead(){
	if(!_head){
		return false;
	}
	if(_head == _tail){
		delete _head;
		_head = nullptr;
		_tail = nullptr;
		return true;	
	}
	Node* temp = _head->next;
	temp->prev = nullptr;
	delete _head;
	_head = temp;
	return true;
}

bool DoubleLinkedList::deleteTail(){
	if(!_tail){
		return false;
	}
	if(_head == _tail){
		delete _head;
		_head = nullptr;
		_tail = nullptr;
		return true;
	}

	Node* temp = _tail;
	temp = _tail->prev;
	delete _tail;
	_tail = temp;
	_tail->next = nullptr;
	return true;
}

bool DoubleLinkedList::deleteNode(std::string entityName){
	if(!_head){
		return false;
	}
	if((_head == _tail) && (_head->entity.getTextureKey() == entityName)){
		delete _head;
		_head = nullptr;
		_tail = nullptr;
		return true;
	}
	Node* tmp = _head;
	if(_head->entity.getTextureKey() == entityName){
		tmp = tmp->next;
		delete _head;
		_head = tmp;
		_head->prev = nullptr;
		return true;
	}
	while(tmp->next != nullptr){
		if(tmp->next->entity.getTextureKey() == entityName){
			Node* anchorNode = tmp->next->next;
			delete tmp->next;
			tmp->next = anchorNode;
			if(anchorNode == nullptr){
				_tail = tmp;
			} else{
				anchorNode->prev = tmp;
			}
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

Entity* DoubleLinkedList::getNode(std::string entityName){
	if(!_head){
		return nullptr;
	}
	Node* tmp = _head;
	while(tmp != nullptr){
		if(tmp->entity.getTextureKey() == entityName){
			return &tmp->entity;
		}
		tmp = tmp->next;
	}
	return nullptr;
}

bool DoubleLinkedList::isEmpty(){
	if(_head) return false;
	return true;
}

bool DoubleLinkedList::clear(){
	if(!_head){
		return false;
	}
	Node* index = _head;
	while(index != nullptr){
		index = index->next;
		delete _head;
		_head = index;
	}
	_tail = nullptr;
	return true;
}