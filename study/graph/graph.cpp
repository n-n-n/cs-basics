#include<cassert>
class Graph 
{
private:
    // protect copy
    void operator=(const Graph&) {}
    Graph(const Graph& ) {}
protected:
   int n_v_, n_e_;
   int **mat_;
   int *mark_;
public:
    Graph(){}
    ~Graph(){
        delete [] mark_;
    }
    void init(int n_v) 
    {
        n_v_ = n_v;
        n_e_ = 0;
        mark_ = new int[n_v_];
        std::memcpy(mark, UNVISITED, sizeof(int)) * n_v_);
    }
    int vertex_num() { return n_v_;}
    int edge_num() { return n_e_;}
    // v's first neigbour
    virtual int first(int v) = 0;
    // v's next neigbour after w.
    virtual int next(int v, int vv) = 0;

    virtual void set_edge(int v1, int v2, int weight) = 0;
    virtual void delete_edge(int v1, int v2) = 0;
    virtual bool is_edge(int v1, int v2) = 0;
    virtual int weight(int v1, int v2) = 0;

    int get_mark(int v) {
        assert(0 <= v && v < n_v_);
        return mark_[v];
    }
    void set_mark(int v, int m) {
        assert(0 <= v && v < n_v_);
        mark_[v] = m;
    }
};


#include<cstring> 
#include<cassert>

class GraphM : public Graph
{
private:
    int **mat_;
public:
    GraphM(int n_v) : { init(n_v); }
    ~GraphM() {
        for (int i = 0; i < n_v_; i++) {
            delete [] mat_[i];
        }
        delete [] mat_;
    }
    void init(int n_v)
    {
        Graph::init(n_v);
        mat_ = new (int*)[n_v_];
        for (int i = 0; i < n_v_; i++) {
            mat_[i] = new int[n_v_];
            std::memcpy(mat_[i], 0, sizeof(int)) * n_v_);
        }
    }

    int first(int v) 
    {
        assert(0 <= v && v < n_v_);
        for (int i = 0; i < n_v_; i++) {
            if (mat_[v][i] != 0) return i;
        }
        return n_v_;
    }
    int next(int v, int vv) {
        assert(0 <= v && v < n_v_);
        assert(0 <= vv && vv < n_v_);
        for (int i = vv + 1; i < n_v_; i++) {
            if (mat_[v][i] != 0) return i;
        }
        return n_v_;
    }

    void set_edge(int v1, int v2, int w) {
        assert(0 <= v1 && v1 < n_v_);
        assert(0 <= v2 && v2 < n_v_);
        assert(0 < w);
        mat_[v1][v2] = w;
    }

    void delete_edge(int v1, int v2) {
        assert(0 <= v1 && v1 < n_v_);
        assert(0 <= v2 && v2 < n_v_);
        if (mat_[v1][v2] != 0) n_e_--;
        mat_[v1][v2] = 0;
    }
    bool is_edge(int v1, int v2) {
        return mat_[v1][v2] != 0;
    }
    int weight(int v1, int v2) {
        return mat_[v1][v2];
    }

};

class Edge {
    int v_;
    int w_;
public:
    Edge(): v_(-1), w_(0) {}
    Edge(int v, int w) : v_(v), w_(w) {}
    int vertex() { return v_; }
    int weight() { return w_; }
};

class GraphL : public Graph 
{
private:
    List<Edge>** v_;
public:
    GraphL(int n_v) { init(n_v_); }

    void init(int n_v) {
        Graph::init(n_v);

        for (int i = 0; i < n_v_; i++) {
            v_[i] = new LinkList<Edge>();
        }
    }
    int first(int v) {
        assert(0 <= v && v < n_v_);
        if (v_[v]->length() == 0)  return n_v_;
        v_[v]->moveToStart();
        Edge it = v_[v]->get_value();
        return it.vertex();
    }
    int next(int v, int vv) {
        assert(0 <= v && v < n_v_);
        assert(0 <= vv && vv < n_v_);
        Edge it;
        if (is_edge(vv, vv)) {
            if ((v_[v]->currPos() + 1) < v_[v]->length()) {
                v_[v]->next();
                it = v_[v]->get_value();
                return it.vertex();
            }
        }
        return n_v_;
    }
    
};
