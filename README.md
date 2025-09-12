This project is part of the 42 School curriculum. The goal is to implement a program that sorts a list of integers using a restricted set of operations on two stacks (A and B). The challenge is to find the most efficient sequence of moves to sort the data.

## Table of Contents
- [About](#about)
- [Project Structure](#project-structure)
- [Functionality](#functionality)
- [Usage](#usage)
- [Compiling](#compiling)
- [License](#license)

## About

`push_swap` is a project that consists of sorting integers received via command line, using only specific operations between two stacks (A and B). The program must calculate and display the smallest possible sequence of commands to perform the sorting.

Allowed operations:
- swap (sa, sb, ss)
- push (pa, pb)
- rotate (ra, rb, rr)
- reverse rotate (rra, rrb, rrr)

This project is a great opportunity to practice algorithms, doubly linked list manipulation, and optimization.

## Project Structure

The project is organized as follows:

```
push_swap/
├── push_swap.c              # Main implementation of push_swap
├── checker.c                # Checker to validate the command sequence
├── ft_deque_handler.c       # Stack (deque) manipulation
├── ft_node_handler.c        # Node manipulation for stacks
├── ft_moves.c               # Implementation of allowed moves
├── ft_push.c                # Push operations between stacks
├── ft_swap.c                # Swap operations
├── ft_rotate.c              # Rotate operations
├── ft_reverse.c             # Reverse rotate operations
├── ft_core.c                # Main algorithm logic
├── ft_cost.c                # Move cost calculation
├── includes/                # Header files
│   ├── push_swap.h
│   ├── ft_deque_handler.h
│   ├── ft_node_handler.h
│   ├── ft_moves.h
│   └── ...
├── libft/                   # Auxiliary library
├── Makefile                 # Build script
├── LICENSE                  # License
└── README.md                # This file
```

## Functionality

The program receives a list of integers as arguments and prints, to standard output, the sequence of commands to sort them using only the allowed operations.

Example workflow:
1. The user provides an unsorted list of numbers.
2. The program calculates the optimal sequence of commands.
3. The commands are displayed line by line.

## Usage

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Ferreira-Jefferson/push_swap
   cd push_swap
   ```

2. **Compile the project:**
   ```bash
   make
   ```

3. **Run the program:**
   ```bash
   ./push_swap 3 2 1 6 5 8
   ```

   Example output:
   ```
   pb
   pb
   sa
   pa
   pa
   ```

4. **Validate the sequence with the checker:**
   ```bash
   ./push_swap 3 2 1 | ./checker 3 2 1
   ```

## Compiling

- To compile the project:
  ```bash
  make
  ```

- To compile with bonus:
  ```bash
  make bonus
  ```

- To clean object files:
  ```bash
  make clean
  ```

- To remove all binaries:
  ```bash
  make fclean
  ```

- To recompile from scratch:
  ```bash
  make re
  ```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

*Project developed as part of the 42*