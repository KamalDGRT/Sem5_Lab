#include<stdio.h>
#include<stdlib.h>

int main() {
    typedef int semphore;

    semphore sread = 0, swrite = 0;
    int ch, r = 0;

    printf("Reader writer\n");

    do {
        printf("Menu");
        printf("\n1.Read from file");
        printf("\n2.Write to file");
        printf("\n3.Exit the reader");
        printf("\n4.Exit the writer");
        printf("\n5.Exit");

        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch(ch) {
            case 1: 
                if(swrite == 0) {
                    sread = 1;
                    r += 1;
                    printf("Reader %d reads\n", r);
                } else {
                    printf("Not possible\n");
                }
            break;

            case 2: 
                if(sread == 0 && swrite == 0) {
                    swrite = 1;
                    printf("Writer in progress\n");
                } else if (swrite == 1) {
                    printf("Writer writes the files\n");
                } else if (sread == 1) {
                    printf("Cannot write while reader reads the file\n");
                }
                break;

            case 3: 
                if(r != 0) {
                    printf("The reader %d closes the file\n", r);
                    r -= 1;
                    if(r == 0) {
                        sread = 0;
                    } 
                } else if (r == 0) {
                    printf("Currently no readers access the file\n");
                    sread = 0;
                }
            break;

            case 4: 
                if(swrite == 1) {
                    printf("Writer closes the file\n");
                    swrite = 0;
                } else {
                    printf("There is no writer in the file\n");
                }
            break;

            case 5: exit(0);
        }
    } while(ch < 6);

    return 0;
}

