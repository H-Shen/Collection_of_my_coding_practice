# Write your MySQL query statement below
select y.Score, z.`Rank`
from Scores as y
         inner join
     (select x.Score, @curRank := @curRank + 1 as `Rank`
      from (select distinct Score from Scores order by Score desc) as x
         , (select @curRank := 0) t) as z
     on y.Score = z.Score
order by z.`Rank`;