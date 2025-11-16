# Foundational C Programs
### Six Standalone C Programs Showcasing Low-Level and Systems-Oriented Skills

This folder contains my implementations of six standalone C programs that highlight core systems concepts: character-level string processing, command-line tools, dynamic memory management, linked data structures, matrix math, and binary search trees.
Each program is independent, written in C, and built with its own Makefile.
This collection demonstrates foundational systems-programming skills including pointer manipulation, memory management, data structures, and structured problem solving in C.

---

# Program Summaries

## 1. rot13 — Character-Level String Cipher
A clean implementation of the classic **ROT-13** transformation.

### Highlights
- Fully character-level encoding
- Preserves punctuation and non-alphabetic chars
- Demonstrates pointer iteration and conditional logic

### Example
```
$ ./rot13 Hello
Uryyb
```

---

## 2. sorta — Lexicographical Argument Sorting
Sorts any number of command-line arguments lexicographically and prints them line-by-line.

### Highlights
- Uses `strcmp()` for ASCII ordering
- No normalization or preprocessing
- Emphasizes raw string handling in C

### ➤ Example
```
$ ./sorta foo bar baz
bar
baz
foo
```

---

## 3. sudoku — Grid Parsing & Logical Validation
Parses a Sudoku grid from a text file and determines whether the grid is valid or solvable.

### Capabilities
- Reads structured 9×9 numeric grids
- Validates rows, columns, and 3×3 regions
- Detects solvability when exactly one value is unknown

---

## 4. list — Sorted Linked List Interpreter
Maintains a **sorted singly linked list** and responds to insertion/deletion commands from stdin.

### Commands
| Command | Meaning |
|--------|---------|
| `i n` | Insert integer `n` |
| `d n` | Delete integer `n` |

### Behavior
- Always keeps the list sorted
- Prints list length + elements after each operation
- All nodes allocated/freed manually

---

## 5. mexp — Matrix Exponentiation
Computes **Mⁿ** where `M` is a dynamically allocated square matrix and `n` is a non-negative exponent.

### Highlights
- Dynamic 2D array allocation
- Matrix multiplication logic
- Handles exponent 0 (identity matrix)

---

## 6. bst — Binary Search Tree Interpreter
Implements a dynamic **binary search tree** with insert, search, print, and delete.

### Commands
| Command | Meaning |
|--------|---------|
| `i n` | Insert value |
| `s n` | Search for value |
| `d n` | Delete value |
| `p`   | Print tree |

### Printing Format
```
((1)2((3(4))5(6)))
```

### Deletion Logic
- Leaf → remove
- One child → replace node with child
- Two children → replace with max of left subtree

---

# Building the Programs
Navigate into any program folder and run:
```
make
./program_name
```

Clean with:
```
make clean
```
