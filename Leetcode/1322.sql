# Write your MySQL query statement below
select distinct y.ad_id,
                IF((select count(x.user_id)
                    from Ads as x
                    where x.ad_id = y.ad_id and (x.action = 'Clicked' or x.action = 'Viewed')) = 0, 0.00, round(
                                   (select count(z.user_id)
                                    from Ads as z
                                    where z.ad_id = y.ad_id and (z.action = 'Clicked')) * 100.0 /
                                   ((select count(z.user_id)
                                     from Ads as z
                                     where z.ad_id = y.ad_id and (z.action = 'Clicked')) + (select count(z.user_id)
                                                                                            from Ads as z
                                                                                            where z.ad_id = y.ad_id
                                                                                              and (z.action = 'Viewed'))),
                                   2)) as ctr
from Ads as y
order by ctr desc, y.ad_id;
