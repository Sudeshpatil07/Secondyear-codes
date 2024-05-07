#!/usr/bin/env python
# coding: utf-8

# # Implement Hash table in Python

# In[ ]:


import numpy as np
HT = np.zeros(10) #Initialize the hash table as zeros. Assumption that accept non zero keys only
print("Hash Table:\n",HT)


# ### Insert key into hash table - Linear Probing Without Replacement

# In[ ]:


for i in range(len(HT)):
    key = input("\nEnter key")
    ind = int(key) % 10
    #print(ind)
    if(HT[ind]==0):
        HT[ind] = key
    
    #Linear Probing without replacement
    else:             
        for j in range(len(HT)):
            ind = (int(key)+j) % 10
            if(HT[ind]==0):
                HT[ind] = key
                break
        #print("\nYou can not inset key")
            


# ### Pring Hash Table

# In[ ]:


print("Hash Table:\n",HT)


# ### Insert key into hash table - With Replacement

# In[ ]:


for i in range(len(HT)):
    key = input("\nEnter key")
    ind = int(key) % 10
    #print(ind)
    if(HT[ind]==0):
        HT[ind] = key
    
    #Linear Probing with replacement
    else:
        Occupied_key = HT[ind]
        home_add_Occupied_key = int(Occupied_key) % 10
        if(home_add_Occupied_key != ind):
            HT[ind] = key
            key = Occupied_key
            for j in range(len(HT)):
                ind = (int(key)+j) % 10
                if(HT[ind]==0):
                    HT[ind] = key
                    break
        else:
            for j in range(len(HT)):
                ind = (int(key)+j) % 10
                if(HT[ind]==0):
                    HT[ind] = key
                    break
                 


# ### Print Hash Table 

# In[ ]:


print("Hash Table:\n",HT)


# ### Quadratic Probing 

# In[ ]:


for i in range(len(HT)):
    key = input("\nEnter key")
    ind = int(key) % 10
    #print(ind)
    if(HT[ind]==0):
        HT[ind] = key
    
    #Quadratic Probing
    else:             
        for j in range(len(HT)):
            indn = (ind+(j*j)) % 10
            if(HT[indn]==0):
                HT[indn] = key
                break


# ### Print Hash Table 

# In[ ]:


print("Hash Table:\n",HT)


# # Main Program

# In[ ]:


def insert_record():
    for i in range(len(HT)):
        key = input("\nEnter key")
        ind = int(key) % 10
        #print(ind)
        if(HT[ind]==0):
            HT[ind] = key

        #Linear Probing without replacement
        else:             
            for j in range(len(HT)):
                ind = (int(key)+j) % 10
                if(HT[ind]==0):
                    HT[ind] = key
                    break


# In[ ]:


def display_record():
    print("Hash Table:\n",HT)


# In[ ]:


import numpy as np
HT = np.zeros(10) #Initialize the hash table as zeros. Assumption that accept non zero keys only
#print("Hash Table:\n",HT)

choice1 = 0
while(choice1 != 4):
    print("1. Insert              *")
    print("2. Search              *")
    print("3. Display             *")
    print("4. Exit                *")
    choice1 = int(input("Enter Choice"))
    if choice1>4:
        print("Please Enter Valid Choice")
    if(choice1==1):
        insert_record()
    elif(choice1==2):
        add = search_record()
        print("Key Address",add)
        #if(add != -1):
        #    print("Key found at location ",add)
        #else:
        #    print("Key not found ")
    elif(choice1==3):
        display_record()


# In[ ]:



