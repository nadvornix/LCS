

def LCS_set2(S, T):
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

def LCS_set(s1, s2):
   m = len(s1); n = len(s2)
   L = [[0] * (n+1) for i in xrange(m+1)]
   
   longest = 0
   for i in xrange(m):
       for j in xrange(n):
           if s1[i] == s2[j]:
               v = L[i][j] + 1

               L[i+1][j+1] = v
               if v > longest:
                   longest = v
                   print ' - - - - - nulujem - - - - - -'
                   #LCS = set()
               if v == longest:

                       print(s1[i-v+1:i+1])


LCS_set("ATAT", "TATA")

