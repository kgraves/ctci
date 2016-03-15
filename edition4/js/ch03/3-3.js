var SetOfStacks = function(limit) {
  this.stacks = [[]];
  this.currentStack = 0;
  this.limit = limit;
}

SetOfStacks.prototype.push = function(value) {
  if (this.stacks[this.currentStack].length >= this.limit) {
    this.currentStack += 1;
    this.stacks.push([]);
  }

  this.stacks[this.currentStack].push(value);
}

SetOfStacks.prototype.pop = function() {
  if (this.stacks[this.currentStack].length <= 0) {
    this.currentStack -= 1;
    this.stacks.pop();
  }

  return this.stacks[this.currentStack].pop();
}

SetOfStacks.prototype.popAt = function(index) {
  var value = null;

  if (this.stacks[index] && this.stacks[index].length > 0) {
    value = this.stacks[index].pop();
  }

  return value;
}

// tests
var assert = require('assert');

describe('SetOfStacks', function() {

  describe('push', function() {

    it('should push values into stacks correctly', function() {
      var s = new SetOfStacks(2);
      s.push(1);
      s.push(2);
      s.push(3);
      s.push(4);
      s.push(5);
      assert.equal(s.stacks[0].length, 2);
      assert.equal(s.stacks[1].length, 2);
      assert.equal(s.stacks[2].length, 1);
    });

  });

  describe('pop', function() {

    it('should pop values from stacks correctly', function() {
      var s = new SetOfStacks(2);
      s.push(1);
      s.push(2);
      s.push(3);
      assert.equal(s.stacks[1].length, 1);
      s.pop();
      assert.equal(s.stacks[1].length, 0);
      s.pop();
      assert.equal(s.stacks[0].length, 1);
      assert.equal(s.currentStack, 0);
    });

  });

  describe('popAt', function() {

    it('should return null', function() {
      var s = new SetOfStacks(2);
      s.push(1);
      s.push(2);
      assert.equal(s.popAt(2), null);
    });

    it('should pop values from given stack index', function() {
      var s = new SetOfStacks(2);
      s.push(1);
      s.push(2);
      s.push(3);
      s.push(4);
      s.push(5);
      assert.equal(s.popAt(0), 2);
      assert.equal(s.popAt(1), 4);
      assert.equal(s.popAt(2), 5);
    });

  });

});
