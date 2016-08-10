from random import choice,randint
import sys


print ">seq1"
print ''.join([choice(('A','C','G','T')) for i in range(10000)])
print ">seq2"
print ''.join([choice(('A','C','G','T')) for i in range(10000)])
sys.exit()
j=0
try:
  for i in range(2):
    sys.stderr.write("\n%s\n"%j)
    j=j+1

    a=randint(0,int(sys.argv[1]))
    sys.stderr.write("(%s)\n"%a)
    text = ''.join([choice(('A','C','G','T')) for i in range(a)])
    
    sys.stdout.write("%s\n"%text)
  
  
except KeyboardInterrupt:
  sys.stdout.close()
  sys.exit()

