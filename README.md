<h1>POO1 - Travel Management System</h1>

<h2>Overview</h2>
This project is part of a lab assignment for the POO1 (Programming Oriented Object) course. The project involves developing a travel management system in C++, focusing on object-oriented principles. The system allows users to manage and query travel itineraries composed of simple and composed trips. It features a robust catalog system for storing and retrieving travel routes, and it utilizes dynamic data structures for efficient data handling.

<h2>Features</h2>

- <b>Travel Itinerary Management</b>: Users can create and manage travel itineraries, which can be simple trips or composed of multiple connected trips.
- <b>Catalog System</b>: The system includes a catalog for storing travel itineraries, making it easy to add, remove, and search for specific routes.
- <b>Dynamic Data Structures</b>: Utilizes dynamic arrays for efficient data storage and manipulation.
- <b>Graph Representation</b>: The project includes a graph-based approach to represent and manage connections between different travel points.

<h2>Project Structure</h2>

- <b>Source Code</b>: The main C++ source files for the application.
  - `Trajet.cpp`: Core logic for handling trips.
  - `TrajetSimple.cpp`: Implementation of simple trips.
  - `TrajetCompose.cpp`: Implementation of composed trips (i.e., trips made of multiple connected legs).
  - `Catalogue.cpp`: Manages the catalog of trips.
  - `DirectedGraph.cpp`: Handles the graph structure for travel points.
  - `TableauDynamique.cpp`: Manages dynamic arrays for storing data.

- <b>Headers</b>: Header files defining classes and functions used in the project.
  - `Trajet.h`, `TrajetSimple.h`, `TrajetCompose.h`, `Catalogue.h`, `DirectedGraph.h`, `TableauDynamique.h`

- <b>Makefile</b>: Script for automating the build process.
  - `Makefile`

- <b>Documentation</b>: Includes a report documenting the design and implementation of the project.
  - `COMPTE RENDU.pdf`

<h2>Technologies Used</h2>

- <b>C++</b>: Core programming language used for developing the application.
- <b>Makefile</b>: For automating the build and compilation process.

<h2>Environments Used</h2>

- <b>Windows / Linux / MacOS </b>: The project is developed and tested on these operating systems.
