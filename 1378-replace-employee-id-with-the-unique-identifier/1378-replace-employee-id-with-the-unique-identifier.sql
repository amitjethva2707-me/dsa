SELECT 
    unique_id,
    name
FROM Employees e
LEFT JOIN EmployeeUni eu
ON e.id = eu.id;