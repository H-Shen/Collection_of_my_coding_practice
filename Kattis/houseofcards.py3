# https://open.kattis.com/problems/houseofcards

h0 = int(input())
h = h0
while True:
    if (h % 8 == 0):
        break
    if ((h - 5) % 8 == 0):
        break
    h += 1
print(h)
