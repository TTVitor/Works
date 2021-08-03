1)
a)
#define Graph Digraph

void GRAPHmstP1( Graph G, Vertex parent[]) 
{ 
  Vertex v0, w, frj[maxV]; link a; 
  double price[maxV], c;
  for (w = 0; w < G->V; w++) 
  parent[w] = -1, price[w] = INFINITO; 
  v0 = 0;
  parent[v0] = v0;
    for (a = G->adj[v0]; a != NULL; a = a->next) {
      price[a->w] = a->cost; 
      frj[a->w] = v0; 
     } 

    while (1) { 
      double minprice = INFINITO; 
        for (w = 0; w < G->V; w++) 
           if (parent[w] == -1 && minprice > price[w]) 
              minprice = price[v0=w]; 
           if (minprice == INFINITO) break;
              parent[v0] = frj[v0]; 
          for (a = G->adj[v0]; a != NULL; a = a->next) {
              w = a->w, c = a->cost;
          if (parent[w] == -1 && price[w] > c) {
            price[w] = c; 
            frj[w] = v0; 
          }
       }
    }
}


b)
void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int n;
vector<Edge> edges;

int cost = 0;
vector<Edge> result;
parent.resize(n);
rank.resize(n);
for (int i = 0; i < n; i++)
    make_set(i);

sort(edges.begin(), edges.end());

for (Edge e : edges) {
    if (find_set(e.u) != find_set(e.v)) {
        cost += e.weight;
        result.push_back(e);
        union_sets(e.u, e.v);
    }
}
2)
public class Node
{
    public string Label { get; }
    public Node(string label)
    {
        Label = label;
    }

    readonly List _edges = new List();
    public IEnumerable Edges => _edges;

    public IEnumerable Neighbors =>
        from edge in Edges
        select new NeighborhoodInfo(
            edge.Node1 == this ? edge.Node2 : edge.Node1,
            edge.Value
            );

    private void Assign(Edge edge)
    {
        _edges.Add(edge);
    }

    public void ConnectTo(Node other, int connectionValue)
    {
        Edge.Create(connectionValue, this, other);
    }

    public struct NeighborhoodInfo
    {
        public Node Node { get; }
        public int WeightToNode { get; }

        public NeighborhoodInfo(Node node, int weightToNode)
        {
            Node = node;
            WeightToNode = weightToNode;
        }
    }

    public class Edge
    {
        public int Value { get; }
        public Node Node1 { get; }
        public Node Node2 { get; }
public Edge(int value, Node node1, Node node2)
        {
            if (value <= 0)
            {
                throw new ArgumentException("Edge value needs to be positive.");
            }
            Value = value;
            Node1 = node1;
            node1.Assign(this);
            Node2 = node2;
            node2.Assign(this);
        }

        public static Edge Create(int value, Node node1, Node node2)
        {
            return new Edge(value, node1, node2);
        }
    }
}
var a = new Node("A");
var b = new Node("B");
var c = new Node("C");
var d = new Node("D");
var e = new Node("E");
var f = new Node(“F");
var g = new Node(“G");
var h = new Node(“H");
var i = new Node("I");
var j = new Node(“J");
var k = new Node("K");

a.ConnectTo(b, 8);
a.ConnectTo(c, 5);
a.ConnectTo(d, 7);
b.ConnectTo(e, 6);
b.ConnectTo(f, 4);
c.ConnectTo(d, 4);
c.ConnectTo(f, 5);
c.ConnectTo(e, 4);
d.ConnectTo(f, 4);
d.ConnectTo(g, 5);
e.ConnectTo(h, 4);
f.ConnectTo(h, 4);
f.ConnectTo(i, 3);
f.ConnectTo(j, 3);
g.ConnectTo(i, 2);
g.ConnectTo(j, 4);
h.ConnectTo(k, 4);
i.ConnectTo(k, 5);
j.ConnectTo(k, 4);



a)A até H
A-C, C-E, E-H = 13

b)D até K
D-F, F-I, I-K = 12
ou
D-G, G-I, I-K = 12
