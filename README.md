ORF_standalone
==============

Stand alone acquisition software for ORF SwissRanger SR4K

- Go to inside the ORF_standalone folder and create a build folder:
```
mkdir build
```

- Go inside the build folder and create the makefile:
```
cd build
cmake ..
```

- Compile the program:
```
make
```

- Plug the ethernet ORF, change your IP to a static 192.168.1.1 (no need to change anything else) and launch the soft:
```
./Main
```

- By default images are saved in *build/img*, calibration matrix in *build* and timestamp data in *build*
