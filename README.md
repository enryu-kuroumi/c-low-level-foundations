# c-low-level-foundations
A collection of laboratory projects focused on low-level programming, memory management, and Unix system calls. This repository demonstrates proficiency in C, specifically regarding pointer arithmetic, dynamic memory allocation, and file descriptor manipulation.

    Memory Management: Implementing dynamic allocation using malloc and ensuring proper cleanup with free.

    Pointer Manipulation: Handling multi-dimensional arrays through pointer-to-pointer logic and offset calculations.

    Algorithms: Implementation of classic sorting and searching algorithms (e.g., Selection Sort).

    Systems Programming: Utilizing POSIX system calls for low-level file I/O and file system manipulation.
Project Structure
1. Algorithms and Data Handling
    selection_sort.c: Implements the Selection Sort algorithm for floating-point arrays. It includes helper functions for element swapping and finding the minimum index within a specific range.
    array_min_element.c: A utility script to identify the minimum value in a dataset using iterative comparison.
2. Memory and Matrix Operations
    matrix_pointer_analysis.c: Explores the memory layout of 2D arrays. It visualizes how data is stored in the stack by printing the memory addresses of each array element.
    dynamic_matrix_copy.c: Demonstrates advanced memory handling by flattening a 2D array into a 1D heap-allocated buffer and reconstructing it using an array of pointers.
3. Unix Systems Programming

        unix_file_remover.c: A high-performance utility that removes the first line of a text file. It utilizes low-level Unix system calls:

        lseek: For precise file pointer positioning.

        read/write: For buffered data shifting.

        ftruncate: To physically resize the file on the disk after data shifting.
To compile any of the modules, use the following command structure:
        ```gcc -o output_name source_file.c```  
Execution (Example)   
        ```./unix_file_remover data.txt```  
Simple all in 1 command (example):
        ```gcc -Wall -Wextra -o output_name source_file.c && ./source_file.c```
