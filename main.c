#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>

void printS(char ** substrs) {
    /*
        printf("PRINTFNAM!!!");
     */
    int i;
    if (substrs != NULL) {
        //for (i = 0; i<DELKA; i++) {
        for (i = 0; substrs[i]; i++) {
            fprintf(stderr, ">%d>%s<\n", i, substrs[i]);
        }
        fprintf(stderr, "#%d#%s<\n", i, substrs[i]);
    } else {
        fprintf(stderr, ">>>NULL<\n");
    }
}

void ppp12(char * p1, char *p2, int delka) {
    int i;
    printf("\n");
    for (i = 0; i < delka; i++) {
        printf("%d ", (int) p1[i]);
    }
    printf("\n");
    for (i = 0; i < delka; i++) {
        printf("%d ", (int) p2[i]);
    }
    printf("\n\n");
}

#endif /* __PROGTEST__ */

#include <string.h>

int DELKA, POZ;

void smazatPole(char ** substrs) {
    int i;
    for (i = 0; i < POZ; i++) {
        free(substrs[i]);
    }
    POZ = 0;
}

int jeTam(char ** substrs, char *str, int delka) {
    int i;
    for (i = 0; i < POZ; i++) {
        if (*(substrs + i) != NULL && strncmp(*(substrs + i), str, (size_t) delka) == 0) {
            return 1;
        }
    }
    return 0;
}

int jeGen(char chr) {
    if (chr != 'A' && chr != 'T' && chr != 'C' && chr != 'G') {
        return 0;
    }
    return 1;
}

char ** pridatMoznost(char ** substrs, char *str, int zacatek, int konec) {
    char **newSubs;
    int k, delka = konec - zacatek;

    if (POZ + 1 >= DELKA) {
        DELKA = DELKA * 2;

        newSubs = (char **) malloc(sizeof (char*) * (DELKA + 2));

        for (k = 0; k < DELKA / 2; k++) {
            newSubs[k] = substrs[k];
        }
        free(substrs);
        substrs = NULL;

        substrs = newSubs;

    }


    if (!jeTam(substrs, (str + zacatek), delka)) {

        substrs[POZ] = (char *) malloc(sizeof (char) * (delka + 1));

        strncpy(substrs[POZ], (str + zacatek), (size_t) delka);
        substrs[POZ][delka] = '\0';
        POZ++;

    }
    return substrs;
}

char ** LCS(char * s1, char * s2) {
    int lenS1 = strlen(s1), lenS2 = strlen(s2), i, j, k, longest = 0, v;
    char ** substrs;
    int * p1, *p2, *c;
    DELKA = 4, POZ = 0;
    substrs = NULL;
    if (strlen(s1) == 0 || strlen(s2) == 0) {
        return NULL;
    }

    for (i = 0; i < lenS1; i++) //validace stringu
        if (!jeGen(*(s1 + i)))
            return NULL;

    for (i = 0; i < lenS2; i++)
        if (!jeGen(*(s2 + i)))
            return NULL;

    p1 = (int *) malloc(sizeof (int) * (lenS2 + 1)); //tabulka shod
    p2 = (int *) malloc(sizeof (int) * (lenS2 + 1));

    for (j = 0; j < lenS2 + 1; j++) {
        p1[j] = 0;
        p2[j] = 0;
    }

    v = 0;
    for (i = 0; i < lenS1; i++) {
        for (j = 0; j < lenS2; j++) {
            if (s1[i] == s2[j]) {
                
                v = p1[j] + 1;

                p2[j + 1] = v;
                if (v > longest) {
                    
                    longest = v;
                    smazatPole(substrs);

                }
                if (v == longest) {
/*
                    printf("%d,%d\n",v,longest);
*/
                    if (substrs == NULL) {
                        substrs = (char **) malloc(sizeof (char*) * (DELKA + 1));
                    }
                    substrs = pridatMoznost(substrs, s1, i - v + 1, i + 1);
                }
            }
        }

        c = p1;
        p1 = p2;
        p2 = c;
        for (k = 0; k < lenS2 + 1; k++) {
            p2[k] = 0;
        }
    }

    free(p1);
    free(p2);

    if (substrs != NULL) {
        //printf("666.) POZ:%d\n", POZ);
        //substrs[POZ] = (char *) malloc(sizeof (char*));
        substrs[POZ] = NULL;
    }

    return substrs;
}

#ifndef __PROGTEST__

char* randStr(int len) {
    int i, r;
    char *str;
    str = (char *) malloc(sizeof (char) *(len + 1));
    for (i = 0; i < len; i++) {
        r = rand() % 4;
        
        switch (rand() % 4) {
            case 0:
                str[i] = 'A';
                break;

            case 1:
                str[i] = 'C';
                break;

            case 2:
                str[i] = 'G';
                break;

            case 3:
                str[i] = 'T';
                break;
        }
    }
    str[len] = '\0';
    return str;
}

int main(int argc, char * argv []) {
    char **res;
    char *s1, *s2;
    int i;


    s1 = randStr(10000);
    /*
        printf(">%s<\n", s1);
     */
    s2 = randStr(10000);
    /*
        printf(">%s<\n", s2);
     */

    /*
        s1="ATTTGTTTA";
        s2="GTTTATTTG";
     */
    res = LCS(s1, s1);
    printS(res);
    for (i = 0; ((res + i) != NULL) && (*(res + i) != NULL); i++) {
        free(*(res + i));
    }
    //    free(res[i]);
    free(res);
    /*
        free(s1);
        free(s2);
     */


    printf("   - - - - - \n");
    /*
        }
     */


    //res = LCS("ATAT", "TATA");
    //printS(res);
    //ACTG

    return 0;
}
#endif /* __PROGTEST__ */
