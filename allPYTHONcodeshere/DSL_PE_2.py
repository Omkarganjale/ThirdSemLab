'''
Created on 11-Aug-2020

@author: omkar
'''
def cnt (el,lst) :
    c=0
    for i in range (0,len(lst)):
        if lst[i]==el:
            c=c+1
    return c
#MAIN
lst=[]
while True:
    choice=int(input("\n1)Append marks \n2)Find total sum \n3)Find average\n4)Find min and max\n5)Count of absent students\n6)Find the highest frequency\n7)End program\nEnter your option: "))
    if choice==1:
        lst2=[int(x) for x in input("Enter the list of numbers separated by comma and enter -1 if absent ").split(',')]
        lst=lst+lst2
    if choice==2:
        sm=0
        for i in range (0,len(lst)):
            if lst[i]>0:
                sm=sm+lst[i]
        print("total sum is ",sm)
    if choice==3:
        sm=0
        for i in range (0,len(lst)):
            if lst[i]>0:
                sm=sm+lst[i]
            ln=len(lst)-cnt(-1,lst)
        print("average is",sm/ln)
    if choice==4:
        mn=lst[0]
        mx=lst[0]
        for i in range (0,len(lst)):
            if lst[i]<mn and lst[i]>=0:
                mn=lst[i]
            if lst[i]>mx and lst[i]>=0:
                mx=lst[i]
        print("max is",mx,"min is",mn)
    if choice==5:
        print("Total number of absent students are",cnt(-1,lst))
    if choice==6:
        mf=0
        mn=lst[0]
        mx=lst[0]
        for i in range (0,len(lst)):
            if lst[i]<mn and lst[i]>=0:
                mn=lst[i]
            if lst[i]>mx and lst[i]>=0:
                mx=lst[i]
        for i in range (mn,mx+1):
            if cnt(i,lst)>mf:
                mf=cnt(i,lst)
                mfe=lst[i]
        print("Marks",mfe,"has maximum frequency of",mf)
    if choice==7:
        break;   