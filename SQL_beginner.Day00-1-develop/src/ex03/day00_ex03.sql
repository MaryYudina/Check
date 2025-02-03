select DISTINCT person_id from person_visits
where visit_date BETWEEN '2022-01-06' and '2022-01-09' or id ='2'
order by person_id DESC 