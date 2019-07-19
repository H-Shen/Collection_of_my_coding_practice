x_negative = 0
x_positive = 0
y_negative = 0
y_positive = 0
for i in range(int(input())):
    x, y = map(int, input().split())
    if x == 0:
        if y > y_positive:
            y_positive = y
        elif y < y_negative:
            y_negative = y
    elif y == 0:
        if x > x_positive:
            x_positive = x
        elif x < x_negative:
            x_negative = x
a1 = abs(x_positive - x_negative)
a2 = abs(y_positive - y_negative)
a3 = (x_positive ** 2 + y_positive ** 2) ** 0.5
a4 = (x_positive ** 2 + y_negative ** 2) ** 0.5
a5 = (x_negative ** 2 + y_positive ** 2) ** 0.5
a6 = (x_negative ** 2 + y_negative ** 2) ** 0.5
result = max([a1, a2, a3, a4, a5, a6])
result = "%.6f" % result
print(result)
