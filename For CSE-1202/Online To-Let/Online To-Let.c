#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to hold property information
struct Property {
    int id;
    char title[100];
    char location[100];
    int rent;
    int numRooms;
    int numFloors;
    struct Property* next;
};

// Structure to represent an edge between properties with the same location
struct LocationEdge {
    struct Property* property;
    struct LocationEdge* next;
};

// Structure to represent a property location node in the graph
struct LocationNode {
    char location[100];
    struct LocationEdge* edges;
    struct LocationNode* next;
};

// Function to display all menu options
void printMenuList() {
    printf("1. List All Properties\n");
    printf("2. Search by Maximum Rent\n");
    printf("3. Search by Number of Rooms\n");
    printf("4. Search by Number of Floors\n");
    printf("5. Search by Location\n");
    printf("6. Add a Property\n");
    printf("7. Exit\n");
}

// Function to display a property
void displayProperty(struct Property* property) {
    printf("Property ID: %d\n", property->id);
    printf("Title: %s\n", property->title);
    printf("Location: %s\n", property->location);
    printf("Rent: %d\n", property->rent);
    printf("Number of Rooms: %d\n", property->numRooms);
    printf("Number of Floors: %d\n", property->numFloors);
    printf("\n");
}

// Function to add a new property to the linked list
struct Property* addProperty(struct Property* head, int id, const char* title, const char* location, int rent, int numRooms, int numFloors) {
    struct Property* newProperty = (struct Property*)malloc(sizeof(struct Property));
    if (newProperty == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newProperty->id = id;
    strncpy(newProperty->title, title, sizeof(newProperty->title));
    strncpy(newProperty->location, location, sizeof(newProperty->location));
    newProperty->rent = rent;
    newProperty->numRooms = numRooms;
    newProperty->numFloors = numFloors;
    newProperty->next = head;

    return newProperty;
}

// Function to create a new location node in the graph
struct LocationNode* createLocationNode(const char* location) {
    struct LocationNode* newNode = (struct LocationNode*)malloc(sizeof(struct LocationNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strncpy(newNode->location, location, sizeof(newNode->location));
    newNode->edges = NULL;
    newNode->next = NULL;

    return newNode;
}

// Function to add an edge between two properties with the same location
void addLocationEdge(struct LocationNode* locationNode, struct Property* property) {
    struct LocationEdge* newEdge = (struct LocationEdge*)malloc(sizeof(struct LocationEdge));
    if (newEdge == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newEdge->property = property;
    newEdge->next = locationNode->edges;
    locationNode->edges = newEdge;
}

// Function to search for properties by maximum rent
void searchByMaxRent(struct Property* head, int maxRent) {
    printf("Properties within specified rent:\n");
    for (struct Property* current = head; current != NULL; current = current->next) {
        if (current->rent <= maxRent) {
            displayProperty(current);
        }
    }
}

// Function to search for properties by number of rooms
void searchByNumRooms(struct Property* head, int numRooms) {
    printf("Properties with specified number of rooms:\n");
    for (struct Property* current = head; current != NULL; current = current->next) {
        if (current->numRooms == numRooms) {
            displayProperty(current);
        }
    }
}

// Function to search for properties by number of floors
void searchByNumFloors(struct Property* head, int numFloors) {
    printf("Properties with specified number of floors:\n");
    for (struct Property* current = head; current != NULL; current = current->next) {
        if (current->numFloors == numFloors) {
            displayProperty(current);
        }
    }
}

// Function to search for properties by location
void searchByLocation(struct Property* head, struct LocationNode* locationGraph, const char* location) {
    printf("Properties at specified location:\n");

    // Find the location node in the graph
    struct LocationNode* locationNode = NULL;
    for (locationNode = locationGraph; locationNode != NULL; locationNode = locationNode->next) {
        if (strcmp(locationNode->location, location) == 0) {
            break;
        }
    }

    if (locationNode == NULL) {
        printf("Location not found.\n");
        return;
    }

    // Traverse the edges to find properties at this location
    for (struct LocationEdge* edge = locationNode->edges; edge != NULL; edge = edge->next) {
        displayProperty(edge->property);
    }
}

// Function to free memory allocated for the linked list
void freeList(struct Property* head) {
    while (head != NULL) {
        struct Property* temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to free memory allocated for the location graph
void freeLocationGraph(struct LocationNode* locationGraph) {
    while (locationGraph != NULL) {
        struct LocationNode* tempNode = locationGraph;
        locationGraph = locationGraph->next;

        // Free edges associated with this location node
        while (tempNode->edges != NULL) {
            struct LocationEdge* tempEdge = tempNode->edges;
            tempNode->edges = tempNode->edges->next;
            free(tempEdge);
        }

        free(tempNode);
    }
}

int main() {
    struct Property* head = NULL;
    struct LocationNode* locationGraph = NULL;

    // Initialize the linked list with sample data
    head = addProperty(head, 4, "Imran Villa", "Rupatoli", 6200, 2, 4);
    head = addProperty(head, 3, "Habib Plaza", "Bottola", 5000, 2, 5);
    head = addProperty(head, 2, "Kuddus Manson", "CNB Road", 6000, 3, 2);
    head = addProperty(head, 1, "Manson Villa", "Rupatoli", 8000, 3, 2);

    // Initialize the location graph
    locationGraph = createLocationNode("Downtown");
    addLocationEdge(locationGraph, head);
    struct LocationNode* suburbNode = createLocationNode("Suburb");
    addLocationEdge(suburbNode, head->next->next);
    addLocationEdge(suburbNode, head->next->next->next);
    locationGraph->next = suburbNode;

    printf("Welcome to Online To-Let Portal\n");
    printf("================================\n");

    while (1) {
        printMenuList();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("List of All Properties:\n");
                printf("================================\n");
                for (struct Property* current = head; current != NULL; current = current->next) {
                    displayProperty(current);
                }
                printf("================================\n");
                break;

            case 2: {
                int maxRent;
                printf("Enter maximum rent: ");
                scanf("%d", &maxRent);
                printf("================================\n");
                searchByMaxRent(head, maxRent);
                printf("================================\n");
                break;
            }

            case 3: {
                int numRooms;
                printf("Enter number of rooms: ");
                scanf("%d", &numRooms);
                printf("================================\n");
                searchByNumRooms(head, numRooms);
                printf("================================\n");
                break;
            }

            case 4: {
                int numFloors;
                printf("Enter number of floors: ");
                scanf("%d", &numFloors);
                printf("================================\n");
                searchByNumFloors(head, numFloors);
                printf("================================\n");
                break;
            }

            case 5: {
                char location[100];
                printf("Enter location: ");
                scanf("%s", location);
                printf("================================\n");
                searchByLocation(head, locationGraph, location);
                printf("================================\n");
                break;
            }

            case 6: {
                printf("================================\n");
                int id, rent, numRooms, numFloors;
                char title[100], location[100];
                printf("Enter property ID: ");
                scanf("%d", &id);
                printf("Enter property title: ");
                scanf("%s", title);
                printf("Enter property location: ");
                scanf("%s", location);
                printf("Enter property rent: ");
                scanf("%d", &rent);
                printf("Enter number of rooms: ");
                scanf("%d", &numRooms);
                printf("Enter number of floors: ");
                scanf("%d", &numFloors);

                head = addProperty(head, id, title, location, rent, numRooms, numFloors);

                // Update the location graph
                struct LocationNode* locationNode = locationGraph;
                while (locationNode != NULL) {
                    if (strcmp(locationNode->location, location) == 0) {
                        addLocationEdge(locationNode, head);
                        break;
                    }
                    locationNode = locationNode->next;
                }
                if (locationNode == NULL) {
                    // Location not found in the graph, create a new node
                    locationNode = createLocationNode(location);
                    addLocationEdge(locationNode, head);
                }

                break;
            }

            case 7:
                freeList(head);
                freeLocationGraph(locationGraph);
                printf("Thank you for using Online To-Let Portal!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
