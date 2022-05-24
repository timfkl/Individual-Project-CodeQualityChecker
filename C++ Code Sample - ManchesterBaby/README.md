# Group17_ManchesterBaby
## Part 1 - Hardware Simulator
Your simulation should take as input a text file containing a binary computer program written
in the machine code language of the Baby (essentially 32 lines each of 32 bits of binary data
corresponding to the store). When your simulation is running, it should step through each line
of the input program, simulating the fetch-decode-execute cycle. For example, after fetching
an instruction, it should work out what that instruction is (which operation it corresponds to),
what its operand is, then simulate the execution of that operation by moving data around
your simulated hardware. The seven operations supported by the Baby are given in the
lecture notes.
Your output should be a text based interface (although you can do a GUI if you so wish) which
displays, at each step in the fetch-decode-execute cycle, the state of each part of the Baby
hardware, for example, displaying register values, memory values, and I/O. Hence the main of
your program might simply be an endless loop calling functions such as fetch, decode,
execute and printout).
The representation of the Baby within your code is up to you (e.g. the store could be held as
strings, binaries, integers, vectors) as long as the output is a clear representation of the
original. Similarly, the internal storage of negative numbers is up to you (but see the Number
Systems handout on MyDundee for some guidance).
A sample machine code file is available on MyDundee, and your simulator should (at least)
be able to load and execute this program.
There are many extensions that you could implement if you have sufficient time (these
should be in addition to your standard Baby simulator). For example, you may like to:

  • add an option to extend the hardware of the Baby so that there is more memory space
to work with

  • extend the instruction set to increase the number of instructions that the Baby can
perform

  • extend the memory addressing modes available by adding e.g. immediate addressing -
how will you encode the addressing mode?

  • produce a high-resolution GUI displaying the content of registers and memory during
program execution

## Part 2 - Assembler
Your assembler should take as input a text file containing source code for an assembly
language program, and convert this into the equivalent Baby binary machine code, which it
should write to a text file - this text file should be in the same format as the input file for your
hardware simulator, hence your simulator should be able to run programs which have been
assembled with your assembler. The implementation should include support for a symbol 
table, so that the source code can include variable names (which are converted to memory
locations) and labels (so that program jumps can be coded by referencing the labels, rather
than the actual memory address).
Possible extensions to your assembler include:

• detecting a variety of typical errors in the assembly language code

• adding meaningful error messages to display when errors are found in source code

• reporting progress during the assembly process (generally, an assembler need not be

verbose if no errors are encountered, but for this simulator, verbosity is useful)

• creating more assembly language programs
