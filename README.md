# BufferOverrunAttack

# Requirements
Linux/x86 system architecture
gcc hello.c -static -g

This is part of a university assignment that aims to familiarize you with buffer overrun attacks.
A simple program hello.c,bufsize.h and the executable hello is given with a buffer vulnerability. The program reads a name and if the name is equal to Angelos Bilas it assigns you a grade equal to 6, otherwise 3. The goal is :
1.) Make the program crash
2.) Make the programe print your name with grade 6
3.) Make the program print your name with grade 9

createdata3-9 are implemented accordingly for each task.

# createdata3.c
Creates an input that is long enough to fill the buffer Name[44] and
overwrites the return address of readString function, leading the program
to crash.

# createdata6.c
Creates an input that contains my name, and the rest of the Name entries are filled with zeros. I manage to overwrite the i variable so that buffer index points to the return address of the readString function and i overwrite it with
the instruction that assigns 6 to grade.I also overwrite the argument of readString in order to not be destroyed.

# createdata9.c
Creates an input that contains my name, and instruction that assigns 9 to grade. Similarly with createdata6.c, the goal is to overwrite the
return address of readString with the instruction that corresponds to the buffer, specifally at the index that we injected the instructions
so that they will be executed.I also overwrite the argument of readString in order to not be destroyed.
