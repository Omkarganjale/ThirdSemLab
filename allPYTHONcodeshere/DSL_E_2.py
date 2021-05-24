'''
Created on 18-Aug-2020

@author: omkar
'''


class opera:

    #lstr    =>string
    #clst=[] =>list of words in lstr
    
    def __init__(self,str):
        self.lstr=str
        lst = []           #temporary list
        f = 0
        ss = ""
        for i in range (0, len(self.lstr)):
            if self.lstr[i] == " " :
                f = 0
            else:
                f = 1

            if f == 0:
                lst.append(ss)
                ss = ""
        # elif f==0 and i==lstr[len(lstr)-1]:
        #   lst.append(ss+i)
            if f == 1:
                if i == len(self.lstr) - 1:
                    lst.append(ss + self.lstr[i]) 
                else:            
                    ss = ss + self.lstr[i]
        
        self.clst=lst[:] 


    def rlongestword(self):
        ml = 0
        for ss in self.clst:
            if len(ss) > ml:
                lw = ss
                ml=len(ss)
        return lw

    
    def rcharcount(self,ch):
        cnt = 0
        for w in self.clst:
            for c in w:
                if c == ch:
                    cnt = cnt + 1
        return cnt


    def isp(self):
        if self.lstr[::1]==self.lstr[::-1]:
            f=True
        else:
            f=False
        return f


    def indxofsubstr(self,sstr):
        r=-1
        for i in self.lstr:
            if i == sstr[0]:
                if self.lstr[i + 1:i+len(sstr)] == sstr[1:]:
                    r = i
        return r


    def cntr(self,ss):
        cnt = 0
        for i in self.clst:
            if i == ss:
                cnt += 1
        return cnt
    
    def wordcntr(self):
        lw=[]
        lf=[]
        for word in self.clst:
            if word in lw:
                lf[lw.index(word)]+=1
            else:
                lw.append(word)
                lf.append(1)
        print('Frequency of words is as follows: ')
        i=0
        for word in lw:
            print(word,"-",lf[i])
            i+=1         
   
sstr = input("Enter the string to be analyzed: ")
sobj=opera(sstr) 
uc = int(input("\n1)To display word with the longest length\n2)To determines the frequency of occurrence of particular character in the string\n3)To check whether given string is palindrome or not \n4)To display index of first appearance of the substring\n5)To count the occurrences of each word in a given string\nEnter your choice number: "))
if uc==1:
    print("longest word in given string is:",sobj.rlongestword())

if uc==2:
    c=input("Enter the character whose frequency is to be count: ")     
    print("character count of",c,"in given string is",sobj.rcharcount(c))

if uc==3:
    if sobj.isp:
        print("Given string is palindrome.")
    else:
        print("Given string is not a palindrome.")
        
if uc==4:
    sstr=input("Enter the substring: ")
    print("Index of given substring is",sobj.indxofsubstr(sstr))

if uc==5:
    sobj.wordcntr()   
#words = separator(sstr)

#print(words)
    
