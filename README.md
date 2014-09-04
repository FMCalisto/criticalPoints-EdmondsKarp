#Instituto Superior Técnico




##Analysis and Synthesis Algorithms 


###2013/2014 


###2nd Draft 


####Delivery Deadline: April 23, 2014 




##The Problem 


Security is a major concern in several types of events, particularly those 
involving large groups of people, crowds. Events like soccer games or 
demonstrations require significant logistical work for the security forces involved. 

In this paper we consider a simple model of crowd control.

We consider map of a city, where there are points where people can focus and 
connections between these points. Two points may be connected, at most, one way.

The our concern is to ensure that there is no communication between a set of critical points. 

If communication between all critical points is more likely to be initiated one 
riot, one of these points.

If this happens the disorder will be extended to all other points 
that are directly linked to them, and so on all the points that are 
reachable from the initial point. 

To avoid compromising the security of the entire city security forces can stop 
a number of connections in order to prevent an upheaval is started.

To minimize costs this operation, we want to minimize the number of connections it is necessary to spread.

Thus objective of this project is to model this problem using data structures and 
appropriate algorithms, so that, given a city map and a list of points 
critics, the algorithm calculates the minimum number of connections that is necessary to blacklist.

The aim is that the critical points are not all in communication.

We want that at least one non-empty set of critical points is isolated from the others,
minimizing the number of connections to spread. 

 
##Input

The first line of input contains two integers. The first indicates the number of points n and o
second integer number of links m.

Here are the links, one per line. Each line contains two integers that identify the 
points are connected.

These numbers u and v satisfy the following restrictions: 0? u <v <n. 

Following the lines of the links there is a line containing only a number h, indicating the 
number of problems that follow. All these problems, ie, sets of points should 
be resolved on the graph previously scanned.

H The following lines contains the lists of points critical.

The first number of each line indicates how many k critical points exist in this line, 
with 1? k? n.

The following are the numbers k of critical points. 

All numbers that are on the same line are separated by a blank space. 


##Output 

For each test case should consist of the output line h, each with only one number, 
the minimum number of links to spread to the respective problem. The order of the numbers must 
be given in the input. Each output line must not contain any more characters in addition to the 
digits of the answer and the '\ n'. 



###Examples 

####Input 1

```
4 4 
0 2 
0 3 
1 2 
1 3 
2 
2 1 0 
2 0 2
```

####Output 1

```
2 
2 
2
```


####Input 2 

```
5 5 
0 2 
0 3 
1 2 
1 3 
0 4 
1 
0 1 3 4
```

####Output 2 

```
1
```


####Input 3 

```
6 4 
0 4 
0 5 
1 4 
1 5 
1 
2 1 0
```

####Output 3 

```
2
```



##Implementation

The implementation of the project should be done preferably using programming languages 
C or C ++. Submissions Java language will not be accepted. 
The time required to implement this project is less than 20 hours. 
Submission of Project 
The submission of the project should include a summary report and a file with the source code 
solution. Information on the possible programming languages ​​is available on the website 
the sistemaMooshak. The programming language is identified by the file extension.

For example, a project written in C should be .c extension. After compilation, the program 
resulting should read the standard input and write to standard output. information 
about options and restrictions compilation can be obtained through the 'help' button on the system 
Mooshak. The compilation command should not produce output, otherwise it will be considered 
a compilation error. The report must be submitted in PDF format with no more than 
4 pages, 12pt font, and 3cm margin. The report should include a brief introduction, 
the description of the solution, the theoretical analysis and experimental evaluation of the results. The report 
shall include any references that have been used in the project. reports 
which are not delivered in PDF format will note 0. The source code should be submitted 
Mooshak through the system and the report (in PDF format) should be submitted via the 
Phoenix. The source code is automatically evaluated by Mooshak system. note that 
only the last submission will be considered for evaluation. All Submissions 
earlier will be ignored; this includes the source code and the report. 
Students are encouraged to submit as soon as possible, preliminary solutions to 
the sistemaMooshak and the Phoenix. Note that it is also possible to submit several times in Phoenix 
and that reports will not be accepted after the deadline and no extension of time. 
The Mooshak system indicates the time available for the project is submitted. projects 
must be subjected to Mooshak system; there is no other form of submission 
project. The reports must be submitted in the Phoenix system; there is no other way to 
submission of reports.



##Rating 

The project should be done individually and will be evaluated in two phases. The first 
phase, during submission, each implementation will run a set of tests, which 
represent 80% of the final grade. In the second stage, the report will be evaluated. The note of the report 
contributes 20% of the final grade.



##Automatic evaluation 

The first phase is automatically evaluated with a test set, which are 
executed on a computer with GNU / Linux operating system. It is essential that the code 
source compile without error and respect the standard input and output indicated above. the 
projects that do not meet the specified formats will be penalized and may be graded 0, 
If all tests fail. A reduced set of tests used by Mooshak system 
will be public. Most tests will not be disclosed before submission. However, 
all tests will be available after the deadline for submission of the project. In addition to checking 
the correction of the output produced, the evaluation environment restricts the memory and time 
available execution. Most of the tests runs the diff as follows:

diff output result 

The result file contains the output generated by the executable from the input file. The 
output file contains the expected value. A program when a test passes, and receives 
corresponding value when the diff command does not report any differences. There are 16
tests. Thus, the system reports a value between 0 and 16. 



##Detection of Copies 

The evaluation of project includes a procedure for detection of copies. Submission of a 
project involves a commitment that the work was done exclusively by the student. 
Violation of this commitment or attempt to submit code that was not developed by 
student implies failure in the course, all students involved (INCLUDING 
students who provided the code). Any attempt to cheat, direct or indirect, 
be communicated to the Pedagogical Council of IST, the course coordinator, and will be penalized 
according to the rules approved by the University and published in the "Official Gazette".
