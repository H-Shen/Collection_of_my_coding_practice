# -*- coding:utf-8 -*-

# https://www.nowcoder.com/practice/5541c433dee04c17ba7774c4a20430de
class ChkBloodType:
    def chkBlood(self, father, mother):
        # write code here
        if {father, mother} == {'O'}:
            return ['O']
        elif {father, mother} == {'A', 'O'}:
            return ['A', 'O']
        elif {father, mother} == {'A'}:
            return ['A', 'O']
        elif {father, mother} == {'A', 'B'}:
            return ['A', 'AB', 'B', 'O']
        elif {father, mother} == {'A', 'AB'}:
            return ['A', 'AB', 'B']
        elif {father, mother} == {'B', 'O'}:
            return ['B', 'O']
        elif {father, mother} == {'B'}:
            return ['B', 'O']
        elif {father, mother} == {'B', 'AB'}:
            return ['A', 'AB', 'B']
        elif {father, mother} == {'AB', 'O'}:
            return ['A', 'B']
        else:
            return ['A', 'AB', 'B']