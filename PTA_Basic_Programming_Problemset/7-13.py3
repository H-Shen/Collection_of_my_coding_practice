from decimal import Decimal

Open, High, Low, Close =  list(map(Decimal, input().split()))

s = ""
if Close < Open:
    s += "BW-Solid"
elif Close > Open:
    s += "R-Hollow"
else:
    s += "R-Cross"

if (Low < Open and Low < Close) and not (High > Open and High > Close):
    s += " with Lower Shadow"
if (High > Open and High > Close) and not (Low < Open and Low < Close):
    s += " with Upper Shadow"
if (Low < Open and Low < Close) and (High > Open and High > Close):
    s += " with Lower Shadow and Upper Shadow"

print(s)