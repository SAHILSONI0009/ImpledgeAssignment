# Longest and Second Longest Compound Word Finder

## Introduction

The "Longest and Second Longest Compound Word Finder" is a C++ program that efficiently identifies the longest and second-longest compound words in a given input file. It leverages the power of a Trie data structure and Breadth-First Search (BFS) for exploring compound words.

## Intution

- **Longest and Second Longest:** The program identifies the longest and second-longest compound words in a given list.

- **Trie Data Structure:** The efficient Trie data structure is used for storing and searching words.

- **BFS Exploration:** A Breadth-First Search (BFS) approach is employed to traverse and discover compound words.

- **Execution Timing:** The program measures and displays the time taken to process the input file.

## Getting Started

## Algorithm

### Trie Initialization:
- Create an empty Trie data structure with a root node.
### Insertion:
- Read each word from the input file and insert it into the Trie.
- For each word, traverse the Trie starting from the root.
- Create new nodes for characters that are not present in the Trie.
- Set the isEndOfWord flag for the last character of each word to indicate the end of a valid word.
### Suffix Search:
- For each word in the input file, explore its suffixes using a breadth-first search (BFS) approach.
- Use a queue (q) to store pairs of original words and their suffixes.
- Initialize q with the original words
### Longest Compound Word Search:
- While the queue is not empty, dequeue a pair containing the original word and its suffix.
- For each pair, find the suffix's valid word endings in the Trie.
- If the suffix has valid word endings, add new pairs to the queue with updated suffixes.
- Track the longest and second-longest compound words found during this process.
### Result Output:- 
- After BFS traversal, the code outputs the longest and second-longest compound words found.
### Performance Measurement:
- Measure and display the time taken to process the input file using the chrono library.

### Prerequisites

Before you can use this program, ensure that you have the following prerequisites in place:

- **C++ Compiler:** You'll need a C++ compiler, such as g++, to build and run the program.

- **Text Editor or IDE:** You can use a text editor or an integrated development environment (IDE) for compiling and running the code.

### Installation

To set up and run the program, follow these steps:

1. **Clone the Repository:** Begin by cloning this GitHub repository to your local machine using the following Git command:

   ```bash
   git clone https://github.com/SAHILSONI0009/ImpledgeAssignment

It records the start time and end time to measure the execution time using the <chrono> library.
Input and Output:

The code reads words from an input file (e.g., "Input_02.txt") and writes the results to an output file (e.g., "output_02.txt").
It prints the longest and second-longest compound words found and the time taken for processing.
