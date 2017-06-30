In this exercise, you will implement one function:
1. A recursive function to convert a long int into a string

# Learning Goals 

The main learning goal is:
1. How to write a recursive function

# Getting Started 

The pa05 folder contains six files:
1. utility.h: this is the file that you should include in pa05.c and 
answer05.c.  It contains functions for me to count the number of recursive 
calls you have made in your recursive function.   That way, We can check 
whether the number of recursion calls you have made is reasonable.
2. utility.o: this is the object code that We have compiled.  It contains the
functions declared in utility.h.  However, these functions are blackboxes 
because you have no access to the source code.
3. answer05.h:  this is the file that declares the function that would be 
called in pa05.c.
4. answer05.c:  this is the file that you have to turn in.  It contains
a complete function, which is declared in answer05.h, and you have to 
complete the recursive function, which is called by the complete function.
5. pa05.c:  this is a file to get you started on testing your implementation.
6. Makefile: a file that allows you to compile the source codes into 
executable using the "make" command.

You will be writing code in the answer05.c file. You may also write code 
in the pa05.c file for the main function as well as function to test 
the functions written in the answer05.c file.

### Submitting Your Exercise 

You submit only one file:
1. `answer05.c` (10 points)

### Compiling Your Program

To compile your program, use the following command:

> make

Take a look at the Makefile.  A line starting with '#' means a comment.
"CC" and "CFLAGS" define the compiler and the flags used by the compiler,
respectively.  The label "pa05" define the rule to build the executable pa05.
Immediately after the labels, the object codes that pa05 is dependent on are
listed:  pa05.o and answer05.o (utility.o is also needed, but this is not 
supposed to be changed by you, so, it is not listed).  The first build
rule is the default rule to follow when "make" is called without an 
argument.  If you type "make clean", the rule for "clean" will be executed,
which removes all object codes and the executable.  The last
build rule "%.o" compiles a .c file into a .o file.
Note that the -c flag is used to generate object code.

### Running Your Program 

To run your program, you type in, for example, the following command 

> ./pa05 

The current program will test the conversion using a few numbers.
For each number, it will perform the conversion based on bases from
2 to 37 (of which 37 is an invalid base).

## Long int to string conversion -- Recursion 

This exercise requires you to perform the conversion of a long int 
to a string for any base greater than 1 but less than 37.  
E.g. number 1234 would be converted into string "1234" in base 10.
pa05.c tries to perform such conversions on selected numbers in bases 2 to 37.
If your `function rec_magnitude_long_int_to_string` is correct, you should see "successful conversion" statement for every base.

File `ideadOutput` contains output of the progarm with correct recursive call. 

In the function `long_int_to_string` (which already defined for you), there is a call to the recursive function

```
void rec_magnitude_long_int_to_string(long int number, int base,
                                      char *intstring, int *stringlen);
```                                     

The assumption that we made here is that we are converting the number,
and putting the symbols of that particular base into `intstring`, and `*stringlen` contains
the number of symbols in intstring.  Note that *stringlen does not include
the '\0' character.  In other words, before the call to the function,
*stringlen should contain the current number of symbols in intstring, and
if the function puts additional symbols into intstring, *stringlen should
be updated accordingly.

If a negative number is given, a '-' character is put in intstring, and 
the first call to the recursive function would have *stringlen set to 1.
Otherwise, the first call to the recursive function would have *stringlen set
to 0. `(This has already been taken care in function long_int_to_string for you).`

At the end of the call to the recursive function inside function `long_int_to_string`, a ret_string is allocated
with the right amount of memory (*stringlen + 1, i.e., the number of symbols 
+ 1 to account for '\0' character), and the symbols in intstring is copied 
over, and ret_string is terminated with '\0'.  

Your main duty is to define the function

void rec_magnitude_long_int_to_string(long int number, int base,
                                      char *intstring, int *stringlen);

However, if you want to declare the recursive function differently, you
are allowed to do so.  However, you would have to make appropriate changes
to long_int_to_string.  Since you have to submit answer05.c, you are allowed
to make changes to the definition of long_int_to_string.  However, the
declaration of long_int_to_string is fixed as the declaration is in 
answer05.h, which you are not submitting.

## rec_magnitude_long_int_to_string 

This function recursively converts the magnitude of a given number into
a string, depending on the given base.   The given number can be negative.
However, this recursive is not responsible for putting the negative sign into
intstring.  It is only responsible for the magnitude of the given number.

How should you perform the conversion?  If We give you a number
1274, and you are supposed it to string for base 10,
what would you get if you perform 1274%10?  You get 4.  Of course,
you have to convert the number 4 to character '4'.  
How about 1274/10 (integer division)?  You get 127.  Now, can you
apply the same thing to 127 to get the rest of the string.  The ordering
of the symbols in intstring is important if you want to get the conversion 
right.

Again, you have the flexibility to redefine the long_int_to_string function
to match the order in which you store symbols into intstring in the
recursive function.  In the definition given to you currently, We assume that
the symbols are put in intstring in the correct order.

## How to use functions in utility.h 

The functions in utility.h allows us to know how many recursion calls
have been made.  This is how you should use the utility functions.
Before you call the long_int_to_string function, you have to call

Initiailize_counter();

so that we can initialize the appropriate counters (see pa05.c). 

At the beginning of the recursive function, you have to call 

Increment_counter(&number);

where number is the first parameter of the recursive function
(see answer05.c). 

Before you return from the recursive function, you have to call

Decrement_counter();

Note that Decrement_counter has to be call after all recursive calls within
the recursive function have been made (see answer05.c).

After the long_int_to_string function is successfully executed,  we have called  

Counter_statistics();

to get the statistics, which should include the total number of
recursive calls, the deepest number of recursive calls, and the frame size.
Note the frame size is 0 if the deepest number of recursive calls is
0 or 1 (see pa05.c). 

Here is an example using the Fibonacci function.
Assume that the main function will call Fibonacci, the main function
will call Initialize_counter() before the call, and Counter_statistics()
after the call.

A typical Fibonacci function looks like this:

int Fibonacci(int n) {
   if (n == 0) { return 0; }
   if (n == 1) { return 1; }
   return Fibonacci(n-1) + Fibonacci(n-2);
}

We would have to modify Fibonacci to use the two functions
Increment_counter and Decrement_counter as follows:

```
int Fibonacci(int n) {
  Increment_counter(&n);
  if (n == 0) { Decrement_counter(); return 0; }
  if (n == 1) { Decrement_counter(); return 1; }
  int temp1 = Fibonacci(n-1);
  int temp2 = Fibonacci(n-2);
  Decrement_counter();
  return temp1 + temp2; 
}
```

Increment_counter has to be called at the beginning of function.
Decrement_counter has to be called before we exit from the function
and after all recursive calls within the function.  

Note that the functions in utility.h are written with the
assumption that the recursion occurs within the same function.
In other words, function A calls function A directly.  In many
real examples, the recursion can be more complicated, with 
function A calling function B, which in turns calls function A.
We expect you to write a recursive function which calls itself
(the simple case).

# Grading 

The 10 points are distributed as follows:
1. correctness of your conversion: 5 points.
2. correctness of the number of recursions used: 5 points.
We can tolerate a +/- 1 difference in the number of recursions used.
