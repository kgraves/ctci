var TripleStack = function() {
  this.STACK_SIZE = 100;
  this.buffer = new Array(this.STACK_SIZE * 3);
  this.topOfStacks = [0,0,0];
}

TripleStack.prototype.computeTopIndex = function(stackNum) {
  return (stackNum * this.STACK_SIZE) + this.topOfStacks[stackNum];
};

TripleStack.prototype.push = function(stackNum, value) {
  this.buffer[this.computeTopIndex(stackNum) + 1] = value;
  this.topOfStacks[stackNum] += 1;
}

TripleStack.prototype.pop = function(stackNum) {
  var value = this.buffer[this.computeTopIndex(stackNum)];
  this.topOfStacks[stackNum] -= 1;
  return value;
}

TripleStack.prototype.peek = function(stackNum) {
  return this.buffer[this.computeTopIndex(stackNum)];
}

// tests
var assert = require('assert');

describe('TripleStack', function() {

  describe('computeTopIndex', function() {

    it('should calculate correctly', function() {
      var s = new TripleStack();
      assert.equal(s.computeTopIndex(0), 0);
      s.topOfStacks[0] = 5;
      assert.equal(s.computeTopIndex(0), 5);
    });

  });

  describe('push', function() {

    it('should insert correctly', function() {
      var s = new TripleStack();
      s.push(0, 1);
      s.push(0, 2);
      assert.equal(s.peek(0), 2);
      s.push(0, 3);
      assert.equal(s.peek(0), 3);
    });

  });

  describe('pop', function() {

    it('should pop correctly', function() {
      var s = new TripleStack();
      s.push(0, 1);
      s.push(0, 2);
      s.push(0, 3);
      assert.equal(s.peek(0), 3);
      assert.equal(s.pop(0), 3);
      assert.equal(s.peek(0), 2);
    });

  });

  describe('peek', function() {

    it('should peek correctly', function() {
      var s = new TripleStack();
      s.push(0, 1);
      assert.equal(s.peek(0), 1);
      s.push(0, 2);
      assert.equal(s.peek(0), 2);
    });

  });

});
