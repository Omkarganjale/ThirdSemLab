'''
Created on 11-Aug-2020

@author: omkar
'''

lst = []
class student:
    def __init__(self, n, r, p):
        self.name = n
        self.roll = r
        self.phone = p

print("\nAfter entering every student's details enter 00 in name to terminate")
while(True):
    n = input("\nEnter the name of student ")
    if n == "00":
        break;
    r = input("\nEnter the roll no. of student ")
    p = input("\nEnter the phone no. of student ")
    so = student(n, r, p)
    lst.append(so)
for so in lst:
    print("name:", so.name, "roll no:", so.roll, "phone no:", so.phone)

