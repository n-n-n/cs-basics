# Graph Algorithm Basics
## Representation
```G=(V, E)```. Directed, Undirected
- Spacse graph: ```|V|^2 >>  |E|
- Dense graph: ```|V|^2 ~ |E|

Representation:
- Link representation (for sparce)
```
struct vertex {
  int i; // vertex index
  vertex* v;
};
/*
verteices = List<*vertex>(vn); // vn = |V|
vertices[1]->vertex(e1)-(v)-->vertext(e2)-->(v)-->..NULL
# (1, e1), (1, e2).... : edges NOTE; there is no value space for 1.
# the index of verteces holds index information. (i.e 1).
*/
```
- Matrix representation (for dense)
  use adjacency matrix ```m[i,j]```
  
