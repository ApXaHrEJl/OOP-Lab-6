#ifndef H_LISTS
#define H_LISTS
#include <cstddef>

class List 
{
protected:
    int key;
public:
    static int values[];
    static int check(int value, int value2);
    List(int value = 0) : key(value) {}
    virtual void pop();
    virtual void add(int* value);
    virtual ~List();
};

class Queue : public List
{
private:
    Queue* next;
public:
    Queue(int value = 0, Queue* pointer = NULL) : List(value), next(pointer) {}
    Queue(int* value, Queue* pointer = NULL) : List(*value), next(pointer) {}
    virtual void pop();
    virtual void add(int* value);
    virtual ~Queue();
    void shift();
};

class Stack : public List
{
private:
    Stack* next;
public:
    Stack(int value = 0, Stack* pointer = NULL) : List(value), next(pointer) {}
    Stack(int* value, Stack* pointer = NULL) : List(*value), next(pointer) {}
    virtual void pop();
    virtual void add(int* value);
    virtual ~Stack();
};

#endif
