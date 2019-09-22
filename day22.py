
weapons = [(4,8), (5,10), (6,25), (7,40), (8,74)]
armors = [(0,0), (1,13), (2,31), (3,53), (4,75), (5,102)]
rings = [(0,0,0), (0,0,0), (1,0,25), (2,0,50), (3,0,100), (0,1,20), (0,2,40), (0,3,80)]

def playerWin(PlayerDam, PlayerArm):
    PlayerHP = 100

    EnemyHP = 109
    EnemyDam = 8
    EnemyArm = 2

    while PlayerHP > 0:
        EnemyHP -= PlayerDam - EnemyArm
        if EnemyHP <= 0:
            return 1
        PlayerHP -= EnemyDam - PlayerArm
    return 0


lowest_cost = 999999
highest_cost = 0

for weapon in weapons:
    for armor in armors:
        for i in range(len(rings)):
            for j in range(len(rings)):
                if i != j:
                    dam = weapon[0] + rings[i][0] + rings[j][0]
                    arm = armor[0] + rings[i][1] + rings[j][1]
                    cost = weapon[1] + armor[1] + rings[i][2] + rings[j][2]
                    if(playerWin(dam, arm) == 1):
                        if cost < lowest_cost:
                            lowest_cost = cost
                    else:
                        if cost > highest_cost:
                            highest_cost = cost



print(lowest_cost)
