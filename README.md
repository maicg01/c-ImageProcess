# c-ImageProcess

- Run

```
mkdir built
```

```
cmake ..
```

```
make
```

# link hieu kha ro rang ve cmake
https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b


# buil bang gcc
```
gcc -I/usr/local/include/opencv4 DisplayImage.cpp -o hw.exe

g++ DisplayImage.cpp -o image
g++ main.cpp -o cmake_hello -I/home/onur/libraries/boost/include -L/home/onur/libraries/boost -lBoost
```

# Chay cmakelist
```
$ mkdir build
$ cmake ..
$ ls -all
-rw-r--r--   1 onur  staff  13010 Jan 25 18:40 CMakeCache.txt
drwxr-xr-x  15 onur  staff    480 Jan 25 18:40 CMakeFiles
-rw-r--r--   1 onur  staff   4964 Jan 25 18:40 Makefile
-rw-r--r--   1 onur  staff   1256 Jan 25 18:40 cmake_install.cmake
$ make all
```

# Hieu lib CMakeFiles
- Shared Library File Extensions:

Windows: .dll

Mac OS X: .dylib

Linux: .so


- Static Library File Extensions:

Windows: .lib

Mac OS X: .a

Linux: .a

# Tai cac thu vien Release tren git
