#include <stdio.h>
#include <ctype.h> // Include ctype.h for tolower

// Function to convert a string to lowercase
void toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

// Function to print welcome text
void welcomeText()
{
    printf("\n");
    printf("  W   W  EEEEE  L      CCCC  OOOOO  M   M  EEEEE        TTTTTTTT OOOOO       \n");
    printf("  W   W  E      L     C      O   O  MM MM  E               TT    O   O       \n");
    printf("  W W W  EEEE   L     C      O   O  M M M  EEEE            TT    O   O       \n");
    printf("  W W W  E      L     C      O   O  M   M  E               TT    O   O       \n");
    printf("  WW WW  EEEEE  LLLL   CCCC  OOOOO  M   M  EEEEE           TT    OOOOO       \n");

    printf("\n");
    printf("\n");
    printf("  SSSSS  RRRRR  IIIII  JJJJJ  AAAAA  N   N  '''  SSSSS   \n");
    printf("  S      R   R    I      J    A   A  NN  N  ''   S       \n");
    printf("  SSSSS  RRRRR    I      J    AAAAA  N N N  '    SSSSS   \n");
    printf("      S  R  R     I   J  J    A   A  N  NN           S   \n");
    printf("  SSSSS  R   R  IIIII  JJ     A   A  N   N       SSSSS   \n");
    printf("\n");
    printf("\n");
    printf("  PPPPP  H   H  OOOOO  N   N  EEEEE  BBBBB  OOOOO  OOOOO  K   K\n");
    printf("  P   P  H   H  O   O  NN  N  E      B   B  O   O  O   O  K  K \n");
    printf("  PPPPP  HHHHH  O   O  N N N  EEEE   BBBBB  O   O  O   O  KK   \n");
    printf("  P      H   H  O   O  N  NN  E      B   B  O   O  O   O  K  K \n");
    printf("  P      H   H  OOOOO  N   N  EEEEE  BBBBB  OOOOO  OOOOO  K   K\n");
    printf("\n");

    printf("\n\n");
}
