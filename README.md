# Circuit Simulator

Last modified: 11 - June - 2020

A transient analysis program written in C++ that reads in a SPICE netlist and uses concepts of Modified Nodal Analysis (MNA) to solve for unknown node voltages per time cycle.


## Table of content
- [Circuit Simulator](#circuit-simulator)
  - [Table of content](#table-of-content)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Instructions on how to run the program](#instructions-on-how-to-run-the-program)
  - [Other scripts](#other-scripts)
  - [Documentation](#documentation)
    - [Project Report](#project-report)
    - [Research Documents](#research-documents)
    - [Meeting Minutes](#meeting-minutes)
  - [Acknowledgments](#acknowledgments)

## Getting Started

The following sections contains information that will allow the user to utilise the program.

For more detailed information on modifying the program or testing it, please refer to the *Program Specification* document found under the **'documents'** folder.  


### Prerequisites

Instructions listed under this section assumes that user has access to a UNIX Shell environment (Linux operating system).


### Instructions on how to run the program

Before running the program, ensure the input file is located in the same folder as 
this README file. 

In the same directory, there will be a file called 'main.sh'. 

To run the file, open the linux terminal by right clicking the and selecting 'Open in Terminal' from the menu.

Type the following instructions into the terminal.

```
./main.sh
```

Follow the instructions displayed on the terminal.

The program will produce a file called 'output.csv' which can then be plotted.


## Other scripts

A script called 'compile.sh' will recompile the program. Do not run the script unless 
a backup of the program is made. 

## Documentation

All documents are found within the **documents** folder. 

A list and its brief descriptions are given here.
### Project Report
The submitted document that summarises the content of all the documents, highlighting the development process of the software and the reflections of its participants. 

### Research Documents
Several documents that is created when researching aspects of the project. 

Each document details the theory and the design processes of a specific module that combine to form the final software package.

### Meeting Minutes
This folder contains all the minutes recorded during each project meeting. 

## Acknowledgments

* Kexing Ying [1st Year UG Department of Mathematics]
  * Help in understanding basic Network Graph theory.
  * Ensuring correct mathematic terminology is used.


