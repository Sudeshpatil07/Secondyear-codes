S1={"2","4","6","5","9"}


S2={"4","7","8","3","9"}




def mainmenu():
        print("\n*******MENU*******")
        print("1.Insert element into Set")
        print("2.Delete element from Set")
        print("3.Display elements")
        print("4.Count Set Elements")
        print("5.Union of Set Elements")
        print("6.Intersetion of Set Elements")
        print("7.Difference of Set Elements")
        print("8.EXIT")
        
        
        
        ch=int(input("\nEnter your Choice :"))
        
        if ch==1:
                print("\nInsertion of elements into Sets :")
                S1.add(int(input("Enter the element to be inserted in S1  :")))
                S2.add(int(input("Enter the element to be inserted in S2  :")))
                
                print("Elements added..")
                mainmenu()
                
        elif ch==2:
                print("\nElements is Deleted :")
                S1.remove(int(input("Enter the element to be deleted in S1  :")))
                S2.remove(int(input("Enter the element to be deleted in S2  :")))
                
                print("Elements Deleted..")
                mainmenu()
                
        elif ch==3:
                print("\nThe Sets are :")
                print (S1)
                print (S2)
                
                print("\n***********//\\***********")
                mainmenu()
                
        elif ch==4:
                print("The Count is :")
                print (len(S1))
                print (len(S2))        
                print("***********//\\***********")
                mainmenu()
        
        elif ch==5:
                print("\nThe Union of Set is :")
                print(S1 | S2)
                
                print("***********//\\***********")
                
                mainmenu()
        
        elif ch==6:
                print("\nThe Intersection of set is :")
                print(S1 & S2)
                
                print("***********//\\***********")
                mainmenu()
        
        elif ch==7:
                print("\nThe Difference of Set is :")        
                print(S1 - S2)
                
                print("***********//\\***********")
                mainmenu()
        
        elif ch==8:
                print("\nThank you 🙂️ for using our program!!! ")
                print("***********//\\***********")
                exit
                                
        else:
                print("Enter the valid choice :")
                print("***********//\\***********")
                mainmenu()
                                
mainmenu()