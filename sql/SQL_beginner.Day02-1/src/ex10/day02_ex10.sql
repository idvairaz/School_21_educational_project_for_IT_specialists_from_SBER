SELECT DISTINCT self_person1.name AS person_name1,
                self_person2.name AS person_name2,
                self_person1.address AS common_address
FROM person self_person1
         JOIN person self_person2 ON
             (self_person1.address = self_person2.address AND self_person1.id > self_person2.id)
ORDER BY person_name1, person_name2, common_address;