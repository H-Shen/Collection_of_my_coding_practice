# Write your MySQL query statement below
select patient_id, patient_name, conditions from Patients
where conditions regexp '^DIAB1' or conditions regexp ' DIAB1';