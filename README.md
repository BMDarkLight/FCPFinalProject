# FCP Final Project
This Repository is Specified for Fundamentals of Computer Programming Subject's Final Project.


Just Note that this Project is not yet Finalized.

# a Guide to How it works
This is a program which handles a list of students with a list of subject assigned to every one of them.


When you open this program you are faced with a Simple CLI that receives numbers documented in terminal to do the associated action.
Here's a List of Action Provided within this program right now:


1 - List students : 
Which lists every saved student's name, ID and field of studying


2 - Sort and List students by Score : 
Sorts Every Student in a list by their Average Grade


3 - List Subjects of an Student : 
Lists all assigned subjects of an student whom his/her ID is asked by the program.


4 - Register a new Student : 
Asks Name, ID and Field and registers an student in the list using the information taken.


5 - Assign a new Subject : 
Assigns a new Subject to an student which its name, credit and grade is asked.


6 - Edit Students : 
Finds an Student by its ID and then gives the option to edit or remove it.


7 - Edit Subjects : 
Lists Assigned Subjects of an student found by its ID and gives the option to edit or remove  it.


8 - Database Management :
Gives 3 Options to manage saved data. You can insert randomized numbers in range of 0 to 20 as grade for every subject assigned to every student and you can either remove saved data (reset everything) or save the data to a file.


When you close the program by entering anything other than assigned numbers to actions, All of the Data will be saved to a file alongside the program with name of students.dat .


This file contains a vector array of structs which are students and each student carries a vector array of structs which are the subjects assigned. This Data is serialized into binary coding, by passing everything saved in memory address of saved struct into the file as binary and then reading it as binary when necessery.
