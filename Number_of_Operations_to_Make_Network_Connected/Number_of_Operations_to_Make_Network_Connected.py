class Solution(object):
    def makeConnected(self, n, connections):
        if len(connections) < n - 1:
            return -1
        
        parent = list(range(n))
        rank = [1] * n
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            
            if rootX != rootY:
                if rank[rootX] > rank[rootY]:
                    parent[rootY] = rootX
                elif rank[rootX] < rank[rootY]:
                    parent[rootX] = rootY
                else:
                    parent[rootY] = rootX
                    rank[rootX] += 1
        
        for conn in connections:
            union(conn[0], conn[1])
        
        components = len(set(find(i) for i in range(n)))
        
        min_cables_needed = components - 1
        
        return min_cables_needed
