function hasAllUnique(str) {
  var hasSeen = new Array(256);

  for (var i=0; i<str.length; i+=1) {
    var code = str.charCodeAt(i);
    if (hasSeen[code]) {
      return false;
    }

    hasSeen[code] = true;
  }

  return true;
}

// tests
var assert = require('assert');

describe('hasAllUnique', function() {

  it('should fail', function() {
    assert.equal(hasAllUnique('aa'), false);
    assert.equal(hasAllUnique('abcdefghijklmnopqrstuvwxyza'), false);
  });

  it('should succeed', function() {
    assert.equal(hasAllUnique('abcdefghijklmnopqrstuvwxyz'), true);
  });

});
