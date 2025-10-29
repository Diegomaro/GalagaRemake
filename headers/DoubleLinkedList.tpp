#include "DoubleLinkedList.hpp"

template <typename T>
DoubleLinkedList<T>::Node::Node(): next(nullptr), prev(nullptr) {};


template <typename T>
DoubleLinkedList<T>::Node::Node(T nData): data(nData), next(nullptr), prev(nullptr) {}
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(): _head(nullptr), _tail(nullptr), _curNode(nullptr) {}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
	clear();
}

template <typename T>
bool DoubleLinkedList<T>::insertHead(T nData) {
	Node *newNode = nullptr;
	newNode = new(std::nothrow) Node(nData);
	if(!newNode) return false;
	newNode->next = _head;
	if(_head){
		_head->prev = newNode;
		if(_head == _curNode) _curNode = _head->prev;
	}
	_head = newNode;
	if(!_head->next){
		_tail = _head;
		_curNode = _head;
	}
	_curNode = _head;
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::insertTail(T nData){
	Node* newNode = new(std::nothrow) Node(nData);
	if(!newNode) return false;

	if(!_head){
		_head = newNode;
		_tail = _head;
		_curNode = _head;
		return true;
	}
	_tail->next = newNode;
	newNode->prev = _tail;
	_tail = newNode;
    return true;
}

template <typename T>
bool DoubleLinkedList<T>::deleteHead(){
	if(!_head){
		return false;
	}
	if(_head == _tail){
		delete _head;
		_head = nullptr;
		_tail = nullptr;
		_curNode = nullptr;
		return true;
	}
	Node* temp = _head->next;
	temp->prev = nullptr;
	if(_curNode == _head) _curNode = _head->next;
	delete _head;
	_head = temp;
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::deleteTail(){
	if(!_tail){
		return false;
	}
	if(_head == _tail){
		delete _head;
		_head = nullptr;
		_tail = nullptr;
		_curNode = nullptr;
		return true;
	}
	if(_curNode == _tail) _curNode = nullptr;
	Node* temp = _tail->prev;
	delete _tail;
	_tail = temp;
	_tail->next = nullptr;
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::deleteNode(T nData){
	if(!_head){
		return false;
	}
	if((_head == _tail) && (_head->data == nData)){
		delete _head;
		_head = nullptr;
		_tail = nullptr;
		_curNode = nullptr;
		return true;
	}

	Node* tmp = _head;
	if(_head->data == nData){
		tmp = tmp->next;
		if(_curNode == _head) _curNode = _head->next;
		delete _head;
		_head = tmp;
		_head->prev = nullptr;
		return true;
	}
	while(tmp->next != nullptr){
		if(tmp->next->data == nData){
			Node* anchorNode = tmp->next->next;
			if(_curNode == tmp->next) _curNode = tmp->next->next;
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

template <typename T>
bool DoubleLinkedList<T>::deleteNode(Node* node){
	if(!node){
		return false;
	}
	if(!node->prev){
		return deleteHead();
	}
	if(!node->next){
		return deleteTail();
	}
	if(node == _curNode) _curNode = _curNode->next;
	Node* prevNode = node->prev;
	Node* nextNode = node->next;
	delete node;
	prevNode->next = nextNode;
	nextNode->prev = prevNode;
	return true;
}


template <typename T>
bool DoubleLinkedList<T>::hasNext(){
	if(_curNode) return true;
	_curNode = _head;
	return false;
}


template <typename T>
T &DoubleLinkedList<T>::getNextNodeData(){
	Node* tmp = _curNode;
	_curNode = _curNode->next;
	return tmp->data;
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty(){
	if(_head) return false;
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::clear(){
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
	_curNode = nullptr;
	return true;
}