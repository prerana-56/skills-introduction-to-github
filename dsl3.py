''' Write a pythonprogram to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores. '''

percentages = [98.99, 70.04, 15.05, 55.6, 77.00, 23, 91, 93.4]
def selection_sort(arr):
    for i in range(len(arr)):
        min = i
        for j in range(i+1,len(arr)):
            if arr[j]< arr[min]:
                min = j
        temp = arr[i]
        arr[i] = arr[min]
        arr[min] = temp
    return arr
def bubble_sort(a):
    for i in range(len(a)):
        bubble = 0
        for j in range(1, len(a)- i):
            if a[bubble] > a[j]:
                temp = a[bubble]
                a[bubble] = a[j]
                a[j] = temp
                bubble = j
            else:
                bubble = j
    return a
print("bubble sort = " ,bubble_sort(percentages))
print("selection sort = ", selection_sort(percentages))
print("5 maximum values are: ")
for i in range(1, 6):
    print(percentages[-i])