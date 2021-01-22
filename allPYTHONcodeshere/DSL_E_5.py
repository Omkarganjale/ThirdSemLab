'''
Created on 15-Sep-2020

@author: omkar
'''



class sort:
    
    def __init__(self,marks,names):
        #member initialization of marks and names
        #@para-list of marks
        #@para-list of names
        
        #problem here
        self.marks=marks[:]
        self.omarks=marks[:]
        self.name=names
        
        
        
    def insertsort(self):
        # insertion sort is performed on marks
        # @para-unsorted marks
        
        for i in range (1, len(self.marks)):
            pen = self.marks[i]
            j = i - 1
            while j >= 0 and pen <= self.marks[j]:
                self.marks[j + 1] = self.marks[j]
                j -= 1
            self.marks[j + 1] = pen
        
    def shellsort(self):
        # perform shell sort on marks
        # @para-unsorted list marks
         
        gap=len(self.marks)//2
        while gap>=1:
            #cnt=1
            
            for g in range (0,gap):
                
                for i in range (g+gap,len(self.marks),gap):
                    
                    pen=self.marks[i]
                    j=i-gap
                    while j>=g and pen <= self.marks[j]:
                        self.marks[j+gap]=self.marks[j]
                        j -= gap
                    self.marks[j+gap]=pen
                    
                #print("pass:",cnt,"gap:",gap,",list:",self.marks)
                    
            gap=gap//2        

    def printobj(self):
        for i in range (0,len(self.marks)):
            print("\nName: ",self.name[self.omarks.index(self.marks[i])],"\nMarks: ",self.marks[i])
       
# main function    
while True:

    ch = int(input("\n1)Initialize the student details\n2)Append few details\n3)Display list\n4)Perform sorting on list\n5)Display top 5 students\n6)Quit\nEnter choice number: "))

    if ch == 1:
        names = []
        marks = []
    
        print("\nEnter student details and enter -1 in name to exit")
        while True:
            name = input("Enter name: ")
            if name == "-1":
                break
            mark = int(input("Enter mark: "))
            names.append(name)
            marks.append(mark)
        
        obj = sort(marks, names)
 
    if ch == 2:
        print("\nEnter student details and enter -1 in name to exit")
        while True:
            name = input("Enter name: ")
            if name == "-1":
                break
            mark = int(input("Enter mark: "))
            obj.name.append(name)
            obj.marks.append(mark) 
            obj.omarks.append(mark) 
 
    if ch == 3:
        obj.printobj() 

    if ch == 4:
        ch4=int(input("1)Insertion sort\n2)Shell sort\nEnter choice number: "))
        if ch4==1:
            obj.insertsort()
            print("\nInsertion sort was successfull!!")
        if ch4==2:
            obj.shellsort()
            print("\nShell sort was successfull!!")
    
    if ch==5:
        #top 5 students
        for i in range (len(obj.marks)-5,len(obj.marks)):
            print("\nName: ",obj.name[obj.omarks.index(obj.marks[i])],"\nMarks: ",obj.marks[i])
       
        
        
    if ch==6:
        break
            