rows = int(input("Enter number of rows in matrix: "))
columns = int(input("Enter number of columns in matrix: "))

m1 = []

print("\nEnter elements of matrix 1")
for i in range(rows):
    row = []
    for j in range(columns):
        ele = int(input())
        row.append(ele)
    m1.append(row)

print("\nMatrix 1 = ")
for row in m1:
    print(row)

m2 = []

print("\nEnter elements of matrix 2")
for i in range(rows):
    row = []
    for j in range(columns):
        ele = int(input())
        row.append(ele)
    m2.append(row)

print("\nMatrix 2 = ")
for row in m2:
    print(row)

add = []

for i in range(rows):
    row = []
    for j in range(columns):
        a = m1[i][j] + m2[i][j]
        row.append(a)
    add.append(row)

print("\nAddition of m1 and m2 = ")
for row in add:
    print(row)

sub = []

for i in range(rows):
    row = []
    for j in range(columns):
        a = m1[i][j] - m2[i][j]
        row.append(a)
    sub.append(row)

print("\nSubstraction of m1 and m2 = ")
for row in sub:
    print(row)

mul = []

for i in range(rows):
    row = []
    for j in range(columns):
        a = 0
        for k in range(columns):
            a = a + m1[i][k] * m2[k][j]
        row.append(a)
    mul.append(row)

print("\nMultiplication of m1 and m2 = ")
for row in mul:
    print(row)

t1 = []

for j in range(columns):
    row = []
    for i in range(rows):
        row.append(m1[i][j])
    t1.append(row)

print("\nTranspose of matrix m1 = ")
for row in t1:
    print(row)

t2 = []

for j in range(columns):
    row = []
    for i in range(rows):
        row.append(m2[i][j])
    t2.append(row)

print("\nTranspose of matrix m2 = ")
for row in t2:
    print(row)