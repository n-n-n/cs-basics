# Data Structure for Disjoint Sets

## Basic data structure and operations
A collectoin of disjoint sets:
```
SS = { S1, S2, ... ,Sk}
```
Each set is able to be identified by some representative. (```|Sn| != 0```)

Operations.
- ```MAKE-SET(x)``` : Create a set with a repsentative ```x```. 
  - ```MAKE-SET(X), |Sx| = 1 ```
  - To make ```Sx`` disjoint, we need to check if other set don't have the element ```x```.
- ```UNION(x, y)```: Union two set ```Sx``` and  ```Sy```. The sets each have representative ```x``` and ```y```.
- ```FIND(x)```: Return the set which have an element ```x``` or not.

### Application - Make disjoint set of an undirected graph
```G``` : a graph, ```G.V, G.E```:the vertext set and the edge set of ```G```.
```
CONNECTED_COMPONENTS(S):
  for v in G.V:
    MAKE_SET(v)
  for (u, v) in G.E:
    if not SAME_COMPONENT(u, v)
        UNION(u, v)

SAME_COMPONENT(u, v):
  if FIND_SET(u) == FIND_SET(v):
    return true
  else return false
```

NOTE: If a graph is static. DFS(Depth-First-Search) can compute the connected componets faster.

### Linked-list repsentation of disjoint sets

```
struct disjoint_set
{
  link* head; // the representative
  link* tail;
};

struct set_link
{
  value_t value;
  disjoint_set* set;
  set_link* next;
};
/*

set_link(a) -(next)-> set_link(b) -(next)-> .... -(next)-> set_link(z)--> null
all set_link(*) -(disjoint_set)-> set
disjoint_set -(head)-> set_link(a)
disjoint_set -(tail)-> set_link(z)
// 'a' is the representative 
*/

disjoint_set* make_set(x)
{
  disjoint_set* ret = new disjoint_set;
  set_link l = new set_link;
  l->value = x
  l->set = ret;
  l->next = NULL;
  ret->head = l;
  ret->tail = l;
  return ret;
}

disjoint_set_t find_set(x, set_list) 
{
    for (ps : set_lst) {
      set_lint* l = ps->head;
      while(l != NULL) {
        if (l->value == x) {
          return ps;
      }
      l = l->next;
    }
    return NULL;
}

disjoint_set_t* union(x, y)
{
  disjoint_set_t* sx = find_set(x);
  if (sx == NULL) return sy;
  sy = find_set(y);
  if (sy == NULL) return sx;
  
  sx->tail->next = sy->head
  set_link* p = sy->head;
  while(p != NULL){
    p->set = sx;
    p = p->next;
  }
  delete sy;
  return sx;
}
```

### A weighted-union huristic

