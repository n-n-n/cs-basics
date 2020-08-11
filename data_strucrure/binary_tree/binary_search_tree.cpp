// Binary Search Tree implimentation

using namespace std;

template <typename Key, typename E> 
class BST : public Dictionary<Key, E> { // BST has same interface as Dictionary
private:
    BSTNode<Key, E>* root;
    // { Key k; E it; BSTNode *left. *right; }
    int nodecount;

    // helper functions
    void clear_(BST<Key, E>* );
    BSTNode<Key, E>* insert_(BSTNode<Key,  E>*, const Key&, const E&);
    BSTNode<Key, E>* get_min_(BSTNode<Key,  E>*);
    BSTNode<Key, E>* remove_(BSTNode<Key,  E>*, const Key&);
    E* find_(BSTNode<Key,  E>* rt, const Key&) const;
    void print_(BSTNode<Key,  E>* rt,  int level) const;

public:
    BST() { root = NULL; nodecount = 0; }
    ~BST() { clean_(root); }

    void clear() 
    { 
        clear_(root);
        root = NULL;
        nodecount = 0;
    }

    void insert(const Key& k, const E& e)
    {
        root = insert_(root, k, e);
        nodecount++;
    }
    E* remove(const Key& k)
    {
        E* tmp = find_(root, k);
        if (tmp != NULL) {
            root = remove_(root, k);
            nodecount--;
        }
        return tmp;
    }
    E* remove_any()
    { 
        if (root != NULL) {
            E* tmp = root->element();
            root = remove_(root, root->key());
            nodecount--;
            return tmp;
        }
        return NULL;
    }
    int size() { return nodecount; }
    void print() const {
        if (root) cout << "The BST is empty\n";
        else print_(root, 0);
    }
};

template < typename Key, typename E>
E BST<Key, E>::find_(BST<Key, E>* rt, const Key& k) const 
{
    if (NULL == rt) return NULL;
    if (k < rt->key()) {
        return find_(rt->left(), k);
    } else if (k > rt->key()) {
        return find_(rt->right(), k);
    } else {
        return rt->element();
    }
}

template<typename Key, typename E>
BSTNode<Key, E> BST<Key, E>::insert_(BST<Key, E>* rt, const Key& k, const E& it)
{
    if (NULL == rt) {
        return new BSTNode<Key, E>(k, it, NULL, NULL);
    }
    if (k < rt->key()) {
        rt->set_left(insert_(rt->left(), k, it));
    } else {
        rt->set_right(inset_(rt->right(), k, it));
    }
    return rt;
}

// KEY OPRATION!!!!!
template<typename Key, typename E> BST<Key, E>::delete_min_(BST<Key, E>* rt)
{
    if (NULL == rt->left()) {
        return rt->right(); // choose right;
    } else {
        rt->set_left(delete_min_(rt->left())); // 
        return rt;
    }
}

template<typename Key, typename E> BSTNode<Key, E>* BST<Key, E>::get_min_(BST<Key, E>* rt)
{
    if (rt->left() == NULL){
        return rt;
    } else {
        return get_min_(rt->left());
    }
}

template<typename Key, typename E> BSTNode<Key, E>* BST<Key, E>::remove_(BST<Key, E>* rt, const Key* k)
{
    if (rt == NULL) return NULL
    if (k < rt->key()) {
        rt->set_left(remove_(rt->left(), k));
    } else if (k > rt->key()) {
        rt->set_right(remove_(rt->right(), k));
    } else {
        // find
        BSTNode<Key, E> *tmp = rt;
        if (rt->left() == NULL) {
            rt = rt->right(); // NULL is also allowed.
            delete tmp;
        } else if (rt->right == NULL) {
            rt = rt->left(); // not NULL.
            delete tmp;
        } else {
            BSTNode<Key, E>* tmp = get_min_(rt->right());
            rt->set_elsement(tmp->element());
            rt->set_key(tmp->key());
            rt->set_right(delete_min(rt->right()));
            delete tmp;
        }
    }
}

template<typename Key, typename E> void BST<Key, E>::clear_(BST<Key, E>* rt)
{
    if (rt == NULL) return;
    clear_(root->left());
    clear_(root->right());
    delete rt;
}

template<typename Key, typename E> void BST<Key, E>::print_(BST<Key, E>* rt, int level)
{
    if (rt == NULL) return;
    print_(root->left()), level+1);
    
    // inorder operation
    for (int i = 0; i < level; i++) {
        cout << " ";
    }
    cout << rt->key() << '\n';

    print_(root->right()), level+1);
}
