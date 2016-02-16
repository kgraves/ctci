function isAnagram(str1, str2) {
  return str1.split('').sort().join() === str2.split('').sort().join();
}

// tests
var assert = require('assert');

describe('isAnagram', function() {

  it('should succeed', function() {
    assert.equal(isAnagram('', ''), true);
    assert.equal(isAnagram('Racecar', 'racecaR'), true);
    assert.equal(isAnagram(
        'This is a test string',
        'string test a is This'), true);
  });

});
