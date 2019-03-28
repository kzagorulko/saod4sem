class Node:
    def __init__(self, value, left=None, right=None):
        self.left = left
        self.right = right
        self.value = value


class BinaryTree:
    def __init__(self):
        self._head = None

    def __add__(self, value, start=True, node=None):
        if self._head is None:
            self._head = Node(value=value)
        else:
            if start:
                node = self._head
            if node.value < value:
                if node.right is not None:
                    self.__add__(value=value, node=node.right, start=False)
                else:
                    node.right = Node(value)
            else:
                if node.left is not None:
                    self.__add__(value=value, node=node.left, start=False)
                else:
                    node.left = Node(value)

    def __str__(self, start=True, node=None, lvl=0):
        assert self._head is not None
        if start:
            node = self._head
        if node.left is not None:
            line = self.__str__(start=False, node=node.left, lvl=lvl + 1)
        else:
            line = ''
        if node.right is not None:
            line_r = self.__str__(start=False, node=node.right, lvl=lvl + 1)
        else:
            line_r = ''
        return 'lvl. ' + str(lvl) + ':' + str(node.value) + ' ' + line + line_r

    def balance(self, start=True, node=None):
        assert self._head is not None
        if start:
            node = self._head
        if node is not None:
            if (node.right is None and node.left is not None or node.right is
                    not None and node.left is None):
                if node.value is not None:
                    print(node.value, end=' ')
            if node.right is not None:
                self.balance(node=node.right, start=False)
            if node.left is not None:
                self.balance(node=node.left, start=False)
        else:
            pass


tree = BinaryTree()
tree.__add__(value=5)
tree.__add__(value=6)
tree.__add__(value=8)
tree.__add__(value=3)
tree.__add__(value=4)
print(tree)
tree.balance()