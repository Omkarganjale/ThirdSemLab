'''
Created on 22-Sep-2020

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
        


    def quick(self,a,z):
    #performs quick sort on given lst
    #@para-unsorted list
    #@para-(a,z)-index range of sorting  
    
        def swap(self,pos1,pos2):
        #swap given positions in lst
        #@para-pos1,pos2-positions to be swapped
    
            temp=self.marks[pos1]
            self.marks[pos1]=self.marks[pos2]
            self.marks[pos2]=temp
    
        j=z
        i=a
        P=self.marks[a]    #pivot is the first element
        print("a:",a,",z:",z)
        #if a>=z and a-z==3:
            #return
        while True:
            
            while True:
                i+=1 
                if self.marks[i]>P and i<z:
                    break
                
            while True:
                j-=1
                if self.marks[j]<P and j>a:
                    break
                
            if j<i:
                break
           
            swap(i,j)
            print(".",self.marks[a:z+1])
        
        #swap pivot and lst[j]
        swap(a,j)
        print("..",self.marks[a:z+1])
        # j is new index of pivot point
        
        self.quick(a,j)   #left of pivot
        self.quick(j,z)   #right of pivot
    
    def printobj(self):
        for i in range (0,len(self.marks)):
            print("\nName: ",self.name[self.omarks.index(self.marks[i])],"\nMarks: ",self.marks[i])
    
    def size(self):
        return len(self.omarks)
       
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
        
        obj.quick(0,obj.size())
        
        
        print("\nQuick sort was successfull!!")
    
    if ch==5:
        #top 5 students
        for i in range (len(obj.marks)-5,len(obj.marks)):
            print("\nName: ",obj.name[obj.omarks.index(obj.marks[i])],"\nMarks: ",obj.marks[i])
       
        
        
    if ch==6:
        break

    
"""#main function
hut=[4,2,1,6,7]
quick(hut,0,len(hut)-1)
print(hut)"""