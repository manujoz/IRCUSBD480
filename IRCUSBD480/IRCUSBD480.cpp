#include <iostream>
#include "USBD480_lib.h"

int main()
{
    int width = 480;
    int height = 272;

    int displays = USBD480_GetNumberOfDisplays();
    if (displays < 1)
    {
        printf("No displays found\n\r");
        return 0;
    }
    else
    {
        printf("%d display(s) found\n\r", displays);
    }

    printf("No displays found\n\r");

    return 0;
}
