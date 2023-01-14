import numpy as np

class Node:
    def __init__(self, name):
        self.name = name
        self.connections = []
        self.visited = False

    def __lt__(self, node2):
        return True

def connect(node1, node2, weight):
    node1.connections.append({"node": node2, "weight": weight})
    node2.connections.append({"node": node1, "weight": weight})


def BFS(node):
    q = [node]
    node.visited = True

    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        print(cur.name)
        for con in cur.connections:
            if not con["node"].visited:
                q.append(con["node"])
                con["node"].visited = True


def get_all_nodes(node):
    q = [node]
    node.visited = True
    list = []
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        list.append(cur)
        for con in cur.connections:
            if not con["node"].visited:
                q.append(con["node"])

                con["node"].visited = True
    return list

def unvisit_all(node):
    q = [node]
    node.visited = False
    i = 0
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        for con in cur.connections:
            if con["node"].visited:
                q.append(con["node"])
                con["node"].visited = False
        i = i +1

def DFS(node):
    if node.visited == False:
        unvisit_all(TO)

    q = [node]
    node.visited = True
    #print(q)
    cur = q.pop()
    print(cur.name)

    for con in cur.connections:
        if not con["node"].visited:
            con["node"].visited = True
            DFS(con["node"])

def DFS_nonrec(node):
    if node.visited == True:
        unvisit_all(TO)
    node.visited = True
    q = [node]
    while len(q) > 0:
        cur = q.pop() # remove q[0] from q and put it in cur
        print(cur.name)
        for con in cur.connections:
            q.append(con["node"])
            con["node"].visited = True


def dijsktra_pq(node):
    d = {}
    pq = [(0, node)]
    while len(pq) > 0:
        cur_dist, cur_node = heapq.heappop(pq)
        if cur_node.name in d:
            continue
        d[cur_node.name] = cur_dist
        for con in cur_node.connections:
            dist = con["weight"] + cur_dist
            node = con["node"]
            heapq.heappush(pq, (dist, node))
    return d

def dijsktra_slowishanswer(node):
    S = [node]
    d = {node.name: 0}

    unexplored = get_all_nodes(node)
    unexplored.remove(node)

    while len(unexplored) > 0:
        cur_min_dist = np.inf
        cur_to_add = None
        for cur in unexplored:
            for con in cur.connections:
                if con["node"] in S:
                    dist = d[con["node"].name] + con["weight"]
                    if dist < cur_min_dist:
                        cur_min_dist = dist
                        cur_prev = con["node"].name
                        cur_to_add = cur

        unexplored.remove(cur_to_add)
        S.append(cur_to_add)
        d[cur_to_add.name] = cur_min_dist
        cur_to_add.prev = cur_prev

    return d


def dijsktra_pq(node):
    d = {}
    pq = [(0, node)]
    while len(pq) > 0:
        cur_dist, cur_node = heapq.heappop(pq)
        if cur_node.name in d:
            continue
        d[cur_node.name] = cur_dist
        for con in cur_node.connections:
            dist = con["weight"] + cur_dist
            node = con["node"]
            heapq.heappush(pq, (dist, node))
    return d



if __name__ == '__main__':
    TO = Node("TO")
    NYC = Node("NYC")
    DC = Node("DC")
    CDMX = Node("CDMX")
    SF = Node("SF")

    connect(TO, NYC, 3)
    connect(TO, SF, 6)
    connect(TO, CDMX, 7)
    connect(NYC, DC, 2)
    connect(SF, DC, 5)
    L = get_all_nodes(TO)
    print(L)
    #DFS_rec(TO)
    unvisit_all(TO)
    DFS(TO)
    unvisit_all(TO)
    #BFS(TO)
    unvisit_all(TO)
    print(CDMX.visited)
    DFS(TO)
    # #print(dijsktra_slowish(TO))