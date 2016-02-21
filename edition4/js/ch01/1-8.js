function isRotation(str1, str2) {
  return (str1 + str1).indexOf(str2) === -1 ? false : true;
}

// tests
var assert = require('assert');

describe('isRotation', function() {

  it('should fail', function() {
    assert.equal(isRotation('This is a test', 'This is a testz'), false);
    assert.equal(isRotation('This is a test', 'This is as'), false);
  });

  it('should succeed', function() {
    assert.equal(isRotation('This is a test', 'a testThis is'), true);
  });

});
