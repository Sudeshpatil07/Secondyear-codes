#!/usr/bin/env python
# coding: utf-8

# # Set Operations

# ### Create Set

# In[1]:


n = int(input('Enter Number of elements in Set'))
setA = set()
for i in range(n):
    e = int(input('Enter Element to add'))
    setA.add(e)
print(setA)


# ### Insert element in Set

# In[2]:


e = int(input('Enter Element to add'))
setA.add(e)
print(setA)


# ### Remove element from Set 

# In[3]:


e = int(input('Enter Element to remove'))
setA.remove(e)
print(setA)


# ### Search element form Set 

# In[5]:


e = int(input('Enter Element to search'))
if e in setA:
    print('Element is in set')
else:
    print('Element is not in set')


# ### Get size of Set 

# In[6]:


print(len(setA))


# ## Union, Intersection, Difference, Subset of Sets 

# ### Get Set-A 

# In[7]:


n = int(input('Enter Number of elements in Set'))
setA = set()
for i in range(n):
    e = int(input('Enter Element to add'))
    setA.add(e)
print(setA)


# ### Get Set-B 

# In[8]:


n = int(input('Enter Number of elements in Set'))
setB = set()
for i in range(n):
    e = int(input('Enter Element to add'))
    setB.add(e)
print(setB)


# ### Union using python function 

# In[9]:


setC = setA.union(setB)
print(setC)


# ### Intersection using python function 

# In[11]:


setC = setA.intersection(setB)
print(setC)


# ### Difference using python function (A-B)

# In[12]:


setC = setA.difference(setB)
print(setC)


# ### Difference using python function (B-A) 

# In[13]:


setC = setB.difference(setA)
print(setC)


# ### Identify subset using python function 

# In[14]:


print(setA.issubset(setB))


# In[ ]:




