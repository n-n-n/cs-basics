class MinStack {
public:
    struct Node {
        Node(const int v, const int m = INT_MAX, Link* n = 0) 
            : val(v), link(n), min_val(m) {;}
        int val;
        int min_val;
        Node* link;
    };

    Node *top_;
    
    MinStack() : top_(0) {;}
    
    void push(int x) {
        if (top_) {
            top_ = new Link(x, (top_->min_val > x ? x : top_->min_val), top_);
        } else {
            top_ = new Link(x, x);
        }
    }
    
    void pop() {
       if (top_) {
            Link* tmp = top_;
            top_ = top_->link;
            delete tmp;
       }
    }
    
    int top() {
        if (top_) {
            return top_->val;
        } else {
            return INT_MAX;
        }
    }
    
    int getMin() {
        if (top_) {
            return top_->min_val;
        } else {
            return INT_MAX;
        }
    }
};
