# Circuit Simulator

Last modified: 11 - June - 2020

A transient analysis program written in C++ that reads in a SPICE netlist and uses concepts of Modified Nodal Analysis (MNA) to solve for unknown node voltages per time cycle.


## Table of content
- [Circuit Simulator](#circuit-simulator)
  - [Table of content](#table-of-content)
  - [Link to Github repository](#link-to-github-repository)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Installing](#installing)
  - [Test scripts](#test-scripts)
    - [Data_struct test (Modification required)](#data_struct-test-modification-required)
  - [Documentation](#documentation)
    - [Project Report](#project-report)
    - [Research Documents](#research-documents)
    - [Project Minutes](#project-minutes)
  - [Scope of functionality](#scope-of-functionality)
  - [Acknowledgments](#acknowledgments)
## Link to Github repository

Project repository: https://github.com/xw2519/ELEC40006.git

## Getting Started

The following sections contains information that will allow the user to utilise the program.

For more detailed information on modifying the program or testing it, please refer to the *Program Specification* document found under the **'documents'** folder.  


### Prerequisites

Instructions listed under this section assumes that user has access to a UNIX Shell environment (Linux operating systems).


### Installing

A step by step series of examples that tell you how to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Test scripts

Explain how to run the automated tests for this system

### Data_struct test (Modification required)

*Data_struct_test.sh* compiles *Parser.cpp* with *Data_struct.cpp* into a file called *Data_struct* before running it with the input textfile *Data_struct_input.txt*. 

This test shows the functionality of the Parser module, testing the functionality of its support functions such as *tokeniser* and *converter*.

```
./Data_struct_test.sh
```

## Documentation

All documents are found within the **documents** folder. 

A list and its brief descriptions are given here.
### Project Report
The submitted document that summarises the content of all the documents, highlighting the development process of the software and the reflections of its participants. 

For more in-depth information on any of the content covered in the Project Report, please refer to the respective Research Documents found in the **Research** folder.

### Research Documents
Several documents that is created when researching aspects of the project. 

Each document details the theory and the design processes of a specific module that combine to form the final software package.

### Project Minutes
This folder contains all the minutes recorded during each project meeting. 

Each document is titled by the date of the meeting in the format DDMMYYYY.


## Scope of functionality


## Acknowledgments

* Kexing Ying [1st Year UG Department of Mathematics]
  * Help in understanding basic Network Graph theory.
  * Ensuring correct mathematic terminology is used.


