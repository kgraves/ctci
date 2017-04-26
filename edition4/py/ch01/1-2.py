def replace_at(s, l, i):
    return s[:i] + l + s[i+1:]

def reverse(s):
    length = len(s)
    start = 0
    upper = len(s) / 2

    for index in xrange(start, upper):
        other = length - 1 - index

        tmp = s[index]
        # swap letters
        s = replace_at(s, s[other], index)
        s = replace_at(s, tmp, other)

    return s

import unittest
class TestReverse(unittest.TestCase):

    def test_even_length(self):
        self.assertEquals(reverse('asdf'), 'fdsa')

    def test_odd_length(self):
        self.assertEquals(reverse('asdfg'), 'gfdsa')

if __name__ == '__main__':
    unittest.main()
