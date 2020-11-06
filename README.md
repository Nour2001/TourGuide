# TourGuide
To see which city is the best for travelling! 
In this project, I designed 2 classes: Node class and Tree class. 
The Node class is used to create nodes that are going to be the bases for the Tree class. 
These nodes hold all of the attributes of a city such as name of city, population, cost of living and net salary. 
The Tree class utilizes the Node class to build a quad-tree that stores attributes related to cities based on their coordinates (longitude and latitude). 
Also, in this class, each node has access to its children in each of the four directions (NE, NW, SW, SE). 
These two classes are related to each other since each node in the Tree class is created from the Node class.
