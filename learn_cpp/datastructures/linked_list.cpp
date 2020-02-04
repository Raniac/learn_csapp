#include <iostream>

using namespace std;

// =================================
// Implementing a Singly Linked List

class StringNode {
private:
    string elem;
    StringNode* next;

    friend class StringLinkedList;
};

class StringLinkedList {
public:
    StringLinkedList(); // constructor
    ~StringLinkedList(); // destructor
    // const: member objects are immutable
    // https://www.cnblogs.com/flyinggod/p/7853082.html
    bool empty() const;
    const string& front() const;
    void addFront(const string& e);
    void removeFront();
private:
    StringNode* head;
};

StringLinkedList::StringLinkedList()
    // : is used for Member Initialization List
    // https://blog.csdn.net/lws123253/article/details/80368047
    : head(NULL) {}

StringLinkedList::~StringLinkedList() {
    while (!empty()) removeFront();
}

bool StringLinkedList::empty() const {
    return head == NULL;
}

const string& StringLinkedList::front() const {
    return head->elem;
}

void StringLinkedList::addFront(const string& e) {
    StringNode* v = new StringNode;
    // new is used to allocate memory for object
    // https://www.cnblogs.com/chris-cp/p/3578976.html
    v->elem = e;
    v->next = head;
    head = v;
}

void StringLinkedList::removeFront() {
    StringNode* old = head;
    head = old->next;
    delete old;
}

//=================================

// =========================================
// Implementing a Generic Singly Linked List

template <typename E>
class SNode {
private:
    E elem;
    SNode<E>* next;

    friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList {
public:
    SLinkedList(); // constructor
    ~SLinkedList(); // destructor
    // const: member objects are immutable
    // https://www.cnblogs.com/flyinggod/p/7853082.html
    bool empty() const;
    const E& front() const;
    void addFront(const E& e);
    void removeFront();
private:
    SNode<E>* head;
};

template <typename E>
SLinkedList<E>::SLinkedList()
    // : is used for Member Initialization List
    // https://blog.csdn.net/lws123253/article/details/80368047
    : head(NULL) {}

template <typename E>
SLinkedList<E>::~SLinkedList() {
    while (!empty()) removeFront();
}

template <typename E>
bool SLinkedList<E>::empty() const {
    return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const {
    return head->elem;
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {
    SNode<E>* v = new SNode<E>;
    // new is used to allocate memory for object
    // https://www.cnblogs.com/chris-cp/p/3578976.html
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename E>
void SLinkedList<E>::removeFront() {
    SNode<E>* old = head;
    head = old->next;
    delete old;
}

// =========================================
