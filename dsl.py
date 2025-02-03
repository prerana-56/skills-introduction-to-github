'''Write a python program to store second year percentage of students in array. Write
function for sorting array of floating point numbers in ascending order using
a) Insertion sort
b) Shell Sort and display top five scores '''
percentages = [98.99, 70.04, 15.05, 55.6, 77.00, 23, 91, 93.4]
def insertion_sort(arr):
    for i in range(len(arr)):
        key = i
        j = i -1
        while j >= 0:
            if arr[key] < arr[j]:
                temp = arr[key]
                arr[key] = arr[j]
                arr[key-1] = temp
            else:
                break
        key = key-1
        j = j-1 
    return arr
def shell_sort(arr):
    n = len(arr)
    gap = n//2
    while gap > 0:
        for i in range(gap,n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j-gap] >temp:
                arr[j] = arr[j-gap]
                j -= gap
                arr[j] = temp
        gap //= 2
    return arr
print("Before sorting = ", percentages)
print("After insertion sort = " ,insertion_sort(percentages))
print("After shell sort = ", shell_sort(percentages))
print("5 maximum values are: ")
for i in range(1, 6):
    print(percentages[-i])