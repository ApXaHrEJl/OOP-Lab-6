#include "lists.h"
#include <iostream>
#include <cstddef>

int List::check(int value, int value2)
{
    try {
        if (value == value2) {
            throw -1;
        }    
    }
    catch (int) {
    std::cerr << "Ошибка: невозможно взять элемент из пустого списка!" << std::endl;  
    return -1;    
    }
    return 0;
}

void Queue::shift()
{
    key = next->key;
    if (next->next != NULL) {
        next->shift();
    } else {
        delete next;
        next = NULL;
    }  
}

void Queue::pop() 
{ 
    if (check(key, 0) == -1) {
        return;
    }   
    std::cout << "Из очереди взят элемент " << key << std::endl;
    if (next != NULL) {
        shift();
    } else {
        key = 0;
    }
}

void Stack::pop() {
    if (next != NULL) {
        next->pop();
        if (next->key == 0) {
            delete next;
            next = NULL;
        }
    return;
    }
    if (check(key, 0) == -1) {
        return;
    }   
    std::cout << "Из стека взят элемент " << key << std::endl;  
    key = 0;  
}

void Queue::add(int* value) 
{
    if (next != NULL) {
        next->add(value);
        return;
    }
    if (key == 0) {
        key = *value;
        return;
    }
    Queue* child = new Queue(value);
    next = child;
}

void Stack::add(int* value) 
{
    if (next != NULL) {
        next->add(value);
        return;
    }
    if (key == 0) {
        key = *value;
        return;
    }
    Stack* child = new Stack(value);
    next = child;
}

int List::values[9] = {20, 30, 40, 50, 60, 70, 80, 90, 100};

List::~List() {}

Queue::~Queue() {}

Stack::~Stack() {}

void List::pop() {}

void List::add(int* value) {}
