''' In second year computer engineering class, group A student’s play cricket, group B
students play badminton and group C students play football.
Write a Python program using functions to compute following: -
a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not both
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not badminton.
(Note- While realizing the group, duplicate entries should be avoided, Do not use SET
built-in functions)  '''
def intersection(list1, list2):
    list3 = []
    for i in list1:
        if i in list2 and i not in list3:
            list3.append(i)
            return list3
def union(list1, list2):
    list3 = []
    for i in list1:
        if i not in list3:
            list3.append(i)
            for j in list2:
                if j not in list3:
                    list3.append(j)
    return list3
def subtraction(list1, list2):
    list3 = []
    for i in list1:
        if i not in list2 and i not in list3:
            list3.append(i)
    return list3
if __name__ == "__main__":
    cricket = []
    football = []
    badminton = []
    n = int(input("How many students are there? "))
    for i in range(n):
        student = input(f"Enter name of student {i+ 1}: ")
        sports = input( "Which sports does the student play? ")
        sports = sports.split(",")
    for sport in sports:
        match(sport.strip()):
            case "cricket":
                cricket.append(student)
            case "badminton":
                badminton.append(student)
            case "football":
                football.append(student)
    print("Cricket Players: ", cricket)
    print("Badminton Players: " , badminton)
    print("Football Players: ", football)
    a = union(cricket, badminton)
    b = intersection(cricket, badminton)
    c = intersection(football, cricket)
    print("List of students who play both cricket and badminton:", b)
    print("List of students who play either cricket or badminton but not both: ", subtraction(a, b))
    print("Number of students who play neither cricket nor badminton: ", len(subtraction(football, a)))
    print("Number of students who play cricket and football but not badminton: ", len(subtraction(c, badminton)))