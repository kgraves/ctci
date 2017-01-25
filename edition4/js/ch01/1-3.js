function removeDups(str) {
  if (!str || str.length < 2) return str;

  var write = 1;

  for (var i=1; i<str.length; i++) {
    var isDup = false;

    // check if letter is already in string
    for (var j=0; j<i; j++) {
      // if duplicate, we can stop searching and just move on
      if (str[j] === str[i]) {
        isDup = true;
        break;
      }
    }

    if (!isDup) {
      str = str.substr(0, write) + str[i] + str.substr(write+1);
      write++;
    }
  }


  return str.substr(0, write);
}

// tests
var assert = require('assert');

describe('removeDups', function() {

  it('should not change a string w/o dups', function() {
    var alphabet = 'abcdefghijklmnopqrstuvwxyz';
    assert.equal(removeDups(''), '');
    assert.equal(removeDups('a'), 'a');
    assert.equal(removeDups(alphabet), alphabet);
  });

  it('should remove dups', function() {
    var alphabet = 'abcdefghijklmnopqrstuvwxyz';
    assert.equal(removeDups('aa'), 'a');
    assert.equal(removeDups('abcadef'), 'abcdef');
    assert.equal(removeDups(alphabet + 'z'), alphabet);
  });

});
