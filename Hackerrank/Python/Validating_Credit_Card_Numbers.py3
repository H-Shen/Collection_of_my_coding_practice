table1 = '0123456789'
table2 = '0123456789-'
table3 = ['0000','1111','2222','3333','4444','5555','6666','7777','8888',
          '9999']

for i in range(int(input())):

    Flag = True
    s = input()

    if not s[0] in ['4', '5', '6']:
        Flag = False

    if Flag == True:

        if len(s) == 16:

            for q in range(16):
                if not s[q] in table1:
                    Flag = False
                    break

            if Flag == True:
                for w in range(13):
                    if s[w:(w + 4)] in table3:
                        Flag = False
                        break

        elif len(s) == 19:

            for q in range(19):
                if not s[q] in table2:
                    Flag = False
                    break

            if Flag == True:
                if s.count('-') != 3:
                    Flag = False
                elif s[4] != '-' or s[9] != '-' or s[14] != '-':
                    Flag = False
                else:
                    Temp = s[0:4] + s[5:9] + s[10:14] + s[-4:]
                    for w in range(13):
                        if Temp[w:(w + 4)] in table3:
                            Flag = False
                            break


        else:
            Flag = False

    if Flag == True:
        print('Valid')
    elif Flag == False:
        print('Invalid')
