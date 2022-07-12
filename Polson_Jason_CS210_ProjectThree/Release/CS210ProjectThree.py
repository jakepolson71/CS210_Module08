#Module 7
#Project 3
#Assignment 7-1
#Jason Polson
#SNHU
#June, 2022

#Chada Tech Grocery Tracking Program for Corner Grocer

#CS210ProjectThree.py




import re
import string

## Procedure for selection 1, to list the number of times each item was sold in a single day.
def ItemCount():
    groceryItemList = open("Project3_GroceryList.txt").read().splitlines()        
    
    itemsAndCount={} ## create a dictionary to hold the items and their total count
    for i in groceryItemList:       ## start a for loop for every line in the list
        if(i not in itemsAndCount):     ## check the dictionary to see if the item is already there - if not - count it as 1
            itemsAndCount[i] = 1 
        else:                           ## if the item is in the dictionary already - add 1 to its count 
            itemsAndCount[i] += 1 
    
    for i in itemsAndCount:
        print ("Customers purchased", i, itemsAndCount[i], "times today.")


                                        
## Procedure for selection two - which gets the number of times a specific item is sold in one day
def ItemFrequency(itemName):
    groceryItemList = open("Project3_GroceryList.txt").read().splitlines()

    numItems = 0    ## set a variable to count the items and return back

    ## for loop to read through the list and count the requested item
    for item in groceryItemList:
        if item == itemName:
            numItems += 1
    
    return numItems     ## return value to C++ code
 

    
## Procedure to write the Python .dat file to be read on the C++ side to create the histogram
def GetPythonHistoData():

    ## read everything into the groceryItemList
    groceryItemList = open("Project3_GroceryList.txt").read().splitlines()

    ## create a dictionary to hold data for the .dat file
    histoFrequency = {}

    for i in groceryItemList:       ## start a for loop for every line in the list
        if(i not in histoFrequency):     ## check the dictionary to see if the item is already there - if not - count it as 1
            histoFrequency[i] = 1 
        else:                           ## if the item is in the dictionary already - add 1 to its count 
            histoFrequency[i] += 1 
    
    ## write data to the frequency.dat file, creating it if necessary
    with open("frequency.dat", "w+") as freqDatFile:
        for key, value in histoFrequency.items():
            freqDatFile.write("%s %s \n" % (key, value))        ## this leaves a newline at the end of the file, so gotta fix it
    
    with open("frequency.dat") as readIn:       ## use this to read and then strip out the newline
        lastLine = readIn.read().rstrip("\n")   

    
    with open("frequency.dat", "w") as readOut:     ## now write the data back to the file minus the newline
        readOut.write(lastLine)
   
