Here are some problems I'm currently working on; some follow lists, but a lot are just problems I find fun.

For context, my area of research is in SLAM/Computer Vision, as well as general NLP+ML/DL. As such, a lot of the problems I chose will have connections to geometry, or will have connections to vector/matrix operations.

# Current Problems to Work On

## 973. K Closest Points to Origin
This one seems pretty nice. My initial guess on approach is to use SELECT to find the nth order stat(the nth smallest number), and then use PARTITION to find all numbers <= that.

## 593. Valid Square
This doesn't seem to bad either, but seems interesting to attempt to solve.

A valid square is defined by 4 points such that we can define 4 segments that a) connect 2 different points and b) are defined in such a way that all 4 points are in 2 segments. 2 of them need to be parralel, and the segments perpendicular to them need to also be parralel.

Interesting problem.

## 2249. Count Lattice Points Inside a Circle
One more geometry problem. Haven't thought that much about this one, so I'll dig into this later.

## 53. Maximum Subarray
This is on Grind 75, and my older attempts didn't work. Gonna try this one again.

## 542. 01 Matrix
This is one Grind 75, and also has importance in SLAM(seems very similar to computing ESDFs to me). So, seems cool to solve.

## 200. Number of Islands
This is also on Grind 75, but has connections to my final project for FSE 598. I used disjoint sets and their union operator to union over points in 3D space given panoptic segmentation to yield object labels. This seems like a good approach for this problem; represent every 1 as a disjoint set initially, and then union 2 sets if they have any adjacents.

Creating a disjoint set type with a hash function for fast coordinate lookups might be a good approach.

## 5. Longest Palindromic Substring
I didn't solve this the first time, and it's on Grind 75. Gotta do this one.

## 621. Task Scheduler
This seems like a cool problem. Wann solve it, also on Grind 75.