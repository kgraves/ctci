class Node(object):
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def max_depth(root):
    # base case
    if root is None:
        return 0
    else:
        return 1 + max(max_depth(root.left), max_depth(root.right))

def min_depth(root):
    # base case
    if root is None:
        return 0
    else:
        return 1 + min(min_depth(root.left), min_depth(root.right))

def is_balanced(root):
    return (max_depth(root) - min_depth(root) < 2)

import unittest
class TestIsBalanced(unittest.TestCase):

    def test_is_balanced(self):
        n1 = Node(1)
        n2 = Node(1)
        n3 = Node(1, n1, n2)

        n4 = Node(1)
        n5 = Node(1)
        n6 = Node(1, n4, n5)

        root = Node(1, n3, n6)
        self.assertTrue(is_balanced(root))

        n7 = Node(1)
        n4.left = n7
        self.assertTrue(is_balanced(root))

        n8 = Node(1)
        n7.left = n8
        self.assertFalse(is_balanced(root))

if __name__ == '__main__':
    unittest.main()
