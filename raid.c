#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raidtype.h" //contains implemenation of RAID LEVELS

/*
"T" - Raid level (0, 1, 01, 10, 4, 5)
"N" - # of disks
"C" - size of chunks
"S" - # of sectors in each disk
"Q" - # of queries
*/

char T[3]; //RAID Level
int N, C, S, Q;
int raidnum; //RAID level as integer


//Checks RAID level
void raid(char* T, int n, int s, int c, int q) {

    //Checks for RAID 01, if true translate RAID 01 into 2
    if( strcmp("01", T) == 0 ) {
        raidnum = 2;
    } 
    else {
        raidnum = atoi(T);  //Changes RAID level char to int
    }

    switch (raidnum) { //CALL FUNCTION SPECIFICED FOR RAID LEVEL

        case 0: //RAID0
            searchR0(q, c, n);
            break;

        case 1: //RAID1
            searchR1(n, s, q);
            break;

        case 2: //RAID01
            searchR01(q, n);
            break;

        case 4: //RAID4
            searchR4(q, n);
            break;

        case 5: //RAID5
            searchR5(q, n);
            break;

        case 10: //RAID10
            searchR10(q, n);
            break;
    }

}


int main () {

    scanf("%3s", T);
    scanf("%2d", &N);
    scanf("%2d", &C);
    scanf("%13d", &S);
    scanf("%10d", &Q);

    raid(T, N, S, C, Q);

    return 0;
}

