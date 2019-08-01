# -*- coding: utf-8 -*-
# Test code for Fraction.java, run by
# python3 FractionTest.py3

import os
from fractions import Fraction
from random import randint

TEST_TIME = 100
MIN_VAL = -200000
MAX_VAL = 200000

try:
    # COMPILE
    os.system("javac -encoding utf8 Fraction.java")
    print("Compiled successfully!")
    # TEST
    print("Total tests: " + str(TEST_TIME))
    for i in range(TEST_TIME):
        numerator = randint(MIN_VAL, MAX_VAL)
        while True:
            denominator = randint(MIN_VAL, MAX_VAL)
            if denominator != 0:
                break
        s = "java -Dfile.encoding=UTF8 Fraction " + str(numerator) + " " + str(denominator)
        output0 = os.popen(s).read().rstrip('\n')
        output1 = str(Fraction(numerator, denominator))
        assert output0 == output1
        print("Test " + str(i + 1) + ": " + output0 + " " + output1)
    print("All tests passed!")
except:
    print("Tests failed!")
finally:
    # CLEAN
    if os.path.exists("Fraction.class"):
        os.remove("Fraction.class")
        print("Fraction.class removed!")
