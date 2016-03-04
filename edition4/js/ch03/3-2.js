var StackNode = function(value, min) {
  this.value = value;
  this.min = min;
}

var Stack = function() {
  this.buffer = [];
}

Stack.prototype.push = function(value) {
  var min = Math.min(value, this.min());
  this.buffer.push(new StackNode(value, min));
}

Stack.prototype.pop = function() {
  return this.buffer.pop();
}

Stack.prototype.min = function() {
  if (this.buffer.length <= 0) {
    return Infinity;
  } else {
    return this.buffer[this.buffer.length - 1].min;
  }
}

Stack.prototype.peek = function() {
  return this.buffer[this.buffer.length - 1];
}

// tests
var assert = require('assert');

describe('Stack', function() {

  describe('push', function() {

    it('should insert correctly', function() {
      var s = new Stack();
      s.push(1);
      s.push(2);
      assert.equal(s.peek().value, 2);
      s.push(3);
      assert.equal(s.peek().value, 3);
    });

  });

  describe('pop', function() {

    it('should pop correctly', function() {
      var s = new Stack();
      s.push(1);
      s.push(2);
      assert.equal(s.peek().value, 2);
      s.push(3);
      assert.equal(s.pop().value, 3);
      assert.equal(s.peek().value, 2);
    });

  });

  describe('min', function() {

    it('should find min correctly', function() {
      var s = new Stack();
      assert.equal(s.min(), Infinity);
      s.push(12);
      assert.equal(s.min(), 12);
      s.push(30);
      assert.equal(s.min(), 12);
      s.push(3);
      assert.equal(s.min(), 3);
    });

  });

  describe('peek', function() {

    it('should peek correctly', function() {
      var s = new Stack();
      s.push(1);
      assert.equal(s.peek().value, 1);
      s.push(2);
      assert.equal(s.peek().value, 2);
    });

  });

});
