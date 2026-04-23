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

check-leaks: all
	@echo "Line 1\nLine 2" > test_data.txt
	
	valgrind --leak-check=full --error-exitcode=1 ./dynamic_copy
	valgrind --leak-check=full --error-exitcode=1 ./matrix_ops
	valgrind --leak-check=full --error-exitcode=1 ./bank_with
	valgrind --leak-check=full --error-exitcode=1 ./bank_without
	valgrind --leak-check=full --error-exitcode=1 ./file_remover test_data.txt
	
	@rm -f test_data.txt
	@echo "All memory checks passed"

clean:
	rm -f $(TARGETS) test_data.txt
