*This project has been created as part of the 42 curriculum by oerrami.*
This project has been created as part of the 42 curriculum by oerrami


# push_swap

## Description

**push_swap** is a project from the 42 curriculum written in **C**.  
The goal is to sort a list of integers using **two stacks** and a **limited set of operations**, while producing the **fewest possible instructions**.

The project uses:
- **Stack A**: initially contains the input numbers
- **Stack B**: starts empty and is used as auxiliary storage

Only specific operations are allowed to manipulate the stacks.

---

## Allowed Operations

### Stack A
- **pa (push a)**               : take the top element from stack **B** and push it to stack **A**
- **sa (swap a)**               : swap the first two elements of stack **A**
- **ra (rotate a)**             : shift all elements of stack **A** up by one (first becomes last)
- **rra (reverse rotate a)**    : shift all elements of stack **A** down by one (last becomes first)

### Stack B
- **pb (push b)**               : take the top element from stack **A** and push it to stack **B**
- **sb (swap b)**               : swap the first two elements of stack **B**
- **rb (rotate b)**             : shift all elements of stack **B** up by one
- **rrb (reverse rotate b)**    : shift all elements of stack **B** down by one

### Both Stacks
- **ss**                        : swap the first two elements of both stacks
- **rr**                        : rotate both stacks
- **rrr**                       : reverse rotate both stacks

---

## Instructions

### Compilation

You can compile the project using the following commands:

```bash
make            # compile push_swap
make push_swap  # same as make
make clean      # remove object files (.o)
make fclean     # remove object files and executable
make re         # clean and recompile
make bonus      # compile the checker program

```

### running

To run the program, execute `push_swap` with integer arguments.  
The arguments must be valid integers between **-2147483648** and **2147483647**, and no duplicate values are allowed.  
If the input is invalid, the program prints `Error`.  
If the input is valid, the program outputs a sequence of operations that sorts stack **A**.

Examples:

./push_swap 0+0 1111111111111111
Error

ARG="0+0 1111111111111111111111"; ./push_swap $ARG                                       
Error

ARG=" 3 2 1 "; ./push_swap $ARG
ra
sa

./push_swap 3 2 1
ra
sa

## Resources









