'''
Created on 29-Aug-2020

@author: omkar
'''

from numpy import *
"""arr=array([[1,2,3,4],[5,6,7,8]])
print(arr)
arr[0][0]=0
print(arr)
m=matrix(arr)
print(m)
m[0][0]=1
print(m)"""

global R,C
R=int(input('Enter number of rows: '))
C=int(input('Enter number of columns: '))

def setarr(lst):
    for r in range(0,R):
        tlist=[int(x) for x in input("Enter row number %d separated by space: "%r).split()]
        lst.append(tlist)

def getresult(lst):
    print('Resultant array is')
    print(lst)
        
lst1=[]
lst2=[]
print("Input array A")
setarr(lst1)
print("Input array B")
setarr(lst2)

M1=matrix(array(lst1))
M2=matrix(array(lst2))

c=int(input("\n1)A+B\n2)A-B\n3)A*B\n4)Transpose of A\n5)Transpose of B\nEnter choice no.: "))

if c==1:
    M3=M1+M2
    getresult(M3)
    
if c==2:
    M3=M1-M2
    getresult(M3)
    
if c==3:
    M3=M1*M2
    getresult(M3)
   
if c==4:
    M3=M1.transpose()
    getresult(M3)
    
if c==5:
    M3=M2.transpose()
    getresult(M3)