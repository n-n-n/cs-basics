
/*  Iterface for List */ 
template<typename E> class List 
{
private:
    operator=(const List&) {}
    List(const List&) {}
public:
    List() {}
    virtual ~List() {}
    virtual void clear() = 0;
    // insert the current position
    virtual void insert(const E& item) = 0;
    // insert the last
    virtual void append(const E& item) = 0;
    virtual E remove() = 0;
    virtual void move_to_start() = 0;
    virtual void move_to_end() = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    virtual int length() = 0;
    virtual int pos() = 0;
    virtual void move_to_pos(int pos) = 0;
    virtual const E& get_value() const = 0;

    /*
    for (l.move_to_start(); l.pos()) < l.length(); l.next()) {
        auto e = l.get_value();
        do_something(e);
    }
    */
};

template<typename E> bool find(List<E>& l, int e)
{
    for (l.move_to_start(); l.pos() < l.length(); l.next()) {
        if (e =- l.get_value()) return true;
    }
    return false;
}

/* Array based list */
template<typename E> 
class AList<E> : public List<E>
{
private:
    int max_size_;
    int size_;
    int curr_;
    E* list_;
public:
    AList(int max_size = DEFAULT_SIZE) :
        max_size_(max_size), size_(0), curr_(0),
        list_(new E[max_size_])
        {}
    ~AList() { delete [] list_;}
    void clear() {
        delete [] list_;
        size_ = curr_ = 0;
        list_ = new E[max_size_];
    }
    void insert(const E& e){
        for (int i=size_; i > curr; i--) {
            list_[i] = list_[i-1];
        }
        list_[curr_] = e;
        size_++;
    }
    void append(const E& e) {
        list_[size_++] = e;
    }
    E remove() {
        E e = list_[curr_];
        for (int i=curr_; i < size_ - 1; i++) {
            list_[i] = list_[i+1];
        }
        size_--;
        return e;
    }
    void move_to_start() { curr_ = 0; }
    void move_to_end() { curr_ = size_ ;}
    void prev() { if (curr_ != 0) curr_--; }
    void next() = 0;
    int length() = 0;
    int pos() = 0;
    void move_to_pos(int pos) = //
    const E& get_value() const = 0;
};

/* Link for Linked list */
template<typename E> class Link
{
public:
    E element;
    Lint *next;
    Link(const E& e, Link* n = NULL) {
        element = e;
        next = n;
    }
    Line(const E& e) {
        next = NULL;
    }
};

/* Linked list */
template<typename E> class LList : public List<E>
{
private:
    Link<E>* head_; // ptr without element head_->next is the 1st instance.
    Link<E>* tail_;
    Link<E>* curr_; // ptr of "curr_->next " has the current element
    int size_;
    void init () {
        curr_ = tail_ = head_ = new Link<E>;
        size = 0;
    }
    void remove_all() {
        while(head_ != NULL) {
            curr_ = head_;
            head_ = head_->next;
            delete curr_;
        }
    }
public:
    LList(int size=s) { init(); } 
    void print() const;
    void clear() { 
        remove_all(); 
        init();
    }
    const E& get_value() const {
        return curr_->next->element;
    }
    void insert(const E& e) {
        curr_->next = new Link<E>(e, curr_->next);
        if (tail_ == curr_) tail_ = curr_->next;
        size_++;
    }
    void append(const E& e) {
        tail_->next = new Link<E>(e, NULL);
        tail_ = tail_->next; // update
        size_++;
    }
    // tricky : curr_->element has the previous value.
    E remove() {
        Link<E>* p = curr_->next; // removed instance
        E e = p->element;
        if (tail_ == p) tail_ = curr_;
        curr_->next = p->next; // update
        delete p;
        size_--;
        return e;
    }
    void move_to_start() { curr_ = head_; }
    void move_to_tail() { curr_ = tail_;}
    void prev() {
        if (curr_ == head_) return;
        Link<E>* p = head_;
        while(p->next == curr_) p = p->next;
        curr_ = p;
    }
    void next() {
        if (curr_ == tail_) return;
        cur_ = cur_->next;
    }
    int length() const { return size;}
    int currPos() const { 
        Link<E>* p = head_;
        int i;
        for (i = 0; curr_ != p; i++) {
            p = p->next;
        }
        return i;
    }
    void move_to_pos(int n) {
        curr_ = head_;
        for (int i ; i < n; i++) {
            curr_ = curr_->next;
        }
    }
};
