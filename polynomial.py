poly1 = [6, 5, 7, 3, 4, 0, 8]
poly2 = [3, 0, 9, 3]

def printPoly(arr):
    exp = len(arr) - 1
    for i in range(len(arr)):
        if (exp > 1):
            print(f"{arr[i]}x^{exp} + ", end="")
        elif (exp == 1):
            print(f"{arr[i]}x + ", end="")
        else:
            print(f"{arr[i]}")
        exp -= 1

def addPoly(arr1, arr2):
    a_diff: int;
    b_diff: int;
    max_size: int;

    diff = len(arr1) - len(arr2)
    if (diff > 0):
        a_diff = 0
        b_diff = diff
        max_size = len(arr1)
    else:
        a_diff = diff
        b_diff = 0
        max_size = len(arr2)

    result = []
    for i in range(max_size):
        a_index = i - a_diff
        b_index = i - b_diff
        a_value = 0 if a_index < 0 else arr1[a_index]
        b_value = 0 if b_index < 0 else arr2[b_index]
        result.append(a_value + b_value)
    return result

def subPoly(arr1, arr2):
    a_diff: int;
    b_diff: int;
    max_size: int;

    diff = len(arr1) - len(arr2)
    if (diff > 0):
        a_diff = 0
        b_diff = diff
        max_size = len(arr1)
    else:
        a_diff = diff
        b_diff = 0
        max_size = len(arr2)

    result = []
    for i in range(max_size):
        a_index = i - a_diff
        b_index = i - b_diff
        a_value = 0 if a_index < 0 else arr1[a_index]
        b_value = 0 if b_index < 0 else arr2[b_index]
        result.append(a_value - b_value)
    return result

def multiplePoly(arr, const):
    result = []
    for i in range(len(arr)):
        result.append(arr[i] * const)
    return result

addResult = addPoly(poly1, poly2)
subResult = subPoly(poly1, poly2)
multipleResult = multiplePoly(poly1, 3)

print("[poly1]")
printPoly(poly1)

print("[poly2]")
printPoly(poly2)

print("[poly1 + poly2]")
printPoly(addResult)

print("[poly1 - poly2]")
printPoly(subResult)

print("[poly1 * 3]")
printPoly(multipleResult)
