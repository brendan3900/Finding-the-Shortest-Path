# Finding-the-Shortest-Path
This program is designed to help users find the shortest path between any two buildings on Northeastern's Campus. Using an undirected graph representing 16 NEU buildings, Dijkstra's algorithm was implemented to achieve this functionality.

The graph and program were designed so that none of the generated shortest paths will guide the user to walk on non-pedestrian areas. The graph represents 16 of Northeastern's buildings, with the edge values (distances between each building) being estimated using Google Maps. The graph has a legend, which says that the black/underlined labels represent the building #'s; these numbers were based off a NEU campus map.



----->Summary of Approach

To begin this program, the necessary libraries and global variables were created/included. The purposes of the global variables were for storing the graph data and for converting the text file data to the corresponding buildings on the map. 

 The ReadMatrix() function was created which opens and reads the graph data from a text file. The data taken from the external text file was entered into a global adjacency matrix.

 The path() function was created, taking an int array and an int variable as parameters. The purpose of this function is to be invoked by other functions to print the desired shortest path; the printing of the correct route is done through recursive calls. 

 The printPath() function was created, taking two int arrays and two int variables as parameters. The purpose of this function is to display the travel directions and path information for the user. This includes stating the inputted start and destination buildings, invoking the path() function to print out the route, and displaying the total distance of the path. 

 The minD() function was created, taking an int array and bool array as parameters. The purpose of this function is to be invoked by other functions in order to find the closest, nonmarked vertex from the current location. 

 The dijkstra() function was created. This function takes the desired start and destination buildings from the user and calculates the shortest path based on the map-graph. However, if an invalid building number is entered, an error message is displayed, and the program will not continue. Multiple arrays were used in this function in order to keep track of the shortest path, shortest distances, and which vertices have already been visited (marked). In order to achieve the overall function, embedded for loops were used—this processes the possible routes based on the closest buildings, updates the path if a new path is shorter, and updates the route distance. Finally, if the user inputted valid building numbers, the printPath() function is called to print the shortest path’s information. 

 Lastly, the main() function was created to test this program. This function invokes the ReadMatrix()and dijkstra() functions, then returns 0. 


There are a few images included in this repository, which includes the graph created for this program and a few test runs showing the program running correctly. 
