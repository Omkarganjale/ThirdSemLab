def ans1:
    lst=[]
    class student:
        def __init__(self,n,r,p):
            name=n
            roll=r
            phone=p
    print("\nafter entering each student enter 00 in name to terminate")
    while(True):
        n=input("\nenter the name of student")
        if n="00":
            break
        r=input("\nenter the roll no. of student")
        p=input("\nenter the phone no. of student")
        so=student(n,r,p)
        lst.append(so)
    for(i=0;i<len(lst);i++)
        print("name",lst[i].name,"roll no",lst[i].roll,"phone no",lst[i].phone)

def ans2:
    print("enter 3 numbers separated by comma")
    a=int(input("\nEnter integer a"))
    b=int(input("\nEnter integer b"))
    c=int(input("\nEnter integer c"))
    if a>=b and a>=c:
        print("\na is greatest")
    if b>=a and b>=c:
        print("\nb is greatest")
    if c>=a and c>=b:
        print("\nc is greatest")
        
def ans3:
    str=input("enter the elements of list separated by comma")
    nn=str.split(',')
    choice=int(input("1)slicing\n2)appending\n3)insertion\n4)sum\n5)length of list\n6)min and max of list\n7)delete through index\n8)remove an element\n9)pop out first element"))
    if choice==1:
        m=int(input("\nmin range"))
        M=int(input("\nmax range"))
        print("\noriginal list ",nn,"\nsliced list",nn[m:M+1])
    if choice==2:
        i=int(input("\nEnter the integer to be appended"))
        print("\noriginal list ",nn,"\nnew list",nn.append(i))
    if choice==3:
        pos=int(input("\nenter position of new element"))
        i=int(input("\nenter element"))
        print("\noriginal list ",nn,"\nnew list",nn.insert(pos,i))
    if choice==4:
        print("\noriginal list ",nn,"\nsum of list",sum(nn))
    if choice==5:
        print("\noriginal list ",nn,"\nlength of list",len(nn))
    if choice==6:
        print("\noriginal list ",nn," min ",min(nn)," max ",max(nn))
    if choice==7:
        i=int(input("\nenter the index to be deleted"))
        print("\noriginal list ",nn,"\nnew list",del nn[i])
    if choice==8:
        i=int(input("\nenter the element to be removed"))
        print("\noriginal list ",nn,"\nnew list",nn.remove(i))
    if choice==9:
        print("\noriginal list ",nn,"\nnew list",nn.pop(0))

#main    
anschoice=int(input("\n1)answer1\n2)answer2\n3)answer3"))
if ansachoice==1:
    ans1
if anschoice==2:
    ans2
if anschoice==3:
    ans3