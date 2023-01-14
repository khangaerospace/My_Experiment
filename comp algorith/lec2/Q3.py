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
        a = BST(4)
        print(a) # prints 4
        '''
        return str(self.value)

def search(node,q):
    #print(node)
    q.append(node.value)
    if node.left == None and node.right == None:
        return 0

        # print(search(node.left))
        # print(search(node.right))
    if node.left == None:
        return search(node.right,q)
    if node.right == None:
        return search(node.left,q)
    return search(node.left,q) and search(node.right,q)


def third_largest(node):
    if node == None:
        return
    q = []
    #print(node)
    list = []
    search(node,q)
    # while node!=None:
    #     q.append(note.left)
    #     q.append(note.right)
    #     node = node
    #rd = max(q);
    #print(q)
    list = q
    sorted(list)
    #print(q[2])
    length = len(list) - 3
    v =q[length]
    print(v)
    return v






if __name__ == '__main__':

    root = BST(1)
    root.insert(2)
    root.insert(3)

    third_largest(root) # 1