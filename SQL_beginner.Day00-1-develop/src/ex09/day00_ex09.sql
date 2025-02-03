SELECT
     (SELECT person.name from person where id = pv.person_id) AS person_name ,  
     (SELECT pizzeria.name from pizzeria where id = pv.pizzeria_id) AS pizzeria_name  
FROM 

(SELECT * FROM person_visits WHERE visit_date between '2022-01-07' and '2022-01-09')  AS pv 
ORDER BY person_name ASC, pizzeria_name DESC 
