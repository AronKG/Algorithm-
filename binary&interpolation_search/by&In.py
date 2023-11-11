import random
import math 
arr = []  #Decaler dynamic array. 

array_size = int(input("Enter the size of the dynamic array between 1 to 1000: ")) #initial the size of array 

for i in range(array_size): #file an elements into the array from user 
    #t = input (f"enter a {i+1} number: ")
    t = random.randint(1,1000)
    cint = int(t)
    arr.append(cint) # 

print(arr) #print the array befor sortering 
arr.sort() #sortoring the array 
print(arr) #print the array after sortering 

target =int(input("Enter an elemnt to be searched: "))

def hybrid_search(arr, target): 
    left = 0                #initialze the left inex
    right = array_size-1

    while left <= right: 
        #Calculate the range for the interpolation 
        interpol_rang = arr[right] -arr[left]
        if interpol_rang == 0: 
            return -1 # Cannot interplate in this case  
        #Calculate an estimated position using interpulation 
        estimate = left + ((target - arr[left])/ interpol_rang )*(right -left)

        #Ensure that the estimate is within the array bounds 
        if estimate < left: 
            estimate = left 
        elif estimate > right: 
            estimate = right 
        
        #preform a binary searching from the estimate 
        midel = math.floor(estimate) 
        if arr[midel] == target:
            return midel #element fuounde at position 
        elif arr[midel] < target: 
            left = midel + 1
        else: 
            right = midel - 1 
        
    return -1 # Element not found 
result = hybrid_search(arr, target)

if result == -1: #check if the elemnte is found or not 
    print("Not found")
else: 
    print(f"The elemnt is at position: {result +1} and the value is {target}:")