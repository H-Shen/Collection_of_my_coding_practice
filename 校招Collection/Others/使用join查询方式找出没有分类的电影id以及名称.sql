/*
https://www.nowcoder.com/practice/a158fa6e79274ac497832697b4b83658
*/
select film.film_id, film.title
from film
where film.film_id not in (
    select film.film_id
    from film,
         category,
         film_category
    where film.film_id = film_category.film_id
      and film_category.category_id = category.category_id
);