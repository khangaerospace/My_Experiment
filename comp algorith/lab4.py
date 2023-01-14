def findlowest(L,e):
    current_index = L[0]
    for i in range(len(L)):
        if current_index >= L[i]:
            current_index = L[i]

    #print(current_index)
    if current_index == e:

        return current_index
    else:
        return -1

def findhigest(L,e):
    current_index = L[0]
    for i in range(len(L)):
        if current_index <= L[i]:
            current_index = L[i]

    if current_index == e:
        return current_index
    else:
        return -1



if __name__ == '__main__':
     L = [1,2,3,4,5,6,7,8,8]
     e1 = 1
     e2 = 3
     e3 = 8
     e4 = 5
     print(findlowest(L,e1))
     print(findlowest(L,e2))
     print(findhigest(L,e3))
     print(findhigest(L,e4))