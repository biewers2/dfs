# Distributed File System (dfs)

### Building for the first time.
#### Conan: <code>$ sudo pip install conan</code>

In the directory _cmake-build-debug_...

Then, in the directory _cmake-build-debug_, run
1. <code>$ conan install ..</code>
2. <code>$ cmake build ..</code>


## Preprocessor Order
  - Guard
  - C++ Libraries
  - C Libraries
  - 3rd Party Libraries
  - Local Headers
  - Defines
