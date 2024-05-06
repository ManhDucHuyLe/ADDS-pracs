#include "LinkedList.h"

#include <iostream>
#include <limits>

LinkedList::LinkedList() { head = nullptr; }

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
  for (int i = 0; i < len; ++i) {
    insertPosition(i + 1, array[i]);
  }
}

LinkedList::~LinkedList() {
  Node* current = head;
  while (current != nullptr) {
    Node* next = current->link;
    delete current;
    current = next;
  }
}

void LinkedList::insertPosition(int pos, int newNum) {
  if (pos <= 0) pos = 1;

  Node* newNode = new Node(newNum, head);

  if (head == nullptr || pos == 1) {
    newNode->link = head;
    head = newNode;
  } else {
    Node* current = head;
    int currentPos = 1;
    while (currentPos < pos - 1 && current->link != nullptr) {
      current = current->link;
      ++currentPos;
    }
    newNode->link = current->link;
    current->link = newNode;
  }
}

bool LinkedList::deletePosition(int pos) {
  if (pos <= 0 || head == nullptr) return false;

  Node* current = head;
  Node* previous = nullptr;
  int currentPos = 1;

  while (currentPos < pos && current != nullptr) {
    previous = current;
    current = current->link;
    ++currentPos;
  }

  if (current == nullptr) return false;

  if (previous == nullptr) {
    head = current->link;
  } else {
    previous->link = current->link;
  }

  delete current;
  return true;
}

int LinkedList::get(int pos) {
  if (pos <= 0) return std::numeric_limits<int>::max();

  Node* current = head;
  int currentPos = 1;

  while (currentPos < pos && current != nullptr) {
    current = current->link;
    ++currentPos;
  }

  if (current == nullptr) return std::numeric_limits<int>::max();

  return current->data;
}

int LinkedList::search(int target) {
  Node* current = head;
  int currentPos = 1;

  while (current != nullptr) {
    if (current->data == target) {
      return currentPos;
    }
    current = current->link;
    ++currentPos;
  }

  return -1;
}

void LinkedList::printList() {
  std::cout << "[";
  Node* current = head;
  while (current != nullptr) {
    std::cout << current->data;
    current = current->link;
    if (current != nullptr) {
      std::cout << " ";
    }
  }
  std::cout << "]";
}