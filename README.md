# 2048 Project
This project was made by Victor Daviau and Parsa Farjam for the CS 111 Imperative Programming course at Paris-Saclay University. As this course was in French, all of the comments used in the code and (most of) the variable names we chose are in French, although we mostly stuck to English for Pull Requests, Issues and Commit Messages on this repo. 

## What is it?
It is a recreation of the famous 2048 game in C++. It can be either played in graphical mode or in any UNIX-based console. It is made using exclusively standard C++ libraries (except `SDL` which is used to render the GUI).

## Features
- Graphical and Terminal modes
- Theme selector
- Score calculator

## Notes
The standard console-based version will fail to clear the screen after each move if using Windows. Because of this, a Windows-specific version of the main source file (2048.cpp) is provided in this repository, along with a pre-compiled executable if you just want to play the game. Both go by the name `2048_win` instead of `2048`. (Note: in order to compile this version you will need to change its name back to just `2048` or modify the makefile accordingly.
