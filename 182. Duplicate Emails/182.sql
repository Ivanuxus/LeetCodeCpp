select Email from (SELECT COUNT(*) as count, email as Email
FROM Person
GROUP BY email
having count(*)>1)