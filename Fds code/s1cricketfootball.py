#Removing dupicates
def removeduplicate(d):
  list = []
  for i in d:
    if i not in list :
      list.append(i)
  return list



#Function for Describing intersection
def intersection(lst1, lst2):
  lst3 = []
  for val in lst1:
    if val in lst2:
      lst3.append(val)
  return lst3

#Defining union
def union(lst1, lst2):
  lst3 = lst1.copy()
  for val in lst2:
    if val not in lst3:
      lst3.append(val)
  return lst3

#Defining difference
def diff(lst1, lst2):
  lst3 = []
  for val in lst1:
    if val not in lst2:
      lst3.append(val)
  return(lst3)

#Defining symmetric difference
def sym_diff(lst1, lst2):
  D1 = diff(lst1, lst2)
  D2 = diff(lst2, lst1)
  lst3 = union(D1, D2)
  return lst3


#Defining intersections of cricket and badminton
def CB(lst1, lst2):
  lst3 = intersection(lst1, lst2)
  print("List of students who play cricket and badminton: ",lst3)
  return len(lst3)

#Defining sym_diff of cricket and badminton
def eCeB(lst1, lst2):
  lst3 = sym_diff(lst1, lst2)
  print("List of students who play either cricket or badminton: ",lst3)
  return len(lst3)

#Defining neither cricket nor badminton
def nCnB(lst1, lst2, lst3):
  u = union(lst2, lst3)
  lst4 = diff(lst1,u)
  return lst4

#Defining cricket, football but not badminton
def CFnB(lst1, lst2, lst3):
  un = union(lst1, lst2)
  lst4 = diff(un, lst3)
  return lst4


SEComp = []
n = int(input("Enter number of Students in SE Computer: "))
print("Enter the name of" ,n, "students:")
for i in range(0,n):
  ele = input()
  SEComp.append(ele)
print("Name of students in SE Computer"+str(SEComp))


#CRICKET
cricket = []
n = int(input("Enter the number of students who play cricket: "))
print("Enter the name of" ,n, "students who play cricket: ")
for i in range(0, n):
  ele = input()
  cricket.append(ele)
print("Number of students who play cricket = "+str(cricket))
cricket = removeduplicate(cricket)
print("Number of students who play cricket without duplicate = "+str(cricket))


#BADMINTON
badminton = []
n = int(input("Enter the number of students who play badminton: "))
print("Enter the name of" ,n, "students who play badminton: ")
for i in range(0, n):
  ele = input()
  badminton.append(ele)
print("Number of students who play badminton = "+str(badminton))
badminton = removeduplicate(badminton)
print("Number of students who play badminton without duplicate = "+str(badminton))


#FOOTBALL
football = []
n = int(input("Enter the number of students who play football: "))
print("Enter the name of" ,n, "students who play football: ")
for i in range(0, n):
  ele = input()
  football.append(ele)
print("Number of students who play football = "+str(football))
football = removeduplicate(football)
print("Number of students who play football without duplicate = "+str(football))


#Displaying Menu
i = 1
while i == 1:
    print("\n----------------MENU----------------\n")
    print("1. Number of students who play both cricket and badminton ")
    print("2. Number of students who play either cricket or badminton but not both ")
    print("3. Number of students who play neither cricket nor badminton ")
    print("4. Number of students who play cricket and football but not badminton ")
    print("5. Exit\n")
    choice = int(input("Enter your choice between 1 to 5 : "))
#choice 1
    if choice == 1:
      print("Number of students who play cricket and badminton", CB(cricket, badminton))
      a = input("Do you want to continue(y/n)=")
      if a == "y":
        i = 1
      else:
        i = 0
#choice 2
    elif choice == 2:
      print("Number of students who play either cricket or badminton but not both", eCeB(cricket, badminton))
      a = input("Do you want to continue(y/n)=")
      if a == "y":
        i = 1
      else:
        i = 0

#choice 3
    elif choice == 3:
      print("Number of students who play neither cricket nor badminton", nCnB(SEComp, cricket, badminton))
      a = input("Do you want to continue(y/n)=")
      if a == "y":
        i = 1
      else:
        i = 0

#choice 4
    elif choice == 4:
      print("Number of students who play cricket and football but not badminton", CFnB(cricket, football, badminton))
      a = input("Do you want to continue(y/n)=")
      if a == "y":
        i = 1
      else:
        i = 0

#choice 5
    elif choice == 5:
      i = 0

#INVALID INPUT
    else:
      print("INVALID INPUT")

