 
1)Name- N.Jithendra Chowdary , BITS ID - 2021H1030032G

2) CONTENTS IN THE DIRECTORY ARE:
    thread.c compmul.c compmul.h README makefile input.txt

    i)thread.c contains the code for the creation of thread which simulates parallel threading and uses multipy function defined in another program.
    ii)compmul.c defines the multiply function of complex numbers which is defined in compmul.h
    iii)compmul.h declares the function multiply which is used to multiply two complex numbers and takes arguments as two complex numbers and return type is struct.
    iv)makefile contains all the compilation part and object creation too.
    v)README contains description about how to do and what to do.
    vi)input.txt contains all the complex numbers which need to be multiplied in the form of "a+ib" .

3) makefile is used to compile my program easily. usage: simply enter "make" command in the terminal containing the folder

4) After opening the terminal

    0) Enter "make" in the terminal then files get compiled and a new object called "result.out" will be created .

    i) Enter ./result.out with one command line argument..
        --> argument passed is textfile name with extension(.txt)

    syntax: ./result.out FILENAME.txt

    ii)  USAGE:  ./result.out input.txt

5)  i)First we the inputs from the text file and then store them in a structure and we create threads and pass it to the function called runner which then multiplies complex numbers using another function called mulitply

    ii)multiply function takes this two parameters and performs multiplication of two complex numbers who return type is structure and parameters passed are also structure variables of complex class. i.e we pass complex number structure to it.

    iii)This operation is done recursively until the final result is obtained and the intermediate elements are equal to 1.

6) There are No warnings and errors in the running program.


7) This programs works very well for all the odd inputs and even inputs if all the inputs are of the form "a+ib".
    SUCCESSFULLY DONE:
        1)Each complex number is stored as a structure with a real and an imaginary integer member in it.
        2) Created [floor (N/2)] number of threads from the main thread. Each thread will compute product of (2*i)th input and (2*i +1)th input where i is the thread number [0 to [floor (N/2)]-1]. The product is stored Successfully in temporary output array in global space.
        3)If N is an even number, the number of threads created for computation is equal to N/2 and the temporary output array elements will be equalto N/2.
        4)If N is an odd number, the number of threads created for computation is equal to [floor (N/2)] and the temporary output array elements will be equal to [ceil (N/2)].
        5)Successfully Printed the intermediate results from main thread after these [floor (N/2)] threads exit and
        6)Successfully Printed the final result from the main thread.
        
8)NOTE:
	1)If you enter a-ib then my programs terminates by saying please enter in the form of a+ib..So please enter in form of "a+ib".
