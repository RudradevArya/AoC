//////////////PART 1
// 
// // const fs = require('fs');
// fs.readFile("C:\\Users\\z00562tu\\Downloads\\AoC-25\\3-input.txt", (err, data) => {
//     const l = data.toString().trim().split('\n');
//     // console.log(l);
//     // console.log(l.length);
//     // console.log(l[0]);

//     let sum = 0;
//     for(let i=0; i<l.length; i++) {
//         let max =check(l[i]);
//         // console.log(max);
//         sum += max;
//     }
//     console.log(sum);
// });

// function check(l) {
//     let d1=0, d2=0, curr=0, max=0;
//     for(let i=0; i<l.length-1; i++) {
//         for(let j=i+1; j<l.length; j++) {
//             d1=parseInt(l[i]);
//             d2=parseInt(l[j]);
//             curr = d1*10 + d2;

//             if(curr > max) {
//                 max = curr;
//             }
//         }
//     }

//     return max;
// }

////////////// part 2
const fs = require('fs');
fs.readFile("C:\\Users\\z00562tu\\Downloads\\AoC-25\\3-input.txt", (err, data) => {
    const l = data.toString().trim().split('\n');
    // console.log(l);
    // console.log(l.length);
    // console.log(l[0]);

    //BigINt
    // let sum = 0;
    // for(let i=0; i<l.length; i++) {
    //     let max =check(l[i]);
    //     // console.log(max);
    //     sum += max;
    // }
    // console.log(sum);
    let tot = BigInt(0);
    for(let i=0; i<l.length; i++) {
        const maxi = check(l[i]);
        tot += BigInt(maxi);
    }
    console.log(tot);
    // console.log(check(l[0][1]));
});

function check(l) {
    let res="";
    // let rem = 12;
    let N = l.length;
   
    let startIdx = 0;
    for(let i=startIdx; i<12; i++) {
        const rem = 12 - i;
        let maxIdx = N - rem; //15-12=3

        let maxDig = 0, idx = 0;
        for(let j=startIdx; j<=maxIdx; j++) {
            const curr = parseInt(l[j]);
            if(curr > maxDig) {
                maxDig = curr;
                idx = j;
                
                if(maxDig == 9) break;
            }
        }
        res += maxDig.toString();
        startIdx = idx + 1;
        // console.log(maxDig);
        // console.log(maxIdx);
        // console.log(idx);
        // console.log(res);
    }
    return res;
}

