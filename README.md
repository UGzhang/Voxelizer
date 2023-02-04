## Solid Voxelization base on Octree
*ONLY support OBJ file  
This program is small and no other denpendeces, so compile and build it is very fast.  
![slice](gif/slice.gif)

## Build
Successfully build in window11 (vs2019), Ubuntu 20.04 and Mac M1Pro
```
mkdir build && cd build
cmake ..
```

## Usage
```
$ ./SolidVoxelization -?

usage: ./SolidVoxelization [options] ... 
options:
  -i, --input        file path (string [=./Armadillo.obj])
  -o, --output       Output file path (string [=./Output.obj])
  -a, --analysis     time Analysis file path (string [=./timeAnalysis.json])
  -d, --dimension    dimension of voxelization (int [=64])
  -?, --help         print this message
  

1. put ./Armadillo.obj and ./SolidVoxelization in same directory
$ ./SolidVoxelization

2. Specify the file
$ ./SolidVoxelization -i "your path" -o "your path" -a "your path"
```


## Visual benchmarking
Env: Apple M1 Pro with 8 CPU, 14 GPU, 32G and 1T ssd
Test File: Armadillo.obj  

### Before Optimazation
loadOBJ: 4.520ms  
BuildOctree: 483.902ms  
outputOBJ: 133.618ms   
![1647938757(1)](https://user-images.githubusercontent.com/80893143/159441957-bc644d7a-4c7c-4c12-a674-a9c6c13fae77.png)  

### Before Optimazation
outputOBJ: 77.343 ms
  
### About timing  
https://www.youtube.com/watch?v=xlAH4dbMVnU&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=81


## Example
### Before solid voxelization
![1647933178](https://user-images.githubusercontent.com/80893143/159427255-0c3cbac5-9cd4-423f-a899-9314abee180f.png)

### 64 dimension solid voxelization
![1647933419(1)](https://user-images.githubusercontent.com/80893143/159427785-3d018c00-986b-49b6-87a9-8b5b173fd25a.png)

### 128 dimension solid voxelization
![1647933356(1)](https://user-images.githubusercontent.com/80893143/159427651-f2e829af-cf10-4bd6-8ae9-7019ecdb83d6.png)

### From
The origin version is from Peter Trier Mikkelsen
The video : https://www.youtube.com/watch?v=nK4GinCpEt8  
The tutorial : https://viscomp.alexandra.dk/index298d.html?p=3836  

