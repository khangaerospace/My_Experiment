def min_eng(list):
    returnlist = []
    nn = 0
    h = len(list)
    k = 0
    list2 = list
    for i in range(len(list2)):
        now = list2[i][nn]

        for v in range(nn,h):
            if now >= list[i][v]:
                now =  list[i][v]
                n = v
        #print(v)
        returnlist.append(now)
        #print(now)
        nn = n -1
        h = n+2
        #print(nn,"   ",h)
        #print(list[i])
    sum = 0
    for i in range(len(returnlist)):
        print(returnlist[i])
        sum = sum + returnlist[i]
    print(sum)

if __name__ == '__main__':
    energies = [[24,      22,      30,      15,      18,      19], [12,      23,      15,      23,      10,     15], [11,      13,      22,      13,      21,      14], [13,      15,      17,      28,      19,      21], [17,      17,      7,       27,      20,      19]]
    min_eng(energies)
