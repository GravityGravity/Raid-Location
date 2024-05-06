#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Searches the location of each Query for RAID0 (STRIPING)
void searchR0 (int q, int c, int n) {

    int query = 0;
    int disksearch = -1;
    int stripesearch = -1;

    for (int i = 0; i < q; i++) {  //LOOPS through each query, searching for the query disk and query stripe

        scanf("%13d", &query);

        disksearch = ((query/c) % n);
        stripesearch = (((query / (n*c)) * c) + (query % c));
        
        printf("%d ", disksearch);
        printf("%d\n", stripesearch);
    }
}

//Searches the location of each Query and Query Backup for RAID01
void searchR01 (int q, int n) {

    int query = 0;
    int disksearch = -1;
    int stripesearch = -1;
    int diskcopysearch = -1;

    for (int i = 0; i < q; i++) { //LOOPS through each query, searching for the query disk and query stripe

        scanf("%13d", &query);

        disksearch = ((query % (n/2)));
        stripesearch = (query / (n/2));
        diskcopysearch = disksearch + (n/2);
        
        printf("%d ", disksearch);
        printf("%d ", stripesearch);
        printf("%d\n", diskcopysearch);
    }
}

//Searches the location of each Query for RAID1
void searchR1 (int n, int s, int q) {

    int query = -1;
    int disksearch = -1;
    int stripesearch = -1;

    for (int i = 0; i < q; i++) { //LOOPS through each query, searching for the query disk and query stripe

        scanf("%13d", &query);
        
        stripesearch = (query);
        disksearch = 0;

        printf("%d ", disksearch);
        printf("%d ", stripesearch);
        
        disksearch = 1;
        printf("%d\n", disksearch);

    }

}

//Searches the location of each Query and Query Backup for RAID10
void searchR10 (int q, int n) {

    int query = 0;
    int disksearch = -1;
    int stripesearch = -1;
    int diskcopysearch = -1;

    for (int i = 0; i < q; i++) { //LOOPS through each query, searching for the query disk and query stripe

        scanf("%13d", &query);

        disksearch = ((query % (n/2)) * 2);
        stripesearch = (query / (n/2));
        diskcopysearch = disksearch + 1;
        
        printf("%d ", disksearch);
        printf("%d ", stripesearch);
        printf("%d\n", diskcopysearch);
    }
}

//Searches the location of each Query and Parity block for RAID4
void searchR4 (int q, int n) {

    int query = 0;
    int disksearch = -1;
    int stripesearch = -1;

    for (int i = 0; i < q; i++) { //LOOPS through each query, searching for the query disk and query stripe

        scanf("%13d", &query);

        disksearch = (query % (n-1));
        stripesearch = (query / (n-1));
        
        printf("%d ", disksearch);
        printf("%d ", stripesearch);
        printf("%d\n", (n-1));
    }
}

//Searches the location of each Query and Parity block for RAID5
void searchR5 (int q, int n) {

    int query = 0;
    int disksearch = -1;
    int stripesearch = -1;
    int ppos = -1;

    for (int i = 0; i < q; i++) { //LOOPS through each query, searching for the query disk and query stripe and corresponding Parity block

        scanf("%13d", &query);

        stripesearch = (query / (n-1));
        ppos = (n-1) - (stripesearch % n);
        disksearch = query % (n);

        if (ppos == (disksearch)) {  //Checks if position of Query is conflicting with Parity position.  IF TRUE: Scan next disk for query.
            disksearch = disksearch + 1;
        }
    
        printf("%d ", disksearch);
        printf("%d ", stripesearch);
        printf("%d\n", ppos);
    }
}