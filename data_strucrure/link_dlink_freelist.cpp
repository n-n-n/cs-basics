#include <iostream>
using namespace std;

// doubly linked list node with freelist supprot
template<typename E> class Link{
private:
    static Link<E>* freelist;
public:
    E element;
    Link* next;
    Link* prev;

    Link(const E& e, Link* p, Link* n) {
        element = e;
        next = n;
        prev = p;
    }
    Link(Link* p = NULL, Link* n = NULL) { prev = p; next = n;}

    void* operator new(size_t n) {
        std::cout <<  "new " << n << ' ' << freelist << std::endl;
        if (freelist == NULL) return ::new Link; // head
        std::cout << "from freelist " << n << ' ' << freelist << std::endl;
        Link<E>* p = freelist;  // take from freelist
        freelist = freelist->next; // update
        return p;
    }

    void operator delete(void* p) {
        ((Link<E>*)p)->next = freelist;
        freelist = (Link<E>*)p;
    }
};

template<typename E> Link<E>* Link<E>::freelist = NULL;

// LList
void insert(const E& e)
{
    Link<E>* p = new Link<E>(e, curr_, curr_->next);
    curr_->next->prev = p;
    curr_->next = curr_->next->prev;
    size_++;
}

void append(const E& e)
{
    Link<E>* p = new Link<E>(e, tail_->prev, tail_);
    tail_->prev->next = p;
    tail_->prev = p;
    size_++;
}

E remove() 
{
    if (curr_->next == tail) return NULL;
    Link<E>* p = curr->next
    E e = p->element;
    p->next->next->prev = curr;
    p = curr_->next->next;
    delete p;
    return e;
}

void prev()
{
    if (curr_ == head_) return;
    curr_ = cur_->prev;
}

int main() 
{
    Link<int> head;
    head.next = new Link<int>();
    head.next->next = new Link<int>();

    Link<int>::freelist 
    return 0;
}
