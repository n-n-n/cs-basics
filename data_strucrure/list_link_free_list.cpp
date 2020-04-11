#include <iostream>
using namespace std;

// Singly linked list node with freelist support
template<typename E> class Link{
private:
    static Link<E>* freelist;
public:
    E element;
    Link* next;
    Link(const E& e, Link* n) {
        element = e;
        next = n;
    }
    Link(Link* n = NULL) { next = n;}

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

int main() 
{
    Link<int> head;
    head.next = new Link<int>();
    head.next->next = new Link<int>();

    Link<int>::freelist 
    return 0;
}
