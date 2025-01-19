Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

Example 1:


Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.
Example 2:


Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10
 

Constraints:

m == heightMap.length
n == heightMap[i].length
1 <= m, n <= 200
0 <= heightMap[i][j] <= 2 * 104



/**
 * @param {number[][]} heightMap
 * @return {number}
 */
var trapRainWater = function(heightMap) {
    var m=heightMap.length, n=heightMap[0].length;
    var max = 0, volume = 0;
    for (var j=0; j<m; j++){
        for (var i=0; i<n; i++){
            if (max<heightMap[j][i]){max=heightMap[j][i]}
            volume+=heightMap[j][i];
        }
    }

    var waterL = Array.from({length:m},()=>new Uint16Array(n).fill(max));
    var inQueue = Array.from({length:m},()=>new Uint8Array(n).fill(0));
    var queues=Array.from({length:max+1},()=>[]);

    var water = m*n*(max)-volume;

    for (var i=0; i<n; i++){
        if (waterL[0][i]>heightMap[0][i]){
            water-=(waterL[0][i]-heightMap[0][i]);
            waterL[0][i]=heightMap[0][i];
            queues[waterL[0][i]].push([0,i]);
            inQueue[0][i]=1;
        }
        if (waterL[m-1][i]>heightMap[m-1][i]){
            water-=(waterL[m-1][i]-heightMap[m-1][i]);
            waterL[m-1][i]=heightMap[m-1][i];
            queues[waterL[m-1][i]].push([m-1,i]);
            inQueue[m-1][i]=1;
        }
    }
    for (var j=1; j<m-1; j++){
        if (waterL[j][0]>heightMap[j][0]){
            water-=(waterL[j][0]-heightMap[j][0]);
            waterL[j][0]=heightMap[j][0];
            queues[waterL[j][0]].push([j,0]);
            inQueue[j][0]=1;
        }
        if (waterL[j][n-1]>heightMap[j][n-1]){
            water-=(waterL[j][n-1]-heightMap[j][n-1]);
            waterL[j][n-1]=heightMap[j][n-1];
            queues[waterL[j][n-1]].push([j,n-1]);
            inQueue[j][n-1]=1;
        }
    }    
    // console.log(waterL,"\n",water,queues, inQueue);

    var pointer = [0,0];
    while (pointer[0]<queues.length){
        if (pointer[1]==queues[pointer[0]].length){
            pointer[0]++;
            pointer[1]=0;
            continue;
        }

        var j = queues[pointer[0]][pointer[1]][0], i = queues[pointer[0]][pointer[1]][1];
        var curLevel = waterL[j][i];

        if (j>0 && !inQueue[j-1][i] && waterL[j-1][i]>heightMap[j-1][i]){
            var startL=waterL[j-1][i];
            waterL[j-1][i]=Math.max(waterL[j][i],heightMap[j-1][i]);
            water-=(startL-waterL[j-1][i]);
            queues[waterL[j-1][i]].push([j-1,i]);
            inQueue[j-1][i]=1;
        }
        if (j<m-1 && !inQueue[j+1][i] && waterL[j+1][i]>heightMap[j+1][i]){
            var startL=waterL[j+1][i];
            waterL[j+1][i]=Math.max(waterL[j][i],heightMap[j+1][i]);
            water-=(startL-waterL[j+1][i]);
            queues[waterL[j+1][i]].push([j+1,i]);
            inQueue[j+1][i]=1;
        }        
        if (i>0 && !inQueue[j][i-1] && waterL[j][i-1]>heightMap[j][i-1]){
            var startL=waterL[j][i-1];
            waterL[j][i-1]=Math.max(waterL[j][i],heightMap[j][i-1]);
            water-=(startL-waterL[j][i-1]);
            queues[waterL[j][i-1]].push([j,i-1]);
            inQueue[j][i-1]=1;
        }
        if (i<n-1 && !inQueue[j][i+1] && waterL[j][i+1]>heightMap[j][i+1]){
            var startL=waterL[j][i+1];
            waterL[j][i+1]=Math.max(waterL[j][i],heightMap[j][i+1]);
            water-=(startL-waterL[j][i+1]);
            queues[waterL[j][i+1]].push([j,i+1]);
            inQueue[j][i+1]=1;
        }
        pointer[1]++;
    }
    // console.log(waterL,"\n",water,queues, inQueue);
    return water;
};
