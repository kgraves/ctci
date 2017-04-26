class Node():
    def __init__(self, value, next):
        self.value = value
        self.next = next

def remove_dups(head):
    prev = head
    curr = head.next
    seen = []

    # add prev to seen
    seen.append(prev.value)

    while curr is not None:
        if curr.value in seen:
            # remove dup
            prev.next = curr.next

            curr = curr.next
        else:
            seen.append(curr.value)
            # only move prev when no deletion
            prev = curr
            curr = curr.next

    return head

import unittest
class TestRemoveDups(unittest.TestCase):

    def test_remove_none(self):
        n1 = Node(5, None)
        n2 = Node(4, n1)
        n3 = Node(3, n2)
        n4 = Node(2, n3)
        n5 = Node(1, n4)
        ll = n5

        actual = remove_dups(ll)

        # check length
        curr = actual
        length = 0
        while curr is not None:
            length += 1
            curr = curr.next
        self.assertEquals(length, 5)

    def test_remove_single(self):
        n1 = Node(5, None)
        n2 = Node(4, n1)
        n3 = Node(3, n2)
        n4 = Node(4, n3)
        n5 = Node(2, n4)
        n6 = Node(1, n5)
        ll = n6

        actual = remove_dups(ll)

        # check length
        curr = actual
        length = 0
        while curr is not None:
            length += 1
            curr = curr.next
        self.assertEquals(length, 5)

if __name__ == '__main__':
    unittest.main()
