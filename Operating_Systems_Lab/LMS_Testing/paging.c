// Paging

#include <stdio.h>

#define MAX 50

int main() {
    int page[MAX], i, n, f, ps, off, pno;

    scanf("%d", &n);
    scanf("%d", &ps);
    scanf("%d", &f);

    for (i = 0; i < n; i++)
        page[i] = -1;

    for (i = 0; i < n; i++)
        scanf("%d", &page[i]);

    scanf("%d%d", &pno, &off);
    if (page[pno] == -1)
        printf("Not available");
    else
        printf("%d,%d", page[pno], off);

    return 0;
}
