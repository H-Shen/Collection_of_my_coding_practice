# https://www.nowcoder.com/practice/668603dc307e4ef4bb07bcd0615ea677

try:
    while 1:
        a = raw_input()
        b = []
        currentItem = ""

        length = len(a)
        inQuotation = False

        for i in xrange(length):

            if inQuotation == False and a[i] != ' ' and a[i] != '"':
                currentItem += a[i]

            elif inQuotation == False and a[i] == ' ':
                if currentItem != "":
                    b.append(currentItem)
                    currentItem = ""

            elif inQuotation == False and a[i] == '"':
                inQuotation = True

            elif inQuotation == True and a[i] != '"':
                currentItem += a[i]

            elif inQuotation == True and a[i] == '"':
                b.append(currentItem)
                currentItem = ""
                inQuotation = False

        if currentItem != "":
            b.append(currentItem)

        print len(b)
        for i in b:
            print i
except:
    pass