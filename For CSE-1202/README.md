Here I provide my project's code step by step to explain its functionality:

1. **Data Structures**:

    -> "struct Property": This structure represents information about a property. 
        It has the following attributes:
            -> "int id": An ID to uniquely identify the property.
            -> "char title[100]": The title or name of the property (up to 100 characters).
            -> "char location[100]": The location of the property (up to 100 characters).
            -> "int rent": The rent amount for the property.
            -> "int numRooms": The number of rooms in the property.
            -> "int numFloors": The number of floors in the property.
            -> "struct Property* next": A pointer to the next property in a linked list.

    -> "struct LocationEdge": Represents an edge between properties that share the same location. 
        It is used in the location-based search.

    -> "struct LocationNode": Represents a node in a graph used to organize properties based on their location. 
       It has the following attributes:
        -> "char location[100]": The location name (up to 100 characters).
        -> "struct LocationEdge* edges": A pointer to the first edge connected to this location.
        -> "struct LocationNode* next": A pointer to the next location node in the graph.

2. **Functions**:

    -> "printMenuList()": This function prints a menu list displaying various options for the user.

    -> "displayProperty()": It displays the details of a property when provided with a "struct Property*".

    -> "addProperty()": Adds a new property to the linked list of properties. 
        It allocates memory for a new property, sets its attributes, and inserts it at the beginning of the linked list.

    -> "createLocationNode()": Creates a new location node in the location graph. 
       It allocates memory for the node and initializes its attributes.

    -> "addLocationEdge()": Adds an edge between a location node and a property with the same location. 
       It is used to connect properties to their corresponding location nodes in the graph.

    -> "searchByMaxRent()": Searches and displays properties with rent less than or equal to a specified maximum rent.

    -> "searchByNumRooms()": Searches and displays properties with a specified number of rooms.

    -> "searchByNumFloors()": Searches and displays properties with a specified number of floors.

    -> "searchByLocation()": Searches and displays properties located in a specified location using the location graph.

    -> "freeList()": Frees memory allocated for the linked list of properties. 
       It iterates through the linked list and deallocates memory for each property.

    -> "freeLocationGraph()": Frees memory allocated for the location graph. 
       It iterates through the location graph nodes and edges and deallocates memory.

3. **Main Function**:

    -> Initializes "head" and "locationGraph" to "NULL". 
      These are pointers to the linked list of properties and the location graph, respectively.

    -> Initializes the linked list with sample property data using the "addProperty()" function.

    -> Initializes the location graph with a sample location node and adds edges connecting properties with their locations.

    -> Displays a welcome message and enters a loop to present a menu to the user repeatedly.

    -> Inside the loop:
        -> It prints the menu using "printMenuList()" and prompts the user for their choice.
        -> Based on the user's choice, it performs various operations. 
           Such as listing properties, searching properties, adding new properties, or exiting the program.
        -> When a new property is added, it also updates the location graph to maintain the connection between properties and locations efficiently.

    -> The program continues to loop until the user chooses to exit ("case 7").

    -> Upon program exit, it frees memory allocated for the linked list of properties and the location graph and displays a "thank you" message.
