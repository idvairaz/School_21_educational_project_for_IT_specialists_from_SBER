SELECT person.name, count(person_visits.id) AS count_of_visits
FROM person_visits
         JOIN person on person.id = person_visits.person_id
GROUP BY person.name
ORDER BY count_of_visits DESC, person.name
LIMIT 4;