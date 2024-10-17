# TextTreeSort
This text sorter is a C program that reads a block of text from the keyboard, line by line, sorts the text in alphabetical order (case insensitive), and displays the sorted result. This project demonstrates the use of binary trees to organize and sort text input efficiently.

## Overview
The program works by:
1. Reading each line of text input from the user until a blank line is entered.
2. Using a binary tree (bTree) structure to store each line, allowing efficient insertion and sorting.
3. Outputting the sorted lines in alphabetical order.

This project includes the following source files:
- `getline.c`: Handles input line-by-line.
- `sortDemo.c`: Provides the main structure and logic for reading and displaying sorted text.
- `bTree.c` – Implements the binary tree structure used to sort the text.

![textSorter](https://user-images.githubusercontent.com/21160813/186041346-05e8a1cc-0808-42f1-bfb9-eed5aa01f414.jpg)  <br>
*(Example of program execution and sorted output)*

---

## How to Compile and Run
1. **Compile the Program**:
   ```bash
   gcc -o textSorter sortDemo.c getline.c bTree.c
   ```

2. **Run the Program**:
   ```bash
   ./textSorter
   ```

3. **Enter Text**:
   - Type each line of text and press Enter.
   - Input a blank line to end the input process.

4. **View Output**:
   - The program will output the text in sorted order.
