# DV-C
Modelling Accurate Prolate Jellyfish Movement

Ayse Sena Demir (ayse_demir@brown.edu) and Amber Chevannes (amber_chevannes@gmail.com)

ENGN 2912B Scientific Programming in C++ 12/2018

## Introduction

![Jellyfish Cover Image](https://raw.githubusercontent.com/ENGN2912B-2018/DV-C/master/DV-Cjellycover.jpg)

### - Project Overview
   This project will create a base work for realistic rendering and animating of the movement of a jellyfish model that can be extended or improved utilizing scientific programming techniques in C++. Providing a visual model of animal behavior has potential to improve the development of soft robots. A more physiologically  and environmentally modular model could provide valuable information for creation of soft robots. Our work provides an opportunity for soft robot developers to understand the animal behavior better in visual form and can provide groundwork for better understanding of animal behavior. 
	Game and animation productions has been improving to become more and more realistic as the technology improves both in software computation time and in hardware capabilities. The producers has been looking for opportunities to create realism especially in video game industry to immerse players into games.

### - Goals and Objectives
The goal of this project is to assemble the base work for creating a realistic model of a prolate jellyfish. By combining the work done to model the movement mathematically as well as analyzing video data of a real jellyfish's movement, we are able to lay the ground work for a true realistic model of the jellyfish movement. First extracting the shape of the head of the jellyfish from the video data as well as adding in multiple tenticles for visual accuracy. An observational model of the head contraction and expansion from Diabiri et al., was used to create the baseline animation of the jellyfish movement. The model changes the radius of the head based on a sine function. The model can be further complicated by consulting the video data, as the movement of the jellyfish head is not as simple as the the visual approximation. The final goal of the project is to utilize the data from research partners at Boston Engineering and Dr. Jack Costello's lab to create a physiologically relevant model. By either extracting the shape of individual frames of the jellyfish and morphing the 3D shapes to create an animation.

## Software Architectural Design (as appropriate)
### - Required External Libraries
This project uses Qt, Glew 1.10 and glm and openGL libraries as well as the standard library. The glew library is already included in the source code repository.
### - Functional Block Diagrams
### - Data Flow Diagrams
### - UML Diagrams showing Object Definition/Inheritance
The objective of this project is model accurate jellyfish behavior for various uses in robotics, gaming and animation. The project is user interactive in which user can choose different modes of behavior.

## Interface Descriptions (as appropriate)

### - Graphical Interface
The graphical interface consists of a main window that contains the jellyfish scene. The camera in the scene can be zoomed in and out by middle mouse button wheel. Any mouse button pressed and moved will rotate the scene so the jellyfish can be seen from all angles.
### - Data Visualization
The data consists of the object (.obj) file that was created in blender. The team has written a parser to decode the data that is in the format as a vertex represented as "v xCoord yCoord zCoord", a normal represented as "vn xCoord yCoord zCoord" and a face represented as "f firstVertexNumber//firstVertexNormal secondVertexNumber//secondVertexNormal thirdVertexNumber//thirdVertexNormal". A face represents a triangle on the jellyfish model. This data is parsed by readOBJ file in the jellyfish class and the correct parts are sent to openGL through Vertex Buffer Object (VBO) and Vertex Array Object (VAO) classes so the openGL can draw and animate the shape in the shaders.
### - Communications Protocols
Our program does not deal with the transfer of data between computers, processes or threads so there is not description for communication protocols.
### - Threading and Concurrency
### - Exception Handling
The necessary checks were inserted for errors that can happen in the program. Since the user interaction is limited most errors can happen from portability issues. We have implemented the necessary checks for reading files as well as shader reading, linking and compiling issues.

## Testing and Evaluation

### - Operating system(s) and software compiler/library version(s) tested
### - Description of functional testing to date
Most of the testing was done visually since the project is very visual oriented. During the writing of the software cout statements was used to ensure the data is read correctly along with error handling. The testing is done by comparing visual videos of jellyfish moving with the movement of the jellyfish in the software.
### - Instructions for compiling and running the software
The software can be run on qtCreator easily by opening the .pro file in the repository or can be run with the CMake file in the repository as well.

## Conclusions
### - Major Accomplishments
### - Results of the software development effort
### - Were you successful in meeting all goals and objectives?  What didn't work?  What would take more time?

## Future Work
### - Description of potential future software expansions and software features

## Author Contributions
### - Description of each authors' contributions to software development
Ayse Sena Demir - Ayse has created the GUI for the program, the Blender program, has written the openGL code for VAO, VBO and the openGL commands, the jellyfish class and the data parser, the shaders for the program and the modelling of the jellyfish in xz plane.
