# Project TestBot 

Test Robot 

# Installation 

```
pip install conan
choco install cmake

conan remote add conancenter https://center.conan.io
conan search poco --remote=conancenter
conan inspect poco/1.12.4
mkdir build && cd build
conan install ..

cmake .. -G "Visual Studio 17"
cmake --build . --config Release
cd ..
```

# Gotcha 

poco is small case - if you put Poco instead of poco in conanfile.txt, it will complain:

```
ERROR: Requested 'Poco/1.12.4', but found case incompatible recipe with name 'poco' in the cache. Case insensitive filesystem can't manage this.
Remove existing recipe 'poco' and try again.
```

# Visual Studio 
* Visual Studio 2019 is version 16
* Visual Studio 2022 is version 17
* so depends on what is installed you'd need to update profile and build.bat 

# Reference

<https://docs.conan.io/en/latest/getting_started.html>
<https://earthly.dev/blog/installandrun-cmake-on-windows/>