/*
https://www.nowcoder.com/practice/3a303a39cc40489b99a7e1867e6507c5
*/
select category.name, count(film_category.film_id)
from (select category_id, count(film_id)
      from film_category
      group by category_id
      having count(film_id) >= 5) as film_category_subquery,
     film,
     film_category,
     category
where film.description like '%robot%'
  and film.film_id = film_category.film_id
  and category.category_id = film_category.category_id
  and category.category_id = film_category_subquery.category_id
group by film_category_subquery.category_id;