## Solid Voxelization base on Octree
*ONLY support OBJ file  
This program is small and no other denpendeces, so compile and build it is very fast.  
![slice](gif/slice.gif)

## Build
Successfully build in win11 / vs2019  
```
mkdir build && cd build
cmake ..
```

## View the example
use the SimpleViewer.exe in output file
```
cd output
.\SimpleViewer.exe .\Armadillo_64.obj
```

## Visual benchmarking
CPU : Intel i7-12700
### Optimazation
loadOBJ: 7.637 ms  
BuildOctree: 5,841.827 ms  
outputOBJ: 1015.288ms   
![1647938757(1)](https://user-images.githubusercontent.com/80893143/159441957-bc644d7a-4c7c-4c12-a674-a9c6c13fae77.png)  
  
  
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

