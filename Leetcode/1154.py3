from datetime import datetime

class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        d1 = datetime.strptime(date1, "%Y-%m-%d")
        d2 = datetime.strptime(date2, "%Y-%m-%d")
        return abs((d2-d1).days)
    def dayOfYear(self, date: str) -> int:
        a = date.split('-')
        date2 = a[0] + "-01-01"
        diff = self.daysBetweenDates(date, date2)
        return diff + 1