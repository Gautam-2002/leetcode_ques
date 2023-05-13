/**
 * @param {Function} fn
 */
// function memoize(fn) {
//     let arr = {};
//     return function(...args) {
//         let arg = JSON.stringify(args);
//         // for(let i=0;i<arr.length;i++){
//         //     let {key,val} = arr[i];
//         //     if(key===arg)
//         //         return val;
//         // }
//         if(arg in arr)
//             return arr[arg];
//         let ans = fn(...args);
//         // arr.push({arg:ans})
//         arr[arg] = ans;
//         return ans;
//     }
// }
function memoize(fn) {
    const cache = new Map();
    return function(...args) {
        if(cache.has(JSON.stringify(args))){
            return cache.get(JSON.stringify(args));
        }
        const res = fn(...args);
        cache.set(JSON.stringify(args),res);
        return res;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */