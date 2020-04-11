/* interface, array-based queue and link-based queue

template<typename E> class Queue 
{
private:
    void operator =(const Queue&) {}
    Queue(const Queue&) {}
public:
    Queue() {}
    virtual ~Queue() {}

    virtual void clear() = 0;
    virtual void enqueue(const E&) = 0;
    virtual E dequeue() = 0;
    virtual const  E& front_value() const = 0;
    virtual int length() const = 0;
};

template<typename E> class AQueue : public Queue<E>
{
private:
    int max_size_;
    int front_;
    int rear_;
    E *list_;
public:
    AQueue(int size) : max_size_(size + 1), front_(1), rear_(0), list_(new E[max_size_]) {}
    ~AQueue() { delete [] list_;}

    void clear() { rear_ = 0; front_ = 1; }
    void enqueue(const E& e) {
        rear_ = (real_ + 1) % max_size_;
        list_[rear_] = e;
    }
    E dequeue() 
    {
        E e = list_[front_];
        front_ = (front_ + 1) % max_size_;
        return e;
    }
    const  E& front_value() const 
    {
        return list_[front_];
    }
    virtual int length() const { (rear_ + max_size_ - front_ + 1) / max_size_;}
};

template<typename E> class LQueue : public Queue<E>
{
private:
    Link<E>* front_;
    Link<E>* rear_;
    int size_;
public:
    LQueue(int size) 
    {
        size_ = 0;
        front_ = rear_ = new Link<E>(); // head pointer holder
    }
    ~LQueue() { clear(); delete front_;}

    void clear() 
    {
        while(front_->next) {
            rear_ = front_;
            front_ = rear_->next;
            delete rear_;
        }
        rear_ = front_;
        size_ = 0;
    }
    void enqueue(const E& e) 
    {
        rear_->next = new Link<E>(e, NULL);
        rear_ = rear_->next;
        size_++;
    }
    E dequeue() 
    {
        E e = front_->next->element;
        Link<E>* p = front_->next;
        front_->next = p->next;
        if (rear_ == p) rear_ = front_;
        delete p;
        return e;
    }
    const  E& front_value() const 
    {
        return front_->next->element;
    }
    int length() const { return size_; }
};

