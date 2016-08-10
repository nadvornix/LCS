/* 
 * File:   test.cpp
 * Author: jirka
 *
 * Created on November 17, 2010, 12:19 PM
 */

#include <stdlib.h>
#include <string>
#include <stdio.h>
using std::string;

int LCS(const string& str1, const string& str2)
{
     if(str1.empty() || str2.empty())
     {
          return 0;
     }

     int *curr = new int [str2.size()];
     int *prev = new int [str2.size()];
     int *swap = NULL;
     int maxSubstr = 0;

     for(int i = 0; i<str1.size(); ++i)
     {
          for(int j = 0; j<str2.size(); ++j)
          {
               if(str1[i] != str2[j])
               {
                    curr[j] = 0;
               }
               else
               {
                    if(i == 0 || j == 0)
                    {
                         curr[j] = 1;
                    }
                    else
                    {
                         curr[j] = 1 + prev[j-1];
                    }
                    //The next if can be replaced with:
                    //maxSubstr = max(maxSubstr, curr[j]);
                    //(You need algorithm.h library for using max())
                    if(maxSubstr < curr[j])
                    {
                         maxSubstr = curr[j];
                    }
               }
          }
          swap=curr;
          curr=prev;
          prev=swap;
     }
     delete [] curr;
     delete [] prev;
     return maxSubstr;
}
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
/*
 * 
 */
int main(int argc, char** argv) {

    char **res;
    char *s1, *s2;
    int i;


    s1 = randStr(10000);
    /*
        printf(">%s<\n", s1);
     */
    s2 = randStr(10000);
    i = LCS(s1, s2);
    printf("%d\n",i);
    return (EXIT_SUCCESS);
}

