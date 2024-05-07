def Linear_hashing():
    HT = []
    n = int(input("Enter the size of table do u want :"))
    for i in range(0,n):
        HT.append(0)
    print("HI is :",HT)
    for i in range (len(HT)):
        key = input("\n Enter the key ")
        index = int(key) % n
        if(HT[index]==0):
            HT[index]=key
        else:
                for j in range(len(HT)):
                    index=(int(key)+j)%n
                    if(HT[index]==0):
                        HT[index] = key
                        break
    print("Hash table given as:",  HT)
    HT.clear()
    menu()


def Quadratic_hashing():
    HT = []
    n = int(input("Enter the size of table do u want :"))
    for i in range(0,n):
        HT.append(0)
    print("HI is :",HT)
    for i in range(len(HT)):
        key = input("\n Enter the key ")
        index = int(key) % n


        if(HT[index]==0):
                HT[index]=key
        else:
                for j in range(len(HT)):
                        index=(int(key)+j**2)%n
                        if(HT[index]==0):
                                HT[index] = key
                                break
    print("Hash table given as:",  HT)
    HT.clear()
    menu()






def menu():
    ch=int(input("Enter your choice: "))
   
    if ch==1:
        Linear_hashing()


    elif ch==2:
        Quadratic_hashing()


    elif ch==3:
        exit()


    else:
        print("Enter valid choice.")
   
menu()