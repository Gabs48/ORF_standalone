ORF_standalone
==============

Stand alone acquisition software for ORF SwissRanger SR4K

1. Go to inside the ORF_standalone folder and create a build folder:
```
mkdir build
```
2. Go inside the build folder and create the makefile:
```
cd build
cmake ..
```

3. Compile the program:
```
make
```

4. Plug the ethernet ORF, change your IP to a static 192.168.1.1 (no need to change anything else) and launch the soft:
```
./Main
```

5. By default images are saved in *build/img*, calibration matrix in *build* and timestamp data in *build*
