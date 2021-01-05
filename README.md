# Distributed File System (dfs)

To get the project to build, make sure conan is installed using _pip_
<code>\$ pip install conan</code>

Then, in the directory _cmake-build-debug_, run
<code>\$ conan install ..</code>

## Preprocessor Order
  - Guard
  - C++ Libraries
  - C Libraries
  - 3rd Party Libraries
  - Local Headers
  - Defines
