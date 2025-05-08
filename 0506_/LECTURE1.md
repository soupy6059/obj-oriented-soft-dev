- 2 teachers
- 2 grad students -> in tutorials

[shit](https://student.cs.uwaterloo.ca/~cs246/)
# USE EXTRA RESOURCES
- !gdb
- !valgrind
- !produceOutputs
- !runTestSuite

A | .4
M | .2
F | .4

"sure fire death"
"use == not ="

# To-Do List
Review the basics of C syntax from CS136. We're going to assume that you're familiar with this and thus won't cover where C and C++ are similar. In particular, pay attention to pointers and dynamic memory allocation since they are frequent sources of problems for students.
Look through the posted handouts, which are also available from the course public Git repository. Assignment 0, which is posted in Piazza, explains how to set up your copy of the repository. We recommend that you *also* clone the repository locally to make it easier to view the posted PDFs. Note that A0 has changed slightly from previous terms, so make sure to read it carefully!
We expect you to be familiar with the use of gdb and valgrind from CS136L. If you aren't familiar with them, or need a refresher, we have some resources available at https://student.cs.uwaterloo.ca/~cs246/S25/debugging.shtml that explain how to use them. In particular, certain run-time errors absolutely require the use of a debugger such as gdb, so spending some time now to learn the basics will save you hours in the future.
Part of your assignments will consist of developing test suites to verify that your implementations match the expected output in Marmoset. The suites that we ask you to write are compatible with the bash scripts produceOutputs and runSuite that you would have developed in CS136L. If you didn't take CS136L, or want to use an extended version of them for checking your code, compiled binaries have been provided in the tools directory of your public course repository.
Note that these binaries can only run in the CS undergraduate student environment.
produceOutputs takes an additional, optional "-e" flag to redirect standard error output to .err files, and trap program exit codes in .ret files. (Unfortunately, running with the "-e" flag then running without the "-e" flag causes the previously produced .err and .ret files to be removed in order to try and reduce problems from having a mixture of old and new output files.)
runSuite has 2 optional flags that may be specified in any order. "-e" will compare the .err and .ret files. "-v" runs the program being tested through valgrind and traps any resulting output in .mem files.
If you need a refresher on how to use these scripts for testing, see the resources at https://student.cs.uwaterloo.ca/~cs246/S25/testing.shtml.
Here's a command to ensure that your test suite contains all of the test cases, though it assumes that each question is in a separate directory:
ls *.{args,in} | cut -d'.' -f1 | uniq > suiteFile.txt
This reads all the files in your local directory that end in either ".args" or ".in", then splits them based on the file's extension, grabs the prefix of the filename, and then ensures no duplicates via uniq.
If you hard-coded a specific Linux server in your local .ssh/config file in CS136 to make it easier to use VS Code, check the current list of CSCF servers to make sure that you're using one that still exists. The full list of servers can be found at https://cs.uwaterloo.ca/cscf/teaching-hosts.

Grades
0 | 5 | 6 | 6 | 8 | 15
10 TUT questions ~ to exam ++additional credit to F

https://www.cppreference.com

3 POVS:
1) programmer => write correct code
2) complier
3) designer
