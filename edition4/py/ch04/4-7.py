class Node(object):
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def is_subtree(t1, t2):
    if not t1:
        return False
    elif not t2: 
        return True
    else:
        return find_starts(t1, t2)

def find_starts(t1, t2):
    # base case
    if not t1:
        return False
    elif t1.value == t2.value:
        # found starting point, try to match whole tree.
        if match_subtree(t1, t2):
            return True

    return find_starts(t1.left, t2) or find_starts(t1.right, t2)

def match_subtree(t1, t2):
    # base case
    if not t1 and not t2:
        # exhausted both trees
        return True
    elif not t1 or not t2:
        # one of the subtrees has been exhausted; does not match other
        return False
    elif not t1.value == t2.value:
        return False
    else:
        return (match_subtree(t1.left, t2.left) and
                match_subtree(t1.right, t2.right))

import unittest
class TestIsBalanced(unittest.TestCase):
    
    def test_is_in_subtree(self):
        n111 = Node(2)
        n112 = Node(10)
        n11 = Node(1, n111, n112)

        n1 = Node(4, n11)
        n2 = Node(3)
        n3 = Node(5, n1, n2)

        n4 = Node(6)
        n6 = Node(8, n4, None)

        root = Node(1, n3, n6)

        # test base cases
        self.assertFalse(is_subtree(None, n1))
        self.assertTrue(is_subtree(n1, None))

        # test subtree not being in tree
        n7 = Node(42)
        self.assertFalse(is_subtree(root, n7))

        # test cases where subtree is in tree
        self.assertTrue(is_subtree(root, n4))
        self.assertTrue(is_subtree(root, root))
        self.assertTrue(is_subtree(root, n11))

if __name__ == '__main__':
    unittest.main()
