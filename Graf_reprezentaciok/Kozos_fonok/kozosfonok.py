# elso sor beolvasasa
N, A, B = list(map(int, input().split(" ")))
A -= 1
B -= 1

# ebben taroljuk, hogy kinek ki a fonoke, kezdetben minden -1
bosses = [-1] * N

for i in range(N - 1):
    boss, subordinate = list(map(int, input().split(" ")))

    bosses[subordinate - 1] = boss - 1

# ebben taroljuk, hogy A-nak kik a fonokei
bossesOfA = [False] * N

# itt jarjuk be, es nezzuk meg, hogy kik A fonokei
at = bosses[A]  # hogy magat A-t mar ne ertsuk bele
while at != -1:
    bossesOfA[at] = True

    at = bosses[at]

# itt jarjuk be B fonokeit es keressuk a kozoseket
at = bosses[B]
solution = -1
while at != -1 and solution == -1:
    if bossesOfA[at]:
        solution = at + 1

    at = bosses[at]

print(solution)
