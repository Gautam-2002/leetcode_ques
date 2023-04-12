/**
 * @param {Object} object
 * @param {Function} classFunction
 * @return {boolean}
 */
// In Javascript, inheritance is achieved with the prototype chain.
// You can get the prototype of an object with the Object.getPrototypeOf(obj) function. Alternatively, you can code obj['__proto__'].
// You can compare an object's __proto__ with classFunction.prototype.
// Traverse the entire prototype chain until you find a match.
var checkIfInstanceOf = function(obj, classFunction) {
    while(obj != null){
        if(obj.constructor==classFunction)
            return true;
        obj = Object.getPrototypeOf(obj);
    }
    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */