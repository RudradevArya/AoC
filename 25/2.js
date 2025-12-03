/////////////////////////////PART 1
// 
// const fs = require('fs');
// fs.readFile("C:\\Users\\z00562tu\\Downloads\\AoC-25\\2-input.txt", (err, data) => {
//     // console.log(data.toString());
//     const l = data.toString().trim().split(',');
//     // console.log(l);
//     let cnt = 0;
//     // console.log(l.length);
//     let num = l[0].split('-');
//     // console.log(num[0], num[1]);
//     for(let j=0; j<l.length; j++){
//         num = l[j].split('-');
//         for(let i=num[0]; i<=num[1]; i++){
//             if(check(i)){
//                 cnt+=i;
//             }
//         }
//     }
//     console.log(cnt);
// });


// function check(num) {
//     const str = String(num);
//     if (str.length % 2 !== 0) return false;

//     const mid = str.length / 2;
//     return str.slice(0, mid) === str.slice(mid);
// }


const fs = require('fs');
fs.readFile("C:\\Users\\z00562tu\\Downloads\\AoC-25\\2-input.txt", (err, data) => {
    // console.log(data.toString());
    const l = data.toString().trim().split(',');
    // console.log(l);
    let cnt = 0;
    // console.log(l.length);
    let num = l[0].split('-');
    // console.log(num[0], num[1]);
    for(let j=0; j<l.length; j++){
        num = l[j].split('-');
        const start = Number(num[0]);  // Convert to number!
        const end = Number(num[1]);
        for(let i=start; i<=end; i++){
            if(check(i)){
                cnt+=i;
            }
        }
    }
    console.log(cnt);
});


function check(num) {
    const str = String(num);
    const len = str.length;
    
    // Try all possible pattern lengths from 1 to len/2
    for (let patLen = 1; patLen <= len / 2; patLen++) {
        // Pattern length must divide evenly into total length
        if (len % patLen !== 0) continue;
        
        const pattern = str.slice(0, patLen);
        const repeated = pattern.repeat(len / patLen);
        
        if (repeated === str) {
            return true;  // Found a repeating pattern!
        }
    }
    return false;
}
