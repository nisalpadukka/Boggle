# Boggle Game Implementation (C++)

## Description

* The game begins with shaking a covered tray of 16 cubic dice, each with a different letter printed on each of its sides.

* The player should make words from adjoining letters. 

* The minimum length of a word should be 3

## Requirements

* Implement a data representation for the 'Game Board'
* Implement a dictionary which reads words from a text file
* Implement an algorithm to search the Game Board

## Implementation

### 1. Naive Word Finder

This is the simplest implementation which retrieves all the words in Boggle by recursively traversing (DFS) through the adjacent letters. Then check if word is exists in the dictionary.

Time Complexity : O(N^2 * M^2)

### 2. DFS based Lookup

Instead of brute-forcing all the words in the grid, we can simply run a DFS on all words present in dictionary and check whether we can make that word from grid or not.

## Optimizations

* Using Trie Data Structure to optimize the lookup time

## Prerequisites

* C++14 or higher
* CMake minimum required version 3.22

## Setup

1. Clone the repository

```git clone https://github.com/nisalpadukka/Boggle.git```

2. Create build directory

```cd Boggle && mkdir build && cd build```

3. Build

```cmake .. && make```


## Run

1. Execute the program

```cd PROJECT_ROOT_DIRECTORY/build/boggle_ex/src && ./Boggle_ex```

2. Update the words in Dictionary file at

```PROJECT_ROOT_DIRECTORY/inputs/Dictionary.txt```

Note: Contains of the 16 dices can be updated using the Dice.txt file at PROJECT_ROOT_DIRECTORY/inputs/Dictionary.txt.


## Test

Execute Test build

```cd PROJECT_ROOT_DIRECTORY/build/boggle_lib/test && ./Boggle_test```


