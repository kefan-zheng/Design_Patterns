#include <iostream>
#include <stdexcept>
#include <vector>
#include<list>
#include<stack>
#include<string>
using namespace std;

template<class T>
struct Node {
    T data;
    Node<T>* next;
};
template<class T>
class LinkList 
{
public:
    LinkList()
    {
        header = new Node<T>;
        header->next = NULL;
        count = 0;
    }

    ~LinkList()
    {
        Node<T>* buffer;
        for (Node<T>* p = header; p; p = p->next) {
            buffer = p->next;
            delete p;
            p = buffer;
        }
    }
    unsigned int size() const
    {
        return count;
    }
    void pushBack(T e) {
        Node<T>* p;
        for (p = header; p->next; p = p->next);
        p->next = new Node<T>{ e,NULL };
        ++count;
    }
    void del(unsigned int index) {
        Node<T>* p = header;
        for (int i = 0; i < index; ++i)p = p->next;
        Node<T>* buffer = p->next;
        p->next = buffer->next;
        delete buffer;
        --count;
    }
    T& at(unsigned int index)
    {
        Node<T>* p = header->next;
        for (int i = 0; i < index; ++i)p = p->next;
        return p->data;
    }

private:
    Node<T>* header;
    unsigned int count;
};

