/* 
Heap / Priority Queue.
Definition:
- Complete binary tree. (using the array representation)
- The values stored in a heap are PARTIALLY ORDERED.

Two variants.
- MAX-heap : a value in a node is greater than or equal to its chirdren. the root is maximum.
- MIN_heap : a value in a node is less than or eqaul to its chirdren. the root is minimum.

Comparison BTW BST and Heap.
- BST: total order on its nodes in that. folowing a inorder traversal, left->right : smaller to larger ro larger to smaller.
- Heap; ordered in the decendant.  no ordered-relation amoung its siblings.

Usecase of the heap
- Heapsort: max-heap,
- Replacement Seleaction algorith: min-heap.

CAUTION
- Its physical implimentation is array and logical representaion is a tree.
*/

// max heap.
template<typename E, typename Comp> class Heap 
{
private:
    E* heap;
    int max_size;
    int n;
    // basic opration 
    void shift_down(int pos) {

        while(!isLeaf(pos)) {
            int i = left_child(pos);
            int rc = right_child(pos);
            // CAUTION: no order btw the left and the right.
            if ((rc < n) && Comp::prior(heap[rc], heap[lc])){
                i = rc; // choose the greater index.
            }

            if (Comp::prior(heap[pos], heap[i])) {
                return;
            }
            // parent - child swap. 
            swap(heap, pos, lc);
            pos = i; // move down (go to the child)
        }
    }
public:
    Heap(E* h, int num, int max) : heap(h), n(num), max_size(max)
    {
        // build_heap
        for (int i = n / 2 - 1; i >= 0; i--) shift_down(i)
    }
    int size() const { return n; }
    bool isLeaf(int pos) const  { return (pos >= n / 2) && (pos < n);}
    int left_child(int pos) { return 2 * pos + 1; }
    int right_child(int pos) { return 2 * pos + 2; }
    int parent(int pos) { return (pos - 1) / 2; }

    void insert(const E& e)
    {
        assert(n < maxsize, "Heap is full.");
        // put the element in the last at once.
        int curr = n++;
        heap[curr] = e;
        // shift up along parents
        while(curr != 0 && Comp::prior(heap[curr], heap[parent(curr)])) {
            swap(heap, curr, parent(curr));
            curr = parent(curr);
        }
    }
    E remove_first() 
    {
       assert(n > 0, "Heap is empty.");
       swap(heap, 0, --n); 
       if (n != 0) shift_down(0); 
       return heap[n];
    }
    E remove(int pos)
    {
        assert((pos >= 0) && (pos < n), "Bad position");
        if (pos == (n - 1)) {
            n--;
        } else {
            swap(heap, pos, --n);
            while((pos != 0) && (Comp::prior(heap[pos], heap[parent(pos)])))
            {
                swap(heap, pos, prarent(pos));
                pos = parent(pos);
            }
            if (n != 0) shift_down(pos);
        }
        return heap[n];
    }
};
