const fs = require("fs");
/**
 * Write Polyfills for the following

Function.prototype.call
Function.prototype.apply
Function.prototype.bind
Array.prototype.map
Array.prototype.filter
Array.prototype.reduce
Array.prototype.forEach
Debounce
Throttle
Memoize
Promise.all
Once

Function currying fn(a, b, c, ..., n) => fn(a)(b)(c)...(n)

 * 
 */

// readLocalFile("./input.txt");

function readLocalFile(path) {
  try {
    const fileData = fs.readFileSync(path, "utf-8");
    console.log(fileData);
  } catch (error) {
    console.error("Error in file reading " + error);
  }
}

Function.prototype.myCall = function (context, ...args) {
  if (typeof this !== "function") throw new Error(`${this} is not a function`);
  context = context || globalThis;

  // create a unique key to avoid property colision
  const fnKey = Symbol("fn");

  // attach function to context
  context[fnKey] = this;

  const result = context[fnKey](...args);

  // delete fnKey from context to clean up the context
  delete context[fnKey];
  return result;
};

Function.prototype.myApply = function (context, args) {
  if (typeof this !== "function") throw new Error(`${this} is not a function`);

  context = context || globalThis;

  // create unique key to attach fn in context
  const fnKey = Symbol("fnKey");

  // set property in context
  context[fnKey] = this;

  const result = context[fnKey](...args);

  // clean up
  delete context[fnKey];
  return result;
};

Function.prototype.myBind = function (context, ...bindArgs) {
  if (typeof this !== "function") return new Error(this + "is not a function");
  const self = this;
  return function (...callArgs) {
    return self.myApply(context, [...bindArgs, ...callArgs]);
  };
};

Array.prototype.myFilter = function (callbackFn, thisArg) {
  if (typeof this === null)
    throw new Error("Array.prototype.myFilter cannot iterate over null");
  if (typeof callbackFn !== "function")
    throw new Error(callbackFn + " is not a function");
  const selfArr = Object(this); // incase `this` is primitive string, number, boolean

  const res = Array();

  for (let i = 0; i < selfArr.length; i++) {
    if (selfArr.hasOwnProperty(i)) {
      // skip over 'holes / sparse elements'
      if (callbackFn.myCall(thisArg, selfArr[i], i, selfArr)) {
        res.push(selfArr[i]);
      }
    }
  }
  return res;
};

Array.prototype.myMap = function (callbackFn, thisArg) {
  if (typeof this === null)
    throw new Error("Array.prototype.myMap cannot iterate over null");
  if (typeof callbackFn !== "function")
    throw new Error(callbackFn + " is not a function");

  const selfArr = Object(this); // to handle primitives

  const res = Array();

  for (let i = 0; i < selfArr.length; i++) {
    if (selfArr.hasOwnProperty(i)) {
      // use i in selfArr -> check for inherited properties as well
      const value = callbackFn.call(thisArg, selfArr[i], i, selfArr);
      res.push(value);
    }
  }
  return res;
};

Array.prototype.myReduce = function (callbackFn, initialVal) {
  if (this === null || this === undefined)
    throw new Error("Cannot iterate over null or undefined");
  if (typeof callbackFn !== "function")
    throw new Error(callbackFn + " is not a function");
  const accumulator = initialVal;
  const selfArr = Object(this);
  for (let i = 0; i < selfArr.length; i++) {
    if (i in selfArr) {
      accumulator = callbackFn(accumulator, selfArr[i], i, selfArr);
    }
  }
  return accumulator;
};

Array.prototype.forEach = function (callbackFn, thisArg) {
  if (this == null)
    throw new Error(
      "Array.prototype.forEach cannot iterate over null or undefined"
    );

  if (typeof callbackFn !== "function")
    throw new Error(callbackFn + " is not a function");

  const selfArr = Object(this); // to handle primitives or array-like objects as well

  for (let i = 0; i < selfArr.length; i++) {
    if (i in selfArr) {
      callbackFn.myCall(thisArg, selfArr[i], i, selfArr);
    }
  }
};

const myDebounceFn = (fn, delay) => {
  let timerId;
  return function (...args) {
    if (timerId) clearTimeout(timerId);
    timerId = setTimeout(() => {
      fn.apply(this, args);
    }, delay);
  };
};

// Leading Edge throttling -> immediate execution on the first call
function myThrottleLeading(fn, executionDelay) {
  let lastCall = 0;
  return function (...args) {
    const now = Date.now();
    if (now - lastCall >= executionDelay) {
      fn.apply(this, args); // executes immediately
      lastCall = now;
    }
  };
}

// Trailing edge throttling -> executed at the end of the limit
function myThrottleTrailing(fn, limit) {
  let timeoutId;
  return function (...args) {
    if (!!timeoutId) {
      timeoutId = setTimeout(() => {
        fn.apply(this, args); // invoked after limit delay
        timeoutId = null;
      }, limit);
    }
  };
}

function once(fn) {
  let isExecuted = false;
  return function (...args) {
    if (!isExecuted) {
      fn.apply(this, args);
      isExecuted = true;
    }
  };
}

/**
 *
 * @param {callbackFn} fn
 * @returns function
 */

function curry(fn) {
  return function curried(...args) {
    if (args.length >= fn.length) {
      return fn.apply(this, args);
    }
    return function (...nextArgs) {
      return curried.apply(this, args.concat(nextArgs));
    };
  };
}

// function sum(a, b, c) {
//   return a + b + c;
// }

// const currySum = curry(sum);
// console.log(currySum(5, 6)(9));

function groupBy(arr, key) {
  // Your implementation
  return arr.reduce((acc, element) => {
    let groupKey = element[key];
    if (groupKey in acc) {
      acc[groupKey].push(element);
    } else {
      acc[groupKey] = [element];
    }
    return acc;
  }, {});
}

const res = groupBy(
  [
    { name: "Alice", age: 25 },
    { name: "Bob", age: 30 },
    { name: "Charlie", age: 25 },
  ],
  "age"
);

console.log(res);
