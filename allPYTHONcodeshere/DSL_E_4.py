'''
Created on 05-Sep-2020

@author: omkar
'''

#Function Definition

def linear(lst,n):
    #linear search algorithm
    #@para-lst:unsorted or sorted list to be searched
    #@para-n:element to be searched
    #@return:index+1 of n in list or False
    
    for i in range (0,len(lst)):
        if i<len(lst) and lst[i]==n:
            return i+1
            break
    else:
        return False
          
def sentinel(lst,n):
    #sentinel search algorithm
    #@para-lst:unsorted or sorted list to be searched
    #@para-n:element to be searched
    #return:index+1 of n in list or False
    
    lst.append(n)
    i=0
    ind=len(lst)-1
    while lst[i]!=n:
        if lst[i]==n:
            ind=i
            break
        i+=1
    if ind == len(lst)-1:
        return False
    else:
        return ind+1 
               
def binary(lst,n):
    #binary search algorithm
    #@para-lst:sorted list to be searched
    #@para-n:element to be searched
    #return:index+1 of n in list or False
    
    flag=False
    halflist=[]
    for i in range (0,len(lst)):
        halflist.append([i,lst[i]])
        
    while len(halflist)>=1:
        tin=(len(halflist))//2
        mid = halflist[tin][1]
        if mid==n:
            r=halflist[tin][0]
            flag=True
            break
        elif mid<n:
            del halflist[:tin+1]
            
        else:#elif mid>n:
            del halflist[tin:]
            
    if flag==True :
        return r+1
    else:
        return False        

def fib(n):
    #returns fibonacci number 
    #@para-n: sequence number of fibonacci sequence
    #return: fibonacci number at n
    
    a = 0
    b = 1
    if n < 0: 
        print("Incorrect input") 
    elif n == 0: 
        return a 
    elif n == 1: 
        return b 
    else: 
        for i in range(2,n+1): 
            c = a + b 
            a = b 
            b = c 
        return b

def fibonacci(lst,n):
    #fibonacci search algorithm
    #@para-lst:sorted list to be searched
    #@para-n:element to be searched
    #return:index+1 of n or False
    
    #lst.insert(0,"NA")  #since we consider array to start from 1 for simplicity
    i=0
    m=0
    l=len(lst)
    while(m<=l):
        m=fib(i)
        i=i+1
    #here m is Fib_m and i-1 is sequence no of Fib_m
                        #Fib_m2 - Fib_m1 - Fib_m
    o=0                 #initial offset is 0
    m1=fib(i-2)         #initial Fib_m1=fib(i-2)
    m2=fib(i-3)         #initial Fib_m2=fib(i-3)
    i=i-3               #i is same as seq no. of m2
    flag=False          #flag=False means n is not found yet
    while(m1>=1 and m2>=1 and flag==False):
        fish=min(o+m2,n)
        if lst[fish]==n:
            R=fish
            flag=True
            break
        elif lst[fish]<n:    #move 1 down and reset offset
            m=m1
            m1=m2
            m2=fib(i-1)
            i=i-1            #updating index i of m2
            o=fish
        elif lst[fish]>n:    #move 2 down 
            m=m2
            m1=fib(i-1)
            m2=fib(i-2)
            i=i-2            #updating index i of m2
    if flag==True:
        return R+1 
    else:
        return False   
        
#Main function
lst=list(map(int,input("Enter space separated sorted elements: ").split()))
while True:
    el=int(input("Element to be searched: "))
    ch=int(input("1)LINEAR SEARCH\n2)SENTINEL SEARCH\n3)BINARY SEARCH\n4)FIBONACCI SEARCH\n5)EXIT\nEnter choice number: "))               
    if ch==1:
        if(linear(lst,el)!=False):
            print("position of",el,"is",linear(lst,el),"\n")
        else:
            print(el,"is not present in given list\n")
    if ch==2:
        if(sentinel(lst,el)!=False):
            print("position of",el,"is",sentinel(lst,el),"\n")
        else:
            print(el,"is not present in given list\n")
    if ch==3:
        if(binary(lst,el)!=False):
            print("position of",el,"is",binary(lst,el),"\n")
        else:
            print(el,"is not present in given list\n")
    if ch==4:
        if(fibonacci(lst,el)!=False):
            print("position of",el,"is",fibonacci(lst,el),"\n")
        else:
            print(el,"is not present in given list\n")
    if ch==5:
        break