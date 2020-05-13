# Circuit Simulator

A C++ software package that performs a transient simulation of a circuit
by applying concepts of Modified Nodal Analysis (MNA) to solve for the unknown voltages at each node per time cycle.

Input file describing the circuit follows the format of SPICE netlists. For more information detailing the format of SPICE netlists, please see Project Report documentation.

## Table of content
- [Circuit Simulator](#circuit-simulator)
  - [Table of content](#table-of-content)
  - [Link to Github repository](#link-to-github-repository)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Installing](#installing)
  - [Test scripts](#test-scripts)
    - [Data_struct test](#datastruct-test)
  - [Documentation](#documentation)
    - [Project Report](#project-report)
    - [Research Documents](#research-documents)
    - [Project Minutes](#project-minutes)
  - [Scope of functionality](#scope-of-functionality)
  - [Acknowledgments](#acknowledgments)
## Link to Github repository

Project repository: https://github.com/xw2519/ELEC40006.git

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them

```
Give examples
```

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

### Data_struct test

*Data_struct_test.sh* compiles *Parser.cpp* with *Data_struct.cpp* into a file called *Data_struct* before running it with the input textfile *Data_struct_input.txt*. 

This test shows the functionality of the Parser module, testing the functionality of its support functions such as *tokeniser* and *converter*.

```
./Data_struct_test.sh
```

## Documentation

Several documents have been created during the development of this project. 
All documents are found in the **Documentation** folder. 

A brief list and its description is given here.
### Project Report
The submitted document that summarises the content of all the documents, highlighting the development process of the software and the reflections of its participants. 

For more in-depth information on any of the content covered in the Project Report, please refer to the respective Research Documents found under the **Research** folder.

### Research Documents
Several documents that is created when researching aspects of the project. 

Each document details the theory and the design processes of a specific module that combine to form the final software package.

### Project Minutes
This folder contains all the minutes recorded during each project meeting. 

Each document is titled by the date of the meeting in the format DDMMYYYY.


## Scope of functionality


## Acknowledgments

* Kexing Ying [Department of Mathematics]