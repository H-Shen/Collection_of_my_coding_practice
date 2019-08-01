# -*- coding: utf-8 -*-
# Test code for Fraction.java, run by
# python3 FractionTest.py3

import os
from fractions import Fraction
from random import randint

TEST_TIME = 100
MIN_VAL = -50
MAX_VAL = 50

try:
    # COMPILE
    os.system("javac -encoding utf8 Fraction.java")
    print("Compiled successfully!")
    # TEST
    print("Total tests: " + str(TEST_TIME))
    for i in range(TEST_TIME):

        numerator0 = randint(MIN_VAL, MAX_VAL)
        denominator0 = randint(MIN_VAL, MAX_VAL)

        numerator1 = randint(MIN_VAL, MAX_VAL)
        denominator1 = randint(MIN_VAL, MAX_VAL)

        s = "java -Dfile.encoding=UTF8 Fraction " + str(numerator0) + " " + str(denominator0) + " " + str(numerator1) + " " + str(denominator1)

        # handle output from Fraction.java
        output0 = os.popen(s).readlines()
        for j in range(len(output0)):
            output0[j] = output0[j].rstrip('\n')

        # handle output here
        output1 = list()
        if (denominator0 == 0 or denominator1 == 0):
            output1.append("java.lang.ArithmeticException: / zero")
        else:
            a = Fraction(numerator0, denominator0)
            b = Fraction(numerator1, denominator1)
            output1.append(str(a + b))
            output1.append(str(a - b))
            output1.append(str(a * b))
            if b == 0:
                output1.append("java.lang.ArithmeticException: / zero")
            else:
                output1.append(str(a / b))

        assert output1 == output0
        print("Test " + str(i + 1) + ":")
        print(output0)
        print(output1)
    print("All tests passed!")
except:
    print("Tests failed!")
finally:
    # CLEAN
    if os.path.exists("Fraction.class"):
        os.remove("Fraction.class")
        print("Fraction.class removed!")
