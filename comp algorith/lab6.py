# Lab 6

#
# We'll define a node of a binary tree and introduce some features of Python
# classes along the way

import random

class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        '''
        node.insert(5) is the same as BST.insert(node, 5)
        We use this when recursively calling, e.g. self.left.insert
        '''
        if value < self.value:
            if self.left == None:
                self.left = BST(value)
            else:
                self.left.insert(value)
        else:
            if self.right == None:
                self.right = BST(value)
            else:
                self.right.insert(value)

    def __repr__(self):
        '''The string representation of a node.
        Here, we convert the value of the node to a string and make that
        the representation.
        We can now use
        a = Node(4)
        print(a) # prints 4
        '''
        return str(self.value)




#problem 1
#    4
#   /\
#  2   5
#   \    \
#    3    10
#          \
#           15


# problem 2
def max(a, b):
    if a >=b:
        return a
    else:
        return b
def min(a,b):
    if b >= a:
        return a
    else:
        return b

def tree_height(node):
    max_list = []
    if node is None:
        return 0
    else:
        #print(node)
        return 1 + max(tree_height(node.left), tree_height(node.right))



def BFS_tree(root):
    if root is None:
        return None
    q = []
    q.append(root)
    while len(q) != 0:
        length = len(q)
        for i in range(length):
            r = q.pop(0)
            if r.left is not None:
                q.append(r.left)
            if r.right is not None:
                q.append(r.right)
            print(r.value)
def make_random_tree(n_nodes):
    global i =  print(int((random.random())*10-1))
    rantree = BTS( int((random.random())*10-1))
    for i in range(1,n_nodes):
        v = int((random.random())*10-1)
        rantree.insert(v)
    return rantree

def height_random_tree(n_nodes):
    make_random_tree
    return tree_height(i)

def make_data(max_nodes):
    n = []
    h = []

    N_TREE = 40
    n_nodes = 5
    counter = 0
    n-val = n_nodes
    while(n_val<=max_node):
        n_val = int(n_nodes*(1.2**counter))
        counter = counter +1
        for i in range(N_TREES):
            h_vals = height_random_tree(n_val)
            n.append(n_val)
            h.append(nval)
    return n,h

if __name__ == '__main__':

    a = BST(4)
    a.insert(2)
    a.insert(5)
    a.insert(10)
    a.insert(3)
    a.insert(15)
    print(tree_height(a))
    BFS_tree(a)