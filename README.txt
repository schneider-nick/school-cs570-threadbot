/*
*Name: Nick Schneider, Brian Dobransky
*Username: cssc1093, cssc1094
*Class: CS570, Summer 2017
*Assignment: Assignment #1, bots
*Due: 6-5-2017
*Instructor: Prof. Leonard
*File: README.txt
*/


usage: ./bots


files:
bots.cpp
bots.h
main.cpp
makefile
README.txt

compile instructions:
"make" : this will compile all source and create executable "bots"

operating instructions:
./bots

significant design decisions:

	A signifacant design decision was to use two seperate funtions for the threads; an
 odd and an even function. This elimnated the passing of flags to the funtion which simplified the program.


-Rules:
When your program starts, it shall do the following:
    1. Create a file, named QUOTE.txt, in the current directory (cwd).
    2. Have your running process write it’s pid (Process ID) followed by a Carriage Return and
    Newline in to the file.
    3. Close the file QUOTE.txt
    4. Create a semaphore named FLAG which the threads will use to manage access to the file
    QUOTE.txt.
    5. Create 7 threads. Use the POSIX version of threads (i.e., pthread_create())
    6. Block/wait for all seven threads to complete their work.
    7. Once all threads are done, destroy the semaphore, then exit gracefully, printing a friendly
    message to the console
Each thread shall perform the following (note, each thread is running concurrently):
    1. Periodically (even numbered threads - once every two seconds, odd numbered threads – once
    every 3 seconds) get the semaphore FLAG; once the thread has FLAG, it will proceed to do the
    following:
        1. Open the file QUOTE.txt and write the thread’s tid (thread id) followed by “The Quote”
        (followed by a Carriage Return and Newline)
        2. Write to the console (print to stdout) “Thread <thread id> is running” followed by a
        newline
        3. Close the file QUOTE.txt
        4. Release the semaphore FLAG
    2. Repeat the above 7 times.
    3. exit 


known bugs:
no known bugs

lessons learned:
Semaphores-
We learned about semaphores and how they protect the critical area.
Also how semaphores is used for signaling, if a process is waiting for a signal,
it is suspened until that process signal is sent.  Semaphores processes avoid 
race conditions by utilizing wait and signal operations that cannot be interrupted.
Threads-
We learned about how threads resides within the context of a process,
those processes may have multiple threads and share process resources through
the U_Area.
