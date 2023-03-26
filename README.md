# monty
The goal of this project is to create an interpreter for Monty ByteCodes files.


## The Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument

	james@ubuntu:~/monty$ cat -e bytecodes/000.m
	push 0$
	push 1$
	push 2$
	  push 3$
					   pall    $
	push 4$
		push 5    $
		  push    6        $
	pall$
	james@ubuntu:~/monty$

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

	james@ubuntu:~/monty$ cat -e bytecodes/001.m
	push 0 Push 0 onto the stack$
	push 1 Push 1 onto the stack$
	$
	push 2$
	  push 3$
					   pall    $
	$
	$
							   $
	push 4$
	$
		push 5    $
		  push    6        $
	$
	pall This is the end of our program. Monty is awesome!$
	james@ubuntu:~/monty$


## The monty program
* Usage: `monty file`
	- where `file` is the path to the file containing Monty byte code
* The monty program runs the bytecodes line by line and stop if either:
	- it executed properly every line of the file
	- it finds an error in the file
	- an error occured
* Lines starting with `#` are treated as comments.

### Allowed Instructions (opcodes)
1. `push <int>` - pushes an element to the stack/queue.
	- where \<int\> is an integer
2. `pall` - prints all the values on the stack/queue, starting from the top/first.
3. `pint` - prints the value at the top of the stack/queue.
4. `pop` - removes the top/first element of the stack/queue.
5. `swap` - swaps the top two elements of the stack/queue.
6. `add` - adds the top two elements of the stack/queue.
	- The result is stored in the second top element and the top/first element is removed.
	- The stack remains one element shorter.
7. `sub` - subtracts the top element of the stack/queue from the second top element of the stack/queue.
	- The result is stored in the second top element and the top/first element is removed.
	- The stack remains one element shorter.
8. `div` - divides the second top element of stack/queue by the top element.
	- The result is stored in the second top element and the top/first element is removed.
	- The stack remains one element shorter.
9. `mul` - multiplies the second top element of the stack/queue with the top element.
	- The result is stored in the second top element and the top/first element is removed.
	- The stack remains one element shorter.
10. `mod` - computes the rest of the division of the second top element of the stack/queue by the top element.
	- The result is stored in the second top element and the top/first element is removed.
	- The stack remains one element shorter.
11. `pchar` - prints the char at the top of the stack/queue.
12. `pstr` - prints the string starting at the top of the stack (or beginning of queue).
	- The integer stored in each element is treated as the ascii value of the character to be printed.
	- The string stops when either:
		+ the stack/queue is over.
		+ the value of the element is 0.
		+ the value of the element is not in the ascii table.
13. `rotl` - rotates the stack/queue to the top.
	- The top element of the stack/queue becomes the last one.
	- The second top element becomes the first one.
14. `rotr` - rotates the stack to the bottom.
	- The last element of the stack/queue becomes the top element.
15. `stack` - sets the format of the data to stack (LIFO).
	- This is the default behaviour of the program.
16. `queue` - sets the format of the data to a queue (FIFO).
17. `nop` - This opcode doesn't do anything. It's a blank opcode.



## Usage
The code should be compiled this way:

	$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

**NOTE:**
* All outputs are printed on `stdout`
* All error messages are printed on `stderr`


Create a file with instructions listed line by line and save it with a `.m` extension

Run the compiled program and pass the file. For example:

	./monty example.m

## Examples
	james@ubuntu:~/monty$ cat bytecodes/35.m 
	push 1
	push 2
	push 3
	push 4
	push 5
	push 6
	push 7
	push 8
	push 9
	push 0
	pall
	rotl
	pall
	james@ubuntu:~/monty$ ./monty bytecodes/35.m 
	0
	9
	8
	7
	6
	5
	4
	3
	2
	1
	9
	8
	7
	6
	5
	4
	3
	2
	1
	0
	james@ubuntu:~/monty$

=============================================================================

	james@ubuntu:~/monty$ cat bytecodes/47.m
	queue
	push 1
	push 2
	push 3
	pall
	stack
	push 4
	push 5
	push 6
	pall
	add
	pall
	queue
	push 11111
	add
	pall
	james@ubuntu:~/monty$ ./monty bytecodes/47.m
	1
	2
	3
	6
	5
	4
	1
	2
	3
	11
	4
	1
	2
	3
	15
	1
	2
	3
	11111
	james@ubuntu:~/monty$
