# ----------
# User Instructions:
# 
# Create a function compute_value() which returns
# a grid of values. Value is defined as the minimum
# number of moves required to get from a cell to the
# goal. 
#
# If it is impossible to reach the goal from a cell
# you should assign that cell a value of 99.

# ----------

grid = [[0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0]]

init = [0, 0]
goal = [len(grid)-1, len(grid[0])-1]

delta = [[-1, 0 ], # go up
         [ 0, -1], # go left
         [ 1, 0 ], # go down
         [ 0, 1 ]] # go right

delta_name = ['^', '<', 'v', '>']

cost_step = 1 # the cost associated with moving from a cell to an adjacent one.

# ----------------------------------------
# insert code below
# ----------------------------------------

def compute_value():
    value =[[99 for row in range(len(grid[0]))] for col in range(len(grid))]
    policy = [[' ' for row in range(len(grid[0]))] for col in range(len(grid))]

    change = True
    while change:
        change=False

        for x in range(len(grid)):
            for y in range(len(grid[0])):

                if goal[0] == x and goal[1] ==y:
                    if value[x][y] >0:
                        value[x][y]=0
                        policy[x][y]= '*'
                        change = True
                elif grid[x][y]==0:
                    for a in range(len(delta)):

                        v2 = cost_step;
                        for i in range(-1, 2):
                            a2 = (a+i)%len(delta)
                            x2 = x + delta[a2][0]
                            y2 = y + delta[a2][1]
                            if i ==0:
                                p2 = sucess_prob
                            else:
                                p2 = (1- success_prob)/2.0
                            if x2 >=0 and x2 < len(grid) and y2 >= 0 and y2 <len(grid[0]) and grid[x2][y2]==0:
                                v2 += p2*value[x2][y2]
                            else:
                                v2 += p2*collision_cost

                         if v2 <value[x][y]:
                             change = True
                             value[x][y] = v2
                             policy[x][y] = delta_name[a]
    for i in range(len(value)):
        print value[i]

    return value

compute_value()
