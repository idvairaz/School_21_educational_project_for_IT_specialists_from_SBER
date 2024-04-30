SELECT DISTINCT person.name
FROM person
JOIN person_order po on person.id = po.person_id
ORDER BY name;