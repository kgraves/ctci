function urlize(str) {
  return str.replace(/ /g, '%20');
}

// tests
var assert = require('assert');

describe('urlize', function() {

  it('should succeed', function() {
    assert.equal(urlize('hello world'), 'hello%20world');
    assert.equal(urlize(' '), '%20');
    assert.equal(urlize('a a a'), 'a%20a%20a');
  });

});
