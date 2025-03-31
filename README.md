# My Template For C++ Projects

This is my template for modern C++ projects.
It is based on CMake to work with different compilers (gcc, clang, MSCV) and build systems (make, ninja, etc).

- Verify your code with [Google tests](https://github.com/google/googletest)
- Create a test Coverage Reports via [gcovr](https://gcovr.com/en/stable/)
- Run a static code analysis thanks to [clang-tidy]() and [cppcheck]()
- Use the full bandwidth of compiler-flags to ensure quality during compile time
- Find memory-leaks & race conditions faster with [sanitizers]()
- Format your code using [clang-format]()
- Add your python-scripts to run custom code analysis [python]()
- Lint and format your CMake-files using [cmake-lint]() and [cmake-format]() 
- Documente your code with [Doxygen](https://doxygen.nl/)
- ...

All these features are optional - modify the root CMakeLists.txt or configure cmake with e.g -DTESTS=ON to enable certain features.
Most of these features are seperate build-targets which can run independt from the main application.

Have fun,
nc4oc

(No-Country-4-Old-Code)

## Software Requirements

#Option 1:
The docker way.
All you need is the installed docker engine to build/run docker-containers.

#Option 2:
You are not a friend of docker ?
Then welcome to the manual installation process.
To build the main application you need:
- CMake 3.28+
- A compiler (gcc, clang, msvc) and a build system (make, ninja). I would recommend gcc and make, because "code coverage" is currently only working with gcc && gcovr.

To use the optional features like google-test etc. you need to install serveral other tools.
Please take a look at the Dockerfile under tools/Dockerfile to see the install process. 

## Working with the Docker Container

# Running the Docker Container
Use either the precompiled docker-image 
```shell
docker run -di --mount type=bind,src=.,dst=/workspace nc4oc/toolchain-cpp:latest
```
or (if you somehow do not trust a random image build by a stranger with funny name) build your own using the Dockerfile under tools/Dockerfile 

```shell
docker build -t /tools/Dockerfile  some-image-name
docker run -di --mount type=bind,src=.,dst=/workspace some-image-name
```

In both cases execute the command from the root of the project.
You now have a running docker-container which mounts this folder (src=.)

# Attaching to the Docker Container
 Most IDEs offer the possibility to attach to a running docker-container-process (E.g. Visual Studio Code with the "Dev Containers" plugin)

 If you want to do it via console figure out the ID of your container using

```shell
docker ps
```
and then attach to it using

```shell
docker attach <ID-of-your-container>
```

## Building
! In the following steps I assume that you are in a linux bash.
If you are using windows / mac you have to use the pendant commands.

CMake is executed from within /build.
If /build does not exist, create it first.

```shell
mkdir -p build
cd build
```

# Build and run the application

```shell
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --target application
cd src/main
./application
```


# Build and run google tests
```shell
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=ON ..
ctest
```

# Build and generate coverage report
```shell
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=ON -DENABLE_UNITTEST_COVERAGE=ON ..
cmake --build . --target unittest-coverage
cd reports/coverage
ls *.html
```

# Build and run clang-tidy

```shell
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_CLANG_TIDY=ON ..
cmake --build . --target clang-tidy
```

# Other..
Please take a look at CMakeLists.txt to see all possible configure options and related build-targets.


