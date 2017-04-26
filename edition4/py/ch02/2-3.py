class Node():
    def __init__(self, value, next):
        self.value = value
        self.next = next

def remove_node(node):
    node.value = node.next.value
    node.next = node.next.next

import unittest
class TestRemoveNode(unittest.TestCase):

    def test_remove_node(self):
        n1 = Node(5, None)
        n2 = Node(4, n1)
        n3 = Node(3, n2)
        n4 = Node(2, n3)
        n5 = Node(1, n4)
        ll = n5

        remove_node(n3)

        # check length
        curr = ll
        length = 0
        while curr is not None:
            length += 1
            curr = curr.next
        self.assertEquals(length, 4)

if __name__ == '__main__':
    unittest.main()
