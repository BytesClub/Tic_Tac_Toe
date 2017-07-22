# Tic_Tac_Toe
A simple Tic_Tac_Toe implementation in C

&copy; All rights reserved by **Bytes Club 2017**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/3efc459239d94d19ade57820e69b8d60)](https://www.codacy.com/app/BytesClub/Tic_Tac_Toe?utm_source=github.com&utm_medium=referral&utm_content=BytesClub/Tic_Tac_Toe&utm_campaign=badger)
[![Issues](https://img.shields.io/github/issues/BytesClub/Tic_Tac_Toe.svg)](https://github.com/BytesClub/Tic_Tac_Toe/issues)
[![Pull Request](https://img.shields.io/github/issues-pr/BytesClub/Tic_Tac_Toe.svg)](https://github.com/BytesClub/Tic_Tac_Toe/pulls)
[![Releases](https://img.shields.io/github/release/BytesClub/Tic_Tac_Toe.svg)](https://github.com/BytesClub/Tic_Tac_Toe/releases)
[![Mailing List](https://img.shields.io/badge/Mailing%20List-BytesClub-blue.svg)](mailto:bytes-club@googlegroups.com)
[![gitter](https://badges.gitter.im/gitterHQ/gitterHQ.github.io.svg)](https://gitter.im/Bytes_Club/General)

### Table of Content
1. [Objectives](#objectives)
2. [Recommended Reading](#recommended-reading)
3. [Academic Honesty](#academic-honesty)
4. [Prerequisite](#prerequisite)
5. [Getting Started](#getting-started)
6. [The Gameplay](#the-gameplay)
7. [Helper.H](#helperh)
8. [Your task](#your-task)
9. [How to Submit](#how-to-submit)

### Objectives
* Getting comfortable with Linux Environment
* Become familiar with GitHub and Open-source contribution
* Understanding fundamental of modular-development
* Solving problems in procedural-oriented technique (C)
* Making a simple board game in the end of the day

### Recommended Reading
* Bytes Club Blog post on [Git](https://bytesclub.github.io/2017/02/23/introduction-to-git/) and [SSH](https://bytesclub.github.io/2017/03/01/introduction-to-ssh/)
* Bytes Club [Coding Style](https://bytesclub.github.io/docs/coding_style.pdf)
* Programming in ANSI C - _E. Balaguruswamy_
* The C Programming Language - _B.W. Kerningham & D.M. Ritchie_

### Academic Honesty
#### Reasonable
* Communicating with classmates about problem sets' problems in English (or some other spoken language).

* Discussing the course’s material with others in order to understand it better.

* Helping a classmate identify a bug in his or her code at office hours, elsewhere, or even online, as by viewing, compiling, or running his or her code, even on your own computer.

* Incorporating snippets of code that you find online or elsewhere into your own code, provided that those snippets are not themselves solutions to assigned problems and that you cite the snippets' origins.

* Sending or showing code that you’ve written to someone, possibly a classmate, so that he or she might help you identify and fix a bug.

* Sharing snippets of your own code online so that others might help you identify and fix a bug.

* Turning to the web or elsewhere for instruction beyond the Club’s own, for references, and for solutions to technical difficulties, but not for outright solutions to Club’s given problems.

* Whiteboarding solutions to problem sets with others using diagrams or pseudocode but not actual code.

#### Not Reasonable
* Accessing a solution to some problem prior to (re-)submitting your own.

* Asking a classmate to see his or her solution to a problem set’s problem before (re-)submitting your own.

* Failing to cite (as with comments) the origins of code or techniques that you discover outside of the Club’s own lessons and integrate into your own work, even while respecting this policy’s other constraints.

* Giving or showing to a classmate a solution to a problem set’s problem when it is he or she, and not you, who is struggling to solve it.

* Paying or offering to pay an individual for work that you may submit as (part of) your own.

* Providing or making available solutions to problem sets to individuals who might contribute to this in the future.

* Searching for or soliciting outright solutions to problems online or elsewhere.

* Splitting a problem set’s workload with another individual and combining your work.

* Submitting (after possibly modifying) the work of another individual beyond allowed snippets.

* Submitting the same or similar work to this course that you have submitted or will submit to another.

* Submitting work to this club that you intend to use outside of the course (e.g., for a job) without prior approval from the club’s heads or your mentor.

* Using resources during a quiz beyond those explicitly allowed in the quiz’s instructions.

* Viewing another’s solution to a problem set’s problem and basing your own solution on it.

### Prerequisite
* **OS:** Linux
	* GCC
	* Git CMD
	* Any text editor
* **OS:** Windows
	* MinGW
	* Git Bash
	* Any text editor
* A GitHub account
* Download [GitHub on Terminal](https://github.com/BytesClub/ghb) and get notified about GitHub Issues/PR on your bash terminal

_**Note:** For Turbo C++ 4.5 or above use the IDE and DSW file for resolving  compatibility issue._

### Getting Started
* Fork the repository to your profile.
* Open your terminal window and run the following
```
$ git clone git@github.com:<your_profile>/Tic_Tac_Toe.git
$ cd Tic_Tac_Toe/
```
* Make sure your local repository contains every file including this README
* Now execute the following _(or MinGW equivalent)_ at the terminal
```
$ make
```
   *If it gives any error, immidiately notify by registering an issue*
* Now your repository will have a directory named `bin` containing binary executable file named as `play`
* Open `helper.h` in your text editor and understand which functions are already given.
* Open `helper.c` to view the implementation of those function done previously

### The Gameplay
Open `main.c` in your text editor and you will see the following
```
int main(int argc, char *argv[])
```
This line indicates that the program expects **Command-Line Arguments**. Actually, the program expects an integer as it's argument. This integer represents the number of rows/columns in the board. Here we used a function `atoi()` which converts a string into equivalent integer.

If you do this:
```
./bin/play
```
It will generate error:
```
Usage: ./bin/play n
n: Dimension of the Board
```

If you go through the `main` function you will notice the following:
```
if (N < DIM_MIN || N > DIM_MAX) {
```
`DIM_MIN` and `DIM_MAX` are two MACRO defined in `helper.h`, whose purpose in life is to give the minimum_(3)_ and maximum_(9)_ limit of the board size respectively.

Instead, if you run the following
```
$ ./bin/play 3
```
It will produce following result
```
WELCOME TO GAME OF TIC_TAC_TOE

...

  1 |  2 |  3
--------------
  4 |  5 |  6
--------------
  7 |  8 |  9
```
The program will ask the user for the position to put **`X`** or **`O`** and will act accordingly. In the end it will announce the winner, if any, or if it's a tie.

### Helper.H
Navigate to `helper.h` and see the Include directives, MACRO definitions and function prototypes given to you and their functionality. You can also open `helper.c` and see the implementation of some of the functions. What happening during compile-time is the file `helper.c` is being compiled separately and later being linked to `main.c` via `helper.h`. You will learn more about this [here](https://www.dartmouth.edu/~rc/classes/softdev_linux/complex_compile.html).

### Your Task
Navigate to `hepler.c` and see the function mentioned as **`TODO`** (or you can view them in `Issue` tab). Your task is to complete the implementation of those methods and applying/calling them from your _**main**_ function. You may add some additional features to make it impressive to the user. In a way such that, after completion and compilation, it will work smooth and fine!

### How To Submit
* Update your local repository with latest in the Club.
```
$ git remote add upstream https://github.com/BytesClub/Tic_Tac_Toe.git
$ git fetch upstream
$ git checkout master
$ git rebase upstream/master
```
* Create a new branch in your local as well as remote repository
```
$ git checkout -b <your-branch>
```
* Complete the implementation of the functions mentioned as **TODO**
* Complete the main function.
* Compile and execute to be sure that it's working.
* Execute the following
```
$ git add -A
$ git commit
Shortlog: Commit Title
Commit description
Fixes: #issue_number
Signed-off-by: your_name <email>
$ git push origin <branch-name>
```
* **Your commit should not contain the binary executable file**
* **Your commit should not make effect in master branch**
* Create a `Pull Request` to the Club repository or send a email containing the `patch`.
* Wait for a response from Club Heads.

### Reference
[Contribution Guidelines](/CONTRIBUTING.md)

[Code of Conduct](/CODE_OF_CONDUCT.md)

#### Happy Coding :)
