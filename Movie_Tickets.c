#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

/*void displayMovies(char movies[3][50])
{
    printf("\n--- Available Movies ---\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d. %s\n", i + 1, movies[i]);
    }
    printf("-----------------------\n");
}*/

typedef struct
{
    int row;
    int col;
} Seat;

// Function to display the theater view
void displayTheaterView(char theater[ROWS][COLS])
{
    system("cls"); // Clear the console screen
    printf("\n\t---Theater View---\n");
    printf("\n");
    // Display column numbers
    printf("     ");
    for (int j = 0; j < COLS; j++)
    {
        printf("%-4d", j + 1);
    }
    printf("\n");

    // Display theater seats
    for (int i = 0; i < ROWS; i++)
    {
        printf("%-3d", i + 1); // Display row number
        for (int j = 0; j < COLS; j++)
        {
            if (theater[i][j] == 'A')
                printf("\033[31;1m| %c \033[0m", theater[i][j]); // Red color for available seats
            else if (theater[i][j] == 'S')
                printf("\033[32;1m| %c \033[0m", theater[i][j]); // Green color for selected seats
            else if (theater[i][j] == 'B')
                printf("\033[33;1m| %c \033[0m", theater[i][j]); // Yellow color for bought seats
        }
        printf("\n");
    }
    printf("--------------------\n");
}

// Function to check if a seat is available
int isSeatAvailable(char theater[ROWS][COLS], int row, int col)
{
    return theater[row][col] == 'A';
}

// Function to mark a seat as selected
void selectSeat(char theater[ROWS][COLS], int row, int col)
{
    system("cls");
    theater[row][col] = 'S';
}

// Function to mark a seat as available
void cancelSeat(char theater[ROWS][COLS], int row, int col)
{
    theater[row][col] = 'A';
}

// Function to buy a seat
void buySeat(char theater[ROWS][COLS], int row, int col)
{
    system("cls");
    theater[row][col] = 'B';
    printf("\n\033[33;1mSeat at Row %d, Column %d has been successfully bought.\033[0m\n", row + 1, col + 1); // Yellow color for success message
}

// Function to clear the input buffer
void clearInputBuffer()
{
    while (getchar() != '\n')
        ;
}

// Function to handle customer login
int customerLogin()
{
    char username[20];
    char password[20];

    printf("\n--- Customer Login ---\n");
    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // You can add authentication logic here to validate customer credentials

    // For simplicity, returning 1 for successful login
    return 1;
}

// Function to handle administrator login
int adminLogin()
{
    system("cls");
    char username[20];
    char password[20];

    printf("\n--- Administrator Login ---\n");
    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // You can add authentication logic here to validate administrator credentials
    // For simplicity, we are using hardcoded credentials

    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0)
    {
        return 1;
    }
    else
    {
        printf("\n\033[31;1mInvalid username or password. Login failed.\033[0m\n"); // Red color for error message
        return 0;
    }
}

// Function to update the movie ticket rate
void updateTicketRate(int *ticketRate)
{
    printf("\n--- Update Ticket Rate ---\n");
    printf("Current Ticket Rate: %d rupees\n", *ticketRate);
    printf("Enter the new ticket rate: ");
    scanf("%d", ticketRate);
    printf("\nTicket Rate updated successfully.\n");
}

// Function to update the snack items
void updateSnackItems(char snacks[3][20])
{
    printf("\n--- Update Snack Items ---\n");
    printf("Current Snack Items:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d. %s\n", i + 1, snacks[i]);
    }
    printf("Enter the new snack items:\n");
    clearInputBuffer();
    for (int i = 0; i < 3; i++)
    {
        printf("Snack %d: ", i + 1);
        fgets(snacks[i], sizeof(snacks[i]), stdin);
        snacks[i][strcspn(snacks[i], "\n")] = 0; // Remove the newline character
    }
    printf("\nSnack items updated successfully.\n");
}

// Function to add movies available to watch
void addMovies(char movies[3][50])
{
    printf("\n--- Add Movies ---\n");
    clearInputBuffer();
    for (int i = 0; i < 3; i++)
    {
        printf("Movie %d: ", i + 1);
        fgets(movies[i], sizeof(movies[i]), stdin);
        movies[i][strcspn(movies[i], "\n")] = 0; // Remove the newline character
    }
    printf("\nMovies added successfully.\n");
}

int main()
{
    char theater[ROWS][COLS];

    // Initialize the theater view with available seats
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            theater[i][j] = 'A';
        }
    }

    int numOfSelectedSeats = 0, numOfSeats;
    int option, row, col;
    int ticketRate = 150; // Default ticket rate

    // Default snack items
    char snacks[3][20] = {
        "Soda",
        "PopCorn",
        "Chips",
    };

    // Default movies
    char movies[3][50] = {
        "Adhipurush",
        "Spiderman:Across The SpiderVerse",
        "Salar"};

    printf("\n--- Welcome to Movie Ticket Booking System ---\n");

    do
    {
        // Display the menu
        printf("\nOptions:\n");
        printf("1. View Available Seats\n");
        printf("2. Select Seat(s)\n");
        printf("3. Cancel Selected Seats\n");
        printf("4. Buy Selected Seats\n");
        printf("5. Administrator Login\n");
        printf("6. Show Available Movies\n");
        printf("7. Show Snacks\n");
        printf("8. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            // Display the theater view
            displayTheaterView(theater);
            break;
        case 2:
        {
            // Select seat(s)
            int numOfSeats;
            printf("\nEnter the number of seats to select: ");
            scanf("%d", &numOfSeats);
            if (numOfSeats <= 0)
            {
                printf("\n\033[31;1mInvalid number of seats. Please try again.\033[0m\n"); // Red color for error message
                break;
            }

            printf("\nEnter the row and column of the seats (separated by a space):\n");
            clearInputBuffer();
            for (int i = 0; i < numOfSeats; i++)
            {
                scanf("%d %d", &row, &col);
                row--; // Adjust row number to 0-based index
                col--; // Adjust column number to 0-based index
                if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
                {
                    if (isSeatAvailable(theater, row, col))
                    {
                        selectSeat(theater, row, col);
                        numOfSelectedSeats++;
                        printf("\n\033[32;1mSeat at Row %d, Column %d has been selected.\033[0m\n", row + 1, col + 1); // Green color for success message
                    }
                    else
                    {
                        printf("\n\033[31;1mSeat at Row %d, Column %d is not available.\033[0m\n", row + 1, col + 1); // Red color for error message
                    }
                }
                else
                {
                    printf("\n\033[31;1mInvalid seat selection.\033[0m\n"); // Red color for error message
                }
            }
            break;
        }
        case 3:
        {
            // Cancel selected seats
            if (numOfSelectedSeats > 0)
            {
                printf("\nEnter the row and column of the seats to cancel (separated by a space):\n");
                clearInputBuffer();
                for (int i = 0; i < numOfSelectedSeats; i++)
                {
                    scanf("%d %d", &row, &col);
                    row--; // Adjust row number to 0-based index
                    col--; // Adjust column number to 0-based index
                    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
                    {
                        if (theater[row][col] == 'S')
                        {
                            cancelSeat(theater, row, col);
                            numOfSelectedSeats--;
                            printf("\n\033[33;1mSeat at Row %d, Column %d has been successfully canceled.\033[0m\n", row + 1, col + 1); // Yellow color for success message
                        }
                        else
                        {
                            printf("\n\033[31;1mSeat at Row %d, Column %d is not selected.\033[0m\n", row + 1, col + 1); // Red color for error message
                        }
                    }
                    else
                    {
                        printf("\n\033[31;1mInvalid seat selection.\033[0m\n"); // Red color for error message
                    }
                }
            }
            else
            {
                printf("\n\033[31;1mNo seats are currently selected.\033[0m\n"); // Red color for error message
            }
            break;
        }
        case 4:
        {

            int totalPrice = ticketRate * numOfSelectedSeats;

            printf("\n--- Bank Account Payment ---\n");
            printf("Total Amount: %d rupees\n", totalPrice);

            char accountNumber[20];
            char pin[5];

            printf("Enter your bank account number: ");
            scanf("%s", accountNumber);

            printf("Enter your PIN: ");
            scanf("%s", pin);

            // Simulating payment processing
            printf("\nProcessing payment...\n");

            if (numOfSelectedSeats > 0)
            {

                theater[row][col] = 'B';
                printf("\n\033[33;1mSeat at Row %d, Column %d has been successfully bought.\033[0m\n", row + 1, col + 1);
            }
            else
            {
                printf("payment failed");
            }
            break;
        }
        case 5:
        {
            // Administrator login
            if (adminLogin())
            {
                int adminOption;
                do
                {
                    printf("\nAdministrator Options:\n");
                    printf("1. Update Ticket Rate\n");
                    printf("2. Update Snack Items\n");
                    printf("3. Add Movies\n");
                    printf("4. Exit Administrator Menu\n");
                    printf("Enter your option: ");
                    scanf("%d", &adminOption);

                    switch (adminOption)
                    {
                    case 1:
                        updateTicketRate(&ticketRate);
                        break;
                    case 2:
                        updateSnackItems(snacks);
                        break;
                    case 3:
                        addMovies(movies);
                        break;
                    case 4:
                        printf("\nExiting Administrator Menu...\n");
                        break;
                    default:
                        printf("\n\033[31;1mInvalid option. Please try again.\033[0m\n"); // Red color for error message
                    }
                } while (adminOption != 4);
            }
            break;
        }
        case 6:
            printf("\n--- Available Movies ---\n");
            for (int i = 0; i < 3; i++)
            {
                printf("%d. %s\n", i + 1, movies[i]);
            }
            printf("-----------------------\n");
            break;
        case 7:
        {
            printf("\n--- Available Snacks ---\n");
            for (int i = 0; i < 3; i++)
            {
                printf("%d. %s\n", i + 1, snacks[i]);
            }
            printf("-----------------------\n");
        }
        break;
        case 8:
            printf("\nThank you for using Movie Ticket Booking System!\n");
            break;
        default:
            printf("\n\033[31;1mInvalid option. Please try again.\033[0m\n"); // Red color for error message
        }
    } while (option != 6);

    return 0;
}
