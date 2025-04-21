Introduction: 
Movie Database System, a C program designed to store, manage, and retrieve movie records 
for a fixed number of movies. The system allows the user to: 
 Add new movies 
 Display all movies 
 Search for movies by title 
 Save and load the data from a file 
This program uses file handling for persistent storage, ensuring data is retained between each 
program executions.

Data Structure and Functions: 
The program uses a struct to store the movie details, the struct stores the title, director or 
author and the release date of a movie. An array of movie structure holds up to 100 movies. 
The count variable tracks the number of movies currently stored. The program uses 4 
function types.

File Handling and Main Program: 
Saving data and loading data, the program writes the count first, followed by all movie records. 
Uses fwrite() for file operations. For loading data, it reads the count first, then loads all movie 
records. Uses fread() for file reading.  
The program loads the existing movies from movies.dat file. Displays the options like add, 
display, search, save, exit. Executes the selected function. It searches the exact name by title 
(case-sensitive comparison), reports if movie is not found. When exiting it askes the user to 
save the changes before closing the program. 

Conclusion: 
This program provides basic movie database functionality with file persistence. While 
functional, it has several areas for improvement in input validation, features, and user 
experience. The core structure works well and could be expanded into a more robust application 
with additional development.
