AppsecSandbox
=============
Welcome.
The Blacklist file contains all of the keywords that will be filtered.
In the sourcecode, there is an explanation on how to go about doing multiplication.
Enjoy!


Restrictions:

1.  multiplication operator is filtered


2. file operations are filtered


3. pretty much anything that has to do with memory management is filtered

Requirements:

Run the following in a terminal window.

The application requires you to compile the files by being in the correct cd.
  ex: g++ sandbox.cpp -o sandy
  -o  creates an executable file called sandy
  
To run the complete sandbox with your program:


The sandbox requires 3 parameters: (programToBeRunfilePath, executableOutputFileName, pathToBlacklist.txtFile)
Suggestion: have all of these files in the same directory.


Command to output: ./(CURRENT outputFILE) (pathtoprogram) (outputfilename) (path to BLACKLIST file)

ex: ./sandy /Users/%USERNAME%/Desktop/fibonacci.cpp fib /Users/%USERNAME%/Desktop/blacklist.txt

