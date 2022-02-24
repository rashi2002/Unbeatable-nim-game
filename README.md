# Unbeatable Nim Game

**Author:** Rashi Mathur   
**Date:** 24-12-2021   
**Version:** 1.2   
**Earlier Contributors:** Dr. Stephen Kremer 


**Problem description**

*Please note that this is an academic project for CIS2520 Data Sturcutures course at the University of Guelph completed in the Fall 2021 academic semester. This code is for demonstration purposes only and may not be used and reused in any context.*

Create the nim game in C programming language which is unbeatable. Nim game is set up by arranging match sticks in groups of odd numbers (i.e, 1, 3, 5, 7, ...) and is played between two players. For the purpose of this project, one player will be the *user* and another will be the *computer* which must always win except for a special set of circumstances described in the limitations section of this document. On their turn, the players must remove any number match sticks from one given row. The player who picks up the last match stick loses the game. 
Further information on this game can be found at:
https://www.archimedes-lab.org/game_nim/play_nim_game.html


**Instructions to compile and run**   

*Please note the `clang` c compiler must be installed and configured with the standard paths and the user must be in the same directory that this file is in.*

1. Type the `make` command. 
2. This will generate the executable `alphanim` 
3. Run the program using the command `./alphanim [players] [list]` where [player] is the binary value 0 (for the computer to make the first move) or 1 (for the user to make the first move) and [list] is a space separated list of integers 

**Expected Output**   
The Program shoud display the initial board containing the specified amount of matches and should make a move if the computer goes first or prompt for input if the user goes first. It will print the state of the nim board at every turn and will print a message when the game is concluded. 

**Limitations and Future Improvements** 
1. While the program attempts mimics artificial intellegence by utilizing the graph data structure, it does so in a brute force manner. This causes the initial processing of the game to be extremely slow for larger boards. Advanced alogrithms derived from commonly used serarching and machine learning alogrithms can greatly improve the effeciency
2. To make the interface more user friendly, a web based graphical user interface can be created
