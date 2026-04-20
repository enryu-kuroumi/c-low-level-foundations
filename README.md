# c-low-level-foundations

A collection of laboratory projects focused on low-level programming, memory management, and Unix system calls. This repository demonstrates proficiency in C, specifically regarding pointer arithmetic, dynamic memory allocation, and file descriptor manipulation.

---

## Key Concepts Covered

* **Memory Management:** Implementing dynamic allocation using `malloc` and ensuring proper cleanup with `free`.
* **Pointer Manipulation:** Handling multi-dimensional arrays through pointer-to-pointer logic and offset calculations.
* **Algorithms:** Implementation of classic sorting and searching algorithms (e.g., Selection Sort).
* **Systems Programming:** Utilizing POSIX system calls for low-level file I/O and file system manipulation.
* **Concurrency:** Synchronizing threads using mutexes and condition variables.

---

## Project Structure

### 1. Algorithms and Data Handling
* **selection_sort.c:** Implements the Selection Sort algorithm for floating-point arrays. Includes helper functions for swapping and range searching.
* **array_min_element.c:** A utility script to identify the minimum value in a dataset using iterative comparison.

### 2. Memory and Matrix Operations
* **matrix_pointer_analysis.c:** Explores the memory layout of 2D arrays. Visualizes how data is stored in the stack by printing memory addresses.
* **dynamic_matrix_copy.c:** Advanced memory handling by flattening a 2D array into a 1D heap-allocated buffer and reconstructing it using an array of pointers.

### 3. Unix Systems Programming
* **unix_file_remover.c:** A utility that removes the first line of a text file using low-level Unix system calls:
    * `lseek`: For precise file pointer positioning.
    * `read`/`write`: For buffered data shifting.
    * `ftruncate`: To physically resize the file on the disk.

### 4. Parallel Programming (Multi-Semaphore)
* **msem (Weighted Semaphore):** A custom library that extends standard semaphore logic. It allows threads to wait for and consume **n** resource units atomically.
    * `sem.c` / `sem.h`: Core implementation using `pthread_mutex` and `pthread_cond`.
    * **Key API:** `sem_wait(s, n)`, `sem_post(s, n)`, `sem_init(s, val)`.
    * **Use Case:** Unlike standard POSIX semaphores, msem allows a thread to wait for n units at once, preventing partial resource acquisition and deadlocks in specific scenarios. Preventing race conditions and managing complex resource allocation in multi-threaded apps.

---

## Compilation and Usage

### General Modules
To compile any standard module, use:
```bash
gcc -Wall -Wextra -o output_name source_file.c
