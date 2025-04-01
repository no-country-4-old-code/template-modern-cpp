# Template for C++ Projects

This is my template for C++ projects. It is based on CMake to work with different compilers (GCC, Clang, MSVC) and build systems (Make, Ninja, etc.).

## Features
- Verify your code with [Google Test](https://github.com/google/googletest).
- Create test coverage reports via [gcovr](https://gcovr.com/en/stable/).
- Perform static code analysis using [Clang-Tidy](https://clang.llvm.org/extra/clang-tidy/) and [Cppcheck](http://cppcheck.net/).
- Utilize compiler flags to ensure quality during compile time.
- Detect memory leaks & race conditions with [sanitizers](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html).
- Format your code using [Clang-Format](https://clang.llvm.org/docs/ClangFormat.html).
- Integrate Python scripts for custom code analysis [Python](https://www.python.org/).
- Lint and format CMake files using [cmake-lint](https://cmake-format.readthedocs.io/en/latest/cmake-lint.html) and [cmake-format](https://cmake-format.readthedocs.io/en/latest/cmake-format.html).
- Document your code with [Doxygen](https://www.doxygen.nl/).

By default, all of these features are disabled to shrink the requirements for building the application to a compiler and a build system.
You can easily enable these features by modifying `CMakeLists.txt` or running CMake with the -D* option.
See **Building the project** for further instructions.

Have fun!

**nc4oc**  
No-Country-4-Old-Code

---

## Software Requirements

### Option 1: The Docker Way
You only need Docker installed to build and run the containerized environment.

### Option 2: Manual Installation
If you prefer a manual setup, install the following dependencies:
- **CMake 3.28+**
- **A compiler** (GCC, Clang, MSVC) and a **build system** (Make, Ninja). GCC and Make are recommended because "code coverage" currently works only with GCC & gcovr.

To use optional features like Google Test, you need to install several other tools. Check the `Dockerfile` under `tools/Dockerfile` for the installation process.

---

## Working with the Docker Container

### Running the Docker Container
Use either the precompiled Docker image:
```sh
docker run -di --mount type=bind,src=.,dst=/workspace nc4oc/toolchain-cpp:latest
```
or build your own image if you prefer:
```sh
docker build -t some-image-name -f tools/Dockerfile .
docker run -di --mount type=bind,src=.,dst=/workspace some-image-name
```
Run the command from the project's root directory. The container will mount this folder (`src=.`).

### Attaching to the Docker Container
Most IDEs allow attaching to a running Docker container (e.g., Visual Studio Code with the "Dev Containers" plugin).  
To do it via the console, first find the container ID:
```sh
docker ps
```
Then attach to it:
```sh
docker attach <ID-of-your-container>
```

---

## Building the Project

> **Note:** The following steps assume you are using a Linux shell. If you are on Windows/macOS, use equivalent commands.

CMake is executed from within the `/build` directory. If `/build` does not exist, create it first:
```sh
mkdir -p build
cd build
```

### Build and Run the Application
```sh
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --target application
cd src/main
./application
```

### Build and Run Google Tests
```sh
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=ON ..
ctest
```

### Build and Generate Coverage Report
```sh
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=ON -DENABLE_UNITTEST_COVERAGE=ON ..
cmake --build . --target unittest-coverage
cd reports/coverage
ls *.html
```

### Build and Run Clang-Tidy
```sh
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_CLANG_TIDY=ON ..
cmake --build . --target clang-tidy
```

### Build and Run... Whatever
Take a look in `CMakeLists.txt`.
If you want to enable the option "ENABLE_PYTHON_SCRIPT," just configure it with:
```sh
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_PYTHON_SCRIPT=ON ..
```
This enables the build target "python-script," which can be executed by:
```sh
cmake --build . --target python-script
```

---

Happy coding! 🚀

