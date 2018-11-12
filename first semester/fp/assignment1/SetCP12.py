# The numbers n1 and n2 have the property P if their writings in basis 10 have the same digits (e.g. 2113 and 323121). Determine whether two given natural numbers have the property P.
def pProperty(a,b):
    """
        This function checks if two numbers are formed with the same digits, using a frequency array.
        input: a,b natural numbers.
        output: True if they have the same digits, False otherwise.
    """
    apA=[] # frequency array for a
    apB=[] # frequency array for b
    stringA=str(a)
    stringB=str(b)
    for i in range(10):
        apA.append(0)   # Initializng both frequency arrays with 0 for every digit
        apB.append(0)
    for i in range(len(stringA)):
        apA[int(stringA[i])]+=1 # Every appearance of a digit increments the array of that digit by 1
    for j in range(len(stringB)):
        apB[int(stringB[j])]+=1
    for i in range(10):
        if (apA[i]==0 and apB[i]!=0) or (apA[i]!=0 and apB[i]==0): # If there is a digit that appears in one number but doesn't appear in the other the function returns False
            return False
    return True
a=int(input("give a "))
b=int(input("give b "))
if (a<0 or b<0):
    print("Invalid input.")
elif pProperty(a,b)==True:
    print(str(a)+" and "+str(b)+" have the P property.")
else:
    print(str(a)+" and "+str(b)+" don't have the P property.")    
