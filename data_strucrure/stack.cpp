template<typename E> class Stack
{
private:
    void operator = (const Statck&) {}
    Stack(const Stack&) {}
public:
    Stack() {}
    virtual ~Stack() {}
    virtual void clear() = 0;
    virtual void push(const E&) = 0;
    virtual E pop() = 0;
    virtual const E& top_value() = 0;
    virtual int length() const = 0;
};

// Array based
template<typename E> class AStack : public Stack<E>
{
private:
    int size_;
    int top_;
    E* list_;
public:
    AStack(int size) : size_(size), top_(0), list_(new E[size]) {}
    ~AStack() { delete [] list_; }
    void clear() { top_ = 0; }
    void push(const E& e) {
        // assert(size...)
        list_[top_++] = e;
    } 
    virtual E pop() {
        // top_
        return list_[--top_];
    }
    const E& top_value() const {
        return list_[top_ - 1];
    }
    int length() const { return top_;}
};

// List based
template<typename E> class LStack : public Stack<E>
{
private:
    int size_;
    Link<E>*  top_;
public:
    LStack(int size) : size_(0), top_(NULL) {}
    ~LStack() { clear(); }
    void clear() 
    { 
        while(top_ != NULL) {
            List<E>* p = top_->next;
            delete top_;
            top_ = p;
        }
        size_ = 0;
    }
    void push(const E& e)
    {
        top_ = new List<E>(e, top);
        size_++;
    } 
    E pop() 
    {
        E e = top->element;
        List<E>* p = top_->next;
        delete top_
        top_ = p;
        size--;
        return e;
    }
    const E& top_value() const 
    {
        return top_->element;
    }
    int length() const { return size_;}
};
