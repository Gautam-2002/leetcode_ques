/**
 * @param {number} millis
 */
// function resolveAfter2Seconds() {
//   return new Promise(resolve => {
//     setTimeout(() => {
//       resolve('resolved');
//     }, 2000);
//   });
// }

// async function asyncCall() {
//   console.log('calling');
//   const result = await resolveAfter2Seconds();
//   console.log(result);
//   // Expected output: "resolved"
// }
async function sleep(millis) {
    await new Promise(resolve=>{
        setTimeout(()=>{
            resolve(millis);
        },millis);
    })
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */