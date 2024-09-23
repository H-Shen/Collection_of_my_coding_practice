/*
https://www.nowcoder.com/practice/2f2e556d335d469f96b91b212c4c203e
*/
select film.title, film.description
from film,
     category,
     film_category
where film.film_id = film_category.film_id
  and film_category.category_id = category.category_id
  and category.name = 'Action';