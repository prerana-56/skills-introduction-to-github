''' Write a Python program to store marks scored in subject “Fundamental of Data
Structure” by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency '''

def average(arr):
    sum = 0
    for i in arr:
        if i != "a":
            sum = sum + float(i)
    av = sum/(len(arr))
    return av
def highest(arr):
    highest = 0
    for i in arr:
        if i != "a" and float(i) > highest:
            highest = float(i)
    return highest
def lowest(arr):
    lowest = 100
    for i in arr:
        if i != "a" and float(i) < lowest:
            lowest = float(i)
    return lowest
def max_freq(arr):
    val = 0
    for i in arr:
        if marks.count(i) > val and i != "a":
            val = marks.count(i)
    return val
n = int(input("How many students are in the class? "))
marks = []
for i in range(1,n):
    a = input(f"Enter marks of student {i}: " )
    marks.append(a)
print("Average score of the class is: ", average(marks))
print("Highest Score is: ", highest(marks))
print("Lowest score is: ", lowest(marks))
print("Count of students who were absent for the test is: ", marks.count("a"))
print("Mark with the highest frequency: ", max_freq(marks))