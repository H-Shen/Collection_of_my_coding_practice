# Write your MySQL query statement below
select x,y,z,
       IF(x > 0 and y > 0 and z > 0 and
          x + y > z and x + z > y and z + y > x and
          x - y < z and y - x < z and
          x - z < y and z - x < y and
          y - z < x and z - y < x, 'Yes', 'No') as triangle
from triangle