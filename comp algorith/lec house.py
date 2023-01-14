
################################################################################


N = 6

houses = [[7, 6, 7, 8, 9, 20],
          [3, 8, 9, 22, 12, 8],
          [16, 10, 4, 2, 5, 7]]


cost = [[0] * N,
        [0] * N,
        [0] * N]



cost[0][0] = houses[0][0]
cost[1][0] = houses[1][0]
cost[2][0] = houses[2][0]

for i in range(1, N):
    # the min cost to paint the first i houses, with the i-th being painted red
    cost[0][i] = houses[0][i] + min(cost[1][i-1], cost[2][i-1])

    # the min cost to paint the first i houses, with the i-th being painted green
    cost[1][i] = houses[1][i] + min(cost[0][i-1], cost[2][i-1])

    # the min cost to paint the first i houses, with the i-th being painted blue
    cost[2][i] = houses[2][i] + min(cost[0][i-1], cost[1][i-1])

min(cost[0][5], cost[1][5], cost[2][5])

cols = [0] * N
i = N-1
if cost[0][N-1] <= min(cost[1][N-1], cost[2][N-1]):
    cols[N-1] = 0
elif cost[1][N-1] <= min(cost[0][N-1], cost[2][N-1]):
    cols[N-1] = 1
else:
    cols[N-1] = 2

for i in range(N-2, -1, -1):
    cur_min = 10000
    cur_min_col = -1
    for col in [0, 1, 2]:
        if col == cols[i+1]:
            continue
        if cost[col][i] < cur_min:
            cur_min = cost[col][i]
            cur_min_col = col
    cols[i] = cur_min_col


def paint_house_cost(houses, col, i):
    '''Return the cost of painting houses
    0, 1, 2, ,,, i, with the i-th houses painted col
    and the total cost minimized'''
    if i == 0:
        return houses[col][i]

    cur_min = 1000000
    cur_min_col = -1
    for color in [0, 1, 2]:
        if color == col:
            continue
        cost_color_i = paint_house_cost(houses, color, i-1)
        if cost_color_i < cur_min:
            cur_min = cost_color_i
            cur_min_col = color
    return houses[col][i] + cur_min