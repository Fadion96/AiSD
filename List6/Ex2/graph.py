from queue import PriorityQueue
from set import Set


class Graph:
    def __init__(self, v, e):
        self.v = v
        self.e = e
        self.adj = []
        self.key = []
        self.parent = []
        self.edges = PriorityQueue()
        self.vertices = PriorityQueue()
        for i in range(v):
            self.parent.append(-1)
            self.adj.append([])
            self.vertices.insert([float('Inf'), i])
            self.key.append(float('Inf'))

    def add_edge(self, x, y, w):
        self.edges.insert([w, (x, y)])
        self.adj[x].append((y, w))
        self.adj[y].append((x, w))

    def kruskal_mst(self):
        mst_weight = 0
        s = Set(self.v)
        while self.edges.size != 0:
            edge = self.edges.extract_min()
            x = edge[1][0]
            y = edge[1][1]
            x_par = s.find(x)
            y_par = s.find(y)

            if x_par != y_par:
               # print("[" + str(x) + "]" + "--" + str(edge[0]) + "--" + "[" + str(y) + "]")
                mst_weight += edge[0]
                s.merge(x_par, y_par)
        return mst_weight

    def prim_mst(self):
        mst_weight = 0
        self.vertices.decrease_key(0, 0)
        self.key[0] = 0
        while self.vertices.size != 0:
            vertex = self.vertices.extract_min()
            mst_weight += vertex[0]
            for v in self.adj[vertex[1]]:
                tmp_key = self.key[v[0]]
                if [tmp_key, v[0]] in self.vertices.queue and v[1] < self.key[v[0]]:
                    self.parent[v[0]] = vertex[1]
                    self.key[v[0]] = v[1]
                    self.vertices.decrease_key(self.vertices.queue.index([tmp_key, v[0]]), v[1])
        #for i in range(1, self.v):
            #print("[" + str(self.parent[i]) + "]" + "--" + str(self.key[i]) + "--" + "[" + str(i) + "]")
        return mst_weight


if __name__ == "__main__":
    lines = [line.rstrip('\n') for line in open('graph3.txt')]
    g = Graph(int(lines[0]), int(lines[1]))
    lines.pop(0)
    lines.pop(0)
    for line in lines:
        ls = line.split()
        g.add_edge(int(ls[0]), int(ls[1]), float(ls[2]))
    print("Kruskal Minimum Spanning Tree")
    print("MST weight: " + str(g.kruskal_mst()))
    print("Prim Minimum Spanning Tree")
    print("MST weight: " + str(g.prim_mst()))
