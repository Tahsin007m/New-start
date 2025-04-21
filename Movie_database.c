#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to store movie details
struct Movie {
    char title[100];
    char director[100];
    int year;
};

// Function to add a movie
void addMovie(struct Movie movies[], int *count) {
    if (*count >= 100) {
        printf("Database is full! Cannot add more movies.\n");
        return;
    }

    printf("Enter movie title: ");
    scanf(" %[^\n]", movies[*count].title);
    printf("Enter director name: ");
    scanf(" %[^\n]", movies[*count].director);
    printf("Enter release year: ");
    scanf("%d", &movies[*count].year);

    (*count)++;
    printf("Movie added successfully!\n\n");
}

// Function to display all movies
void displayMovies(struct Movie movies[], int count) {
    if (count == 0) {
        printf("No movies in the database!\n\n");
        return;
    }

    printf("\n-------- Movie Database ---------\n");
    for (int i = 0; i < count; i++) {
        printf("Movie no.%d:\n", i + 1);
        printf("\n");
        printf("Movie Title:  %s\n", movies[i].title);
        printf("Director:     %s\n", movies[i].director);
        printf("Release Year: %d\n\n", movies[i].year);
    }
}

// Function to search for a movie by title
void searchMovie(struct Movie movies[], int count) {
    if (count == 0) {
        printf("No movies in the database!\n\n");
        return;
    }

    char searchTitle[100];
    printf("Enter the title to search: ");
    scanf(" %[^\n]", searchTitle);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, searchTitle) == 0) {
            printf("\nMovie found:\n");
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Year: %d\n\n", movies[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie not found!\n\n");
    }
}

// Function to save movies to a file
void saveToFile(struct Movie movies[], int count) {
    FILE *file = fopen("movies.dat", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    // Write the count first
    fwrite(&count, sizeof(int), 1, file);
    
    // Write all movie records
    fwrite(movies, sizeof(struct Movie), count, file);
    
    fclose(file);
    printf("Movies saved to file successfully!\n\n");
}

// Function to load movies from a file
int loadFromFile(struct Movie movies[]) {
    FILE *file = fopen("movies.dat", "rb");
    if (file == NULL) {
        printf("No existing database file found. Starting with empty database.\n\n");
        return 0;
    }

    int count;
    // Read the count first
    fread(&count, sizeof(int), 1, file);
    
    // Read all movie records
    fread(movies, sizeof(struct Movie), count, file);
    
    fclose(file);
    printf("Movies loaded from file successfully!\n\n");
    return count;
}

int main() {
    struct Movie movies[100];
    int count = 0;
    int choice;

    // Load existing data from file at startup
    count = loadFromFile(movies);

    while (1) {
        printf("1. Add Movie\n");
        printf("2. Display All Movies\n");
        printf("3. Search Movie\n");
        printf("4. Save to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                searchMovie(movies, count);
                break;
            case 4:
                saveToFile(movies, count);
                break;
            case 5:
                // Ask if user wants to save before exiting
                printf("Do you want to save changes before exiting? (1=Yes, 0=No): ");
                int saveChoice;
                scanf("%d", &saveChoice);
                if (saveChoice == 1) {
                    saveToFile(movies, count);
                }
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }

    return 0;
}