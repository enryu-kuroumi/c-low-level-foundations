CC = gcc
CFLAGS = -Wall -Wextra -pthread

TARGETS = dynamic_copy matrix_ops bank_with bank_without file_remover

all: $(TARGETS)

dynamic_copy: Memory-Management/dynamic_array_copy.c
	$(CC) $(CFLAGS) -o dynamic_copy Memory-Management/dynamic_array_copy.c

matrix_ops: Memory-Management/matrix_operations.c
	$(CC) $(CFLAGS) -o matrix_ops Memory-Management/matrix_operations.c

bank_with: Parallel-programming/bank-balance-WITH-mutex.c
	$(CC) $(CFLAGS) -o bank_with Parallel-programming/bank-balance-WITH-mutex.c

bank_without: Parallel-programming/bank-balance-WITHOUT-mutex.c
	$(CC) $(CFLAGS) -o bank_without Parallel-programming/bank-balance-WITHOUT-mutex.c

file_remover: System-Programming/file_line_remover.c
	$(CC) $(CFLAGS) -o file_remover System-Programming/file_line_remover.c

clean:
	rm -f $(TARGETS)
