flag=0

#Class student with public attributes string name, bool isc,bool isb, bool isf and some 
class student:
    scnt=0;
    def __init__(self,Pname,Pisc,Pisb,Pisf):
        self.name=Pname
        self.isc=Pisc
        self.isb=Pisb
        self.isf=Pisf

#function that converts Y to True and N to False
def strtobool(sstr):
    if sstr=="Y":
        return True
    if sstr=="N":
        return False
    else:
        print("\nYou messed up please try again")
        flag=1

# function that creates and store object into the list   
def createnstoreobj(name,isc,isb,isf):
    sobj=student(name,isc,isb,isf)
    scont.append(sobj)
    student.scnt=student.scnt+1

#main function

scont=[] #student object container
while True:
    choice=int(input("\nPlease choose one of the following options\n1)Create a student profile \n2)Search few students \n3)go to assignment results \nPlease enter your option here: "))
    
    if choice==1:
        tname=input("\nPlease enter the name of student: ").upper()
        #check the name in scontainer if already there then dont add
        flag=0
        for ob in scont:
            if ob.name==tname:
                flag=1;
                break;
        if flag==1:
            print("\nName already exists")
            continue;
        #getting sports details and storing into tcb,tbb and tfb
        tcs=input("\nDoes the above student play Cricket:(Y/N): ")
        tcb=strtobool(tcs)
        if flag==1:
            print("\nProfile not created please start from the beginning")
            continue
        tbs=input("\nDoes the above student play Badminton:(Y/N): ")
        tbb=strtobool(tbs)
        if flag==1:
            print("\nProfile not created please start from the beginning")
            continue
        tfs=input("\nDoes the above student play Football:(Y/N): ")
        tfb=strtobool(tfs)
        if flag==1:
            print("\nProfile not created please start from the beginning")
            continue
        #passing those details to createnstoreobj function
        createnstoreobj(tname,tcb,tbb,tfb)

    if choice==2:
        scount=0
        tcs=input("\nDoes the required student play Cricket:(Y/N): ")
        tcb=strtobool(tcs)
        if flag==1:
            continue
        tbs=input("\nDoes the required student play Badminton:(Y/N): ")
        tbb=strtobool(tbs)
        if flag==1:
            continue
        tfs=input("\nDoes the required student play Football:(Y/N): ")
        tfb=strtobool(tfs)
        if flag==1:
            continue
        for ob in scont:
            if tcb==ob.isc and tbb==ob.isb and tfb==ob.isf:
                print("\n",ob.name) 
                scount=scount+1
        print("\nShowing",scount,"out of",student.scnt)         
    
    if choice==3:
        c3=int(input("\nchoose one of the following and enter\n1)List of students who play both cricket and badminton \n2)List of students who play either cricket or badminton but not both \n3)Number of students who play neither cricket nor badminton \n4)Number of students who play cricket and football but not badminton. \n5)students playing no game at all \n6)students playing badminton or football but not cricket\n"))
        if c3==1:
            scount=0
            for ob in scont:
                if ob.isc==True and ob.isb==True:
                    print("\n",ob.name) 
                    scount=scount+1
            print("\nShowing",scount,"out of",student.scnt)
        if c3==2:
            scount=0
            for ob in scont:
                if (ob.isc==True or ob.isb==True) and not (ob.isc==True and ob.isb==True):
                    print("\n",ob.name) 
                    scount=scount+1
            print("\nShowing",scount,"out of",student.scnt)
        if c3==3:
            scount=0
            for ob in scont:
                if (ob.isc==False and ob.isb==False):
                    print("\n",ob.name) 
                    scount=scount+1
            print("\nShowing",scount,"out of",student.scnt)
        if c3==4:
            scount=0
            for ob in scont:
                if ob.isc==True and ob.isf==True and ob.isb==False:
                    print("\n",ob.name) 
                    scount=scount+1
            print("\nShowing",scount,"out of",student.scnt)
        if c3==5:
            scount=0
            for ob in scont:
                if ob.isc==False and ob.isf==False and ob.isb==False:
                    print("\n",ob.name) 
                    scount=scount+1
            print("\nShowing",scount,"out of",student.scnt)
        if c3==6:
            scount=0
            for ob in scont:
                if ob.isc==False and (ob.isf==True or ob.isb==tbb):
                    print("\n",ob.name) 
                    scount=scount+1
            print("\nShowing",scount,"out of",student.scnt)