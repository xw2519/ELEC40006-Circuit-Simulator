# Change Log
Last update: Please see below for date of last update.

Date started: 7 May 2020
Language: C++

Authors: 
- Adam Rehman 
- Brandon Cann, 
- Xin Wang

## Updates or changes
### 5 May 2020
- Project repo established.
- Research into Circuit Simulators begun.

### 7 May 2020
- Tech Specifications document published.

### 9 May 2020
- First version of Project Management Guideline document published.

### 12 May 2020
- v1.0 Parser module implemented.
  - Features:
    - R, C and L element recognised but C and L not yet supported.
    - Node numbering relies on input to start from 1.
    - Ground node needs to be inputted in form: N0
  - Still to do:
    - Automatic node ID assignment.
    - Recognise ground node as 0 instead of N0.
    - Recognise comments denoted by '*' char

### 14 May 2020
- v1.0 Analysis module implemented.
  - Features:
    - Only R and independent sources supported.
    - DC analysis supported for now.
  - Still to do:
    - Dependent sources support.
    - C and L elements support.

### 15 May 2020
- Parser module data structure modified to support SINE voltage sources.
- Minor code optimisation.

### 16 May 2020
- Caught a bug in Analysis module not calculating non-grounded voltage source.
- Research into v2.0 begun.
