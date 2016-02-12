/**
 * Reverses a c style string
 *
 * NOTE: using an array to represent a c style string, since string are
 * immutable in javascript.
 */
function reverseString(str) {
  var head = 0;
  var tail = 0;

  while (str[tail] !== '\0') {
    tail += 1;
  }
  tail -= 1;

  while (head < tail) {
    var temp = str[head];
    str[head] = str[tail];
    str[tail] = temp;

    head += 1;
    tail -= 1;
  }

  return str;
}

// tests
var assert = require('assert');
var mocha = require('mocha');

describe('reverseString', function() {

  it('should succeed', function() {
    var str = 'This is a test string\0';
    var actual = reverseString(str.split(''));
    var expected = 'gnirts tset a si sihT\0';
    assert.equal(actual.join(''), expected);
  });

});
