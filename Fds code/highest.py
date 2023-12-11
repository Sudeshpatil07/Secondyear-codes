# Number of Students
n = int(input("Enter the number of students in class: "))

#------------------------------------------------------------------------------

# Input of present students
present = int(input("Enter the students present for test: "))
absent = n - present

#------------------------------------------------------------------------------

# Input Marks of students
marks = []
print("Enter the marks of students: ")
for i in range(1, present+1):
    value = int(input())
    marks.append(value)
    i += 1
print("marks of students = ", marks)

#------------------------------------------------------------------------------

def average(a):
    total = 0
    for i in range(0, len(marks)):
        total = total + marks[i]
    b = total/len(marks)
    return b

def highest(a):
    highest = 0
    for i in a:
        if i > highest:
            highest = i
    return highest

def lowest(a):
    lowest = 999
    for i in a:
        if i < lowest:
            lowest = i
    return lowest

def freq(a):
    most_fe = None
    max_freq = 0
    for i in a:
        freq = a.count(i)
        if freq > max_freq:
            max_freq = freq
            most_fe = i
    return most_fe

#------------------------------------------------------------------------------

# menu
i = 1
while i == 1:
    print("\n\n---------------------MENU---------------------")
    print("1. The Average score of Class ")
    print("2. Highest Score and Lowest Score of Class ")
    print("3. Count of students who were absent for the test ")
    print("4. Display mark with highest frequency ")
    print("5. Exit")

    choice = int(input("\nEnter your choice between 1 to 5: "))

    if choice == 1:
        print("\nAverage score of class = ", average(marks))
        a = input("\nDo you want to continue? y or n. ")
        if a == 'y':
            i = 1
        else:
            i = 0

    elif choice == 2:
        print("\nHighest score = ", highest(marks))
        print("\nLowest score = ", lowest(marks))
        a = input("\nDo you want to continue? y or n. ")
        if a == 'y':
            i = 1
        else:
            i = 0

    elif choice == 3:
        print("\nCount of students who were absent for the test = ", absent)
        a = input("\nDo you want to continue? y or n. ")
        if a == 'y':
            i = 1
        else:
            i = 0

    elif choice == 4:
        print("\nMark with highest frequency = ", freq(marks))
        a = input("\nDo you want to continue? y or n. ")
        if a == 'y':
            i = 1
        else:
            i = 0

    elif choice == 5:
        i = 0

    else:
        print("\nInvalid input, try again.\n")
        i = 1

i = 0