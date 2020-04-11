/* interface , array-list-based dictionary */

template<typename K, typename E> class Dictionary
{
private:
    void operator = (const Dictionary&) {}
    Dictionary(const Dictionary&) {}
public:
    Dictionary() {}
    virtual ~Dictionary() {}

    virtual void clear() = 0;
    virtual void insert(const K& k, const E& e) = 0;
    virtual E remove(const K& k) = 0;
    virtual E remove_any() = 0;
    virtual E find(const K& k) const = 0;
    virtual int size() = 0;
};

template<typename K, typename V> class KVPair
{
private:
    K k_;
    V v_;
public:
    KVPair() {}
    KVPair(K k, E v) k_(k), v_(v) {}
    KVPair(const KVPair& o) k_(o.k_), v_(o.v_) {}
    void operator =(const& KVPair& o) {
        k_ = o.k_; v_ = o.v_;
    }
    K key() { return k_; }
    V value() { return v_; }
    void set_key(const K& k) { k_ = k; }
};

template <typename K, typename V> class UALDict {
private:
    AList< KVPair<K, V> >* list_;
public:
    UALDict(int size) : list_(AList< KVPair<K, V> >(size)) {}
    ~UALDict() { delete list_; }
    void clear() { list_->clear(); }
    void insert(const K& k, const V& v) {
        KVPair<K, V> tmp(k, v);
        list_->append(k, v);
    }
    void remove(const K& k) {
        V tmp = find(k); // not found??
        if (tmp != NULL) list_->remove();
        return tmp;
    }
};
