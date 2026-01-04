*This project has been created as part of the 42 curriculum by vbleskin.*

# Push_swap

## Description

**Push_swap** is a 42 school algorithm project. The goal is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, one must manipulate various types of algorithms and choose the most appropriate solution (optimized data sorting) for optimized data sorting.

The project involves two stacks:
- **Stack A**: Contains a random amount of non-duplicated negative and/or positive numbers.
- **Stack B**: Initially empty.

The goal is to sort the numbers in **Stack A** in ascending order using specific operations (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).

## Instructions

### Compilation

The project uses a `Makefile` to compile the source files.

* **Compile the project:**
    `make`
    -> This generates the `push_swap` executable.

* **Compile the bonus (Checker):**
    `make bonus`
    -> This generates the `checker` executable.

* **Clean object files:**
    `make clean`

* **Full clean (objects + executables):**
    `make fclean`

### Execution

To run the sorting program:
`./push_swap 2 1 3 6 5 8`
    -> The program will output a list of operations to sort the stack.

To run the program with a randomly sorted 500 numbers list:
`ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $ARG`
    -> add `... | wc -l` to count operations printed.

* **Verification (Bonus)**

To check if the list of operations actually sorts the stack, pipe the output into the checker program:
`ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG`
    -> If the sorting is correct, it displays OK.
    -> If not, it displays KO.
    -> In case of error, it displays Error.

## The Algorithm: "The Turk"

This project implements the Turk Algorithm. It is a highly efficient algorithm for this specific problem, usually performing better than Radix or Quicksort for N=100 and N=500.

Key steps:
    - Push to B: Move almost all nodes from A to B, leaving only 3 nodes in A. At each step, we calculate the "cheapest" node to move (the one requiring the fewest operations to reach its correct position in B).
    - Sort 3: Sort the remaining 3 nodes in A.
    - Push back to A: Move nodes back from B to A. For each node, we find its correct target position in A to keep the stack sorted.
    - Final Rotation: Rotate stack A to bring the smallest number to the top.

## Resources & AI Usage

* **References**

    - Push_swap Tutorial: A guide to the Turk Algorithm. https://medium.com/@ayogun/push-swap-c1f5d2d41e97
    - Time Complexity: Understanding Big O notation for sorting algorithms.
    - Stack Data Structure: Documentation on LIFO structures.

* **AI Usage**

As part of the learning process, Artificial Intelligence (specifically ChatGPT/Gemini) was used for the following tasks:
    - Debugging & Logic:
        -> Helping to understand the "Dirty Flag" issue where cost calculations were not updated correctly before moving nodes.
        -> Identifying the logic error in rr vs rrr optimization (the "Dyslexia" bug).
        -> Explaining Valgrind errors (Use After Free) and suggesting safer memory freeing strategies.

    - Makefile Optimization:
        -> Assisting in structuring the Makefile to handle the Bonus part without relinking, ensuring a clean compilation process.

    - Understanding the Subject:
        -> Clarifying the behavior of specific operations (like rra vs ra) and edge cases (MAX_INT/MIN_INT overflows).

*Note: All code was manually implemented, reviewed, and tested. AI served as a "pair programmer" for explanation and debugging.*