from queue import PriorityQueue
import sys


class Graph:
    def __init__(self, v):
        self.v = v
        self.adj = []
        self.dist = []
        self.parent = []
        self.vertices = PriorityQueue()
        self.edges = {}
        for i in range(v):
            self.parent.append(-1)
            self.adj.append([])
            self.vertices.insert([float('Inf'), i])
            self.dist.append(float('Inf'))

    def add_edge(self, x, y, w):
        self.adj[x].append((y, w))
        self.edges[str(x) + " " + str(y)] = w

    def dijkstra(self, s):
        self.vertices.decrease_key(0, s)
        self.dist[s] = 0
        while self.vertices.size != 0:
            vertex = self.vertices.extract_min()[1]
            for pairV in self.adj[vertex]:
                v = pairV[0]
                weight = pairV[1]
                tmp_dist = self.dist[v]
                if self.dist[v] > self.dist[vertex] + weight:
                    self.dist[v] = self.dist[vertex] + weight
                    self.vertices.decrease_key(self.vertices.queue.index([tmp_dist, v]), self.dist[v])
                    self.parent[v] = vertex
        for i in range(self.v):
            print(str(s) + " to " + str(i) + " : " + str(round(self.dist[i], 5)), end=" ")
            tmp = [i]
            x = self.parent[i]
            while x != -1:
                tmp.append(x)
                x = self.parent[x]
            while len(tmp) != 1:
                z = tmp.pop()
                print(
                    "[" + str(z) + "]|--" + str(self.edges[str(z) + " " + str(tmp[-1])]) + "-->[" + str(tmp[-1]) + "]",
                    end=" ")
            print()


if __name__ == "__main__":
    if len(sys.argv) > 2:
        lines = [line.rstrip('\n') for line in open(sys.argv[1])]
        g = Graph(int(lines[0]))
        lines.pop(0)
        lines.pop(0)
        for line in lines:
            ls = line.split()
            g.add_edge(int(ls[0]), int(ls[1]), float(ls[2]))
        if g.v > int(sys.argv[2]):
            g.dijkstra(int(sys.argv[2]))
        else:
            print("Usage: graph.py <filename> <source vertex>")
    else:
        print("Usage: graph.py <filename> <source vertex>")
