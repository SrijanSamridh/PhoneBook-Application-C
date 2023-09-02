#include <stdio.h>
#include "Services/get.c"
#include "Services/post.c"

int main(void)
{
    const char *baseUrl = "https://c-project-backend-server-srijansamridh.vercel.app";
    const char *getUrl = "http://localhost:8080/api/get";    // URL for GET request
    const char postUrl[] = "http://localhost:8080/api/save"; // URL for POST request
    int choice;
    char name[20];
    char number[20];

    printf("Choose an operation:\n");
    printf("1. Fetch All the Contacts\n");
    printf("2. Save Contacts\n");
    printf("3. Search for a Contact\n");
    printf("4. Exit\n");

    while (1)
    {
        printf("Enter your choice (1, 2, 3 or 4): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Send a GET request
            if (sendGetRequest(getUrl) != 0)
            {
                fprintf(stderr, "GET request failed.\n");
            }
            printf("\n\n\n");
            break;
        case 2:
            // Send a POST request
            printf("Enter your name: ");
            scanf("%s", name);
            printf("Enter your number: ");
            scanf("%s", number);

            // Creating JSON data string
            char postData[100];
            snprintf(postData, sizeof(postData), "{\"name\": \"%s\", \"number\": \"%s\"}", name, number); // Properly format JSON

            if (sendPostRequest(postUrl, postData) != 0)
            {
                fprintf(stderr, "POST request failed.\n");
            }
            printf("\n\n\n");
            break;
        case 3:
            // Search for a number
            printf("Enter the name to search for: ");
            scanf("%s", name);

            if (searchNumber(name) != 0)
            {
                fprintf(stderr, "Search failed.\n");
            }
            printf("\n\n\n");
            break;
        case 4:
            // Exit
            printf("\n****** Exiting Thank You ******\n");
            return 0;
        default:
            printf("Invalid choice.\n");
            printf("\n\n");
            break;
        }
    }

    return 0;
}
