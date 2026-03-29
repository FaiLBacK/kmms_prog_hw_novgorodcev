#include "doubly_linked_list.hpp"

#include <iostream>

using Nov::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	while (begin){
		Node* tmp = begin;
		begin = begin->next;
		delete tmp;
	}
	
}

template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
	std::size_t length = 0;
	Node* current = begin;
	while (current){
		++length;
		current = current->next;
	}
	return length;
}

template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
	for(Node* current = begin; current; current = current->next){
		if(current->value == value){
			return true;
		}
	}
	return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
	Node* current = begin;
	while (current){
		std::cout << current->value;
		if (current->next){
			std::cout << ", ";
		}
		current = current->next;
	}
	std::cout << endl;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	Node* NewNode = new Node(value);
	if (end == nullptr){
		begin = NewNode;
		end = NewNode;
	}
	else{
		end->next = NewNode;
		NewNode->prev = end;
		end = NewNode;
	}
	
}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
	if (!begin) return false;
	
	Node* cur = begin;
	while(cur && cur->value != value){
		cur = cur->next;
	}
	
	if(!cur) return false;
	
	if(cur->prev){
		cur->prev->next = cur->next;
	}
	else{
		begin = cur-> next;
	}
	
	if(cur->next){
		cur->next->prev = cur->prev;
	}
	else{
		end = cur->prev;
	}
	
	delete cur;
	
	return true;
}
