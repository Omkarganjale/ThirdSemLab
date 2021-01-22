'''
Created on 25-Aug-2020

@author: omkar
'''
global R,C
R=int(input('Enter number of rows: '))
C=int(input('Enter number of columns: '))

def setarr(lst):
    for r in range(0,R):
        tlist=[int(x) for x in input("Enter row number separated by comma: ").split(',')]
        lst.append(tlist)
        
def getarr(lst):
    i=0
    for r in lst:
        for c in r:
            #m=lst[c]
            print(" ",c,end=" ")
            #i=i+1
        print('')
        #print(end=" ")
def addarr(lst1,lst2):
    if(len(lst1)!=len(lst2)):
        print("ORDER DON'T MATCH")
    else:
        for r in range (0,R):
            for c in range (0,C):
                lst1[r][c]=lst1[r][c]+lst2[r][c]
    return lst1

def subarr(lst1,lst2):
    if(len(lst1)!=len(lst2)):
        print("ORDER DON'T MATCH")
    else:
        for i in range (0,len(lst1)):
            lst1[i]=lst1[i]-lst2[i]
    return lst1

lst1=[]
lst2=[]
print('Enter first array')
setarr(lst1)
print('Enter second array')
setarr(lst2)
c=int(input("\n1)add array 1 and 2\n2)subtract array 2 from 1\n3)multiply 1 and 2\n4)Transpose array 1"))
if c==1:
    lst3=addarr(lst1,lst2)
    getarr(lst3)
if c==2:
    lst3=subarr(lst1,lst2)
    getarr(lst3)