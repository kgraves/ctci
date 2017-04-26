# Implement an algorithm to determine if a string has all unique characters.
# What if you can not use additional data structures?

def has_all_unique(str):
    seen = dict()

    for letter in str:
        if seen.has_key(letter):
            return False
        seen[letter] = True
    return True

import unittest
class TestHasAllUnique(unittest.TestCase):

    def test_all_unique(self):
        self.assertTrue(has_all_unique('a'))
        self.assertTrue(has_all_unique('blah'))

    def test_not_all_unique(self):
        self.assertFalse(has_all_unique('aa'))
        self.assertFalse(has_all_unique('a.a'))
        self.assertFalse(has_all_unique('not unique '))

if __name__ == '__main__':
    unittest.main()
