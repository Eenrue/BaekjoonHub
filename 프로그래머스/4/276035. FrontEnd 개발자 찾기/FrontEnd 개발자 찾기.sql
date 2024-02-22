SELECT DISTINCT(ID), EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPERS D, SKILLCODES S
WHERE SKILL_CODE & CODE = CODE AND CATEGORY="Front End"
ORDER BY ID