# fuzzapifile
Generate test case files for API fuzz testing

1) Generate test files using Python, that represent function calls and their input parameters
2) Fuzz the files with AFL
3) Parse the fuzzed files within a C test program looking for API errors

This is a fork of the test case file generation code from [TriforceLinuxSyscallFuzzer](https://github.com/nccgroup/TriforceLinuxSyscallFuzzer)

## Build

1) Install AFL
  ```
  wget http://lcamtuf.coredump.cx/afl/releases/afl-latest.tgz
  cd afl-2.52b
  make
  sudo make install
  ```

2) Make library

  ```
  cd fuzzapifile
  make
  ```
  
## Running Example
  ```
  cd example
  make
  ./gen_testcases.py
  ./target < testscases/base.dat
