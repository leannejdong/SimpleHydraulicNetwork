# SimpleHydraulicNetwork

## Implementation of hydraulic modelling of 
[A New Modeling Approach for Low-Carbon District Energy System Planning](https://www.mdpi.com/1996-1073/14/5/1383)

* There are 8760 sets of solutions for heat flows, with each contain 8 values. The first set of solutions is found as
```
  61.5766 11.5465 4.45635 13.4064 32.1674  25.424 2.71611 4.02726
```
8760 rows and 8 columns.

## Build Instruction

### Dependency required

- CMake = 3.12
- A Modern C++ compiler
- Eigen3.3
- doctest 
  
  [The fastest feature-rich C++11/14/17/20 single-header testing framework](https://raw.githubusercontent.com/onqtam/doctest/master/doctest/doctest.h)

### Linux

#### Build from terminal
(To avoid extra headache, set to absolute path whenever files need to be opened,
such as `NetworkSolve.cpp` and `read_write_test.cpp`.)
```
git clone git@github.com:leannejdong/SimpleHydraulicNetwork.git
cd SimpleHydraulicNetwork/
mkdir build
cd build
cmake ..
make
```
To run the main program
```
cd ..
build/SimpleHydraulicNetwork
```
To run the test suit
```
ctest
```



#### Build from CLion (Best choice for windows user)

Open the project directory and hit `shift-f10`

## Some expected outputs from main program and doctest

```shell
/home/leanne/CLionProjects/SimpleHydraulicNetwork/cmake-build-debug/HydraulicLib/basic_tests
[doctest] doctest version is "2.4.5"
[doctest] run with "--help" for options
The first set of solutions is 
61.5766 11.5465 4.45635 13.4064 32.1674  25.424 2.71611 4.02726
8760 rows and 8 columns.pass
===============================================================================
[doctest] test cases: 2 | 2 passed | 0 failed | 0 skipped
[doctest] assertions: 0 | 0 passed | 0 failed |
[doctest] Status: SUCCESS!

Process finished with exit code 0

```
