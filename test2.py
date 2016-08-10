def LCSubstr_len(S, T):
   m = len(S); n = len(T)
   L = [[0] * (n+1) for i in xrange(m+1)]
   lcs = 0
   for i in xrange(m):
       for j in xrange(n):
           if S[i] == T[j]:
               L[i+1][j+1] = L[i][j] + 1
               lcs = max(lcs, L[i+1][j+1])
           else:
               L[i+1][j+1] = max(L[i+1][j], L[i][j+1])
   return lcs

#I think something is wrong in LCSubstr_len. I get some wrong results in some cases

def LCSubstr_set(S, T):
   m = len(S); n = len(T)
   L = [[0] * (n+1) for i in xrange(m+1)]
   LCS = set()
   longest = 0
   for i in xrange(m):
       for j in xrange(n):
           if S[i] == T[j]:
               v = L[i][j] + 1
               L[i+1][j+1] = v
               if v > longest:
                   longest = v
                   LCS = set()
               if v == longest:
                   if type(S)==list:
                       LCS.add( tuple(S[i-v+1:i+1]) )
                   else:
                       LCS.add( S[i-v+1:i+1] )
   return LCS
from random import choice
s1= ''.join([choice(('A','C','G','T')) for i in range(10000)])
s2= ''.join([choice(('A','C','G','T')) for i in range(10000)])
print "-"
print LCSubstr_len(s1,s2)



