# https://open.kattis.com/problems/datum
import datetime
d, m = list(map(int, input().split()))
print(datetime.date(2009, m, d).strftime("%A"))
