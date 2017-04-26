import sys

class Stack(list):
    def __init__(self):
        self._min = sys.maxint

    def push(self, v):
        if (v < self._min):
            self._min = v

        self.append(v)

    def min(self):
        return self._min

import unittest
class TestStackMin(unittest.TestCase):

    def test_stack_min_empty(self):
        s = Stack()
        self.assertEquals(s.min(), sys.maxint)

    def test_stack_min(self):
        s = Stack()
        s.push(5)
        self.assertEquals(s.min(), 5)

        s.push(6)
        s.push(2)
        s.push(100)
        self.assertEquals(s.min(), 2)

if __name__ == '__main__':
    unittest.main()
