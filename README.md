# MUSIC-8903-2016
Repo for the class Audio Software Engineering Spring 2016

1. Design a class interface based on the template MyProject.h [20] Use parameter units that are understandable by the user, e.g., seconds instead of samples. Properly document all functions of the class interface. Consider the following questions: What parameters can be adjusted during processing? When (and by whom) is the maximum allowed delay set? What parameters can be known during instantiation? How/Where do you set them? Will your interface work for all samplerates and all channel configurations? How can the user access both types (see 2. + 3. below) from one interface? Is your process function inplace or not? Document your thoughts on the design, solutions, and answers to these questions.
2. Implement FIR comb filter (DAFX: fircomb.m) [15]
3. Implement IIR comb filter (DAFX: iircomb.m)  [15]
4. Implement main command line function  [12] The command line application instantiates your class with the correct parameters, read the parameters from the command line (file name, effect-parameters), reads and processes audio data in blocks and writes the result to an output file.
5. verify functionality for 2 different input audio files by comparison with matlab   [08]
6. write the following test functions to ensure functionality [30]
    1. zero output if input frequeny matches feedforward (FIR)                                         
    2. magnitude increase/decrease if input frequency matches feedback (IIR)        
    3. varying input block size (FIR & IIR)                                                                              
    4. zero input signal (FIR & IIR)                                                                                         
    5. additional test to verify correct functionality    
