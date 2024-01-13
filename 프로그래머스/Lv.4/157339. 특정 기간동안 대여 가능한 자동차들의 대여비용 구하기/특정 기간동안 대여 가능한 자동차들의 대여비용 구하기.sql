-- 코드를 입력하세요
SELECT C.CAR_ID, C.CAR_TYPE,	 FLOOR(30*DAILY_FEE*(1-DISCOUNT_RATE/100)) AS FEE
FROM CAR_RENTAL_COMPANY_CAR C JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN D
ON C.CAR_TYPE=D.CAR_TYPE
WHERE CAR_ID NOT IN (
    SELECT CAR_ID
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY 
    WHERE '2022-11' BETWEEN DATE_FORMAT(START_DATE,'%Y-%m') AND DATE_FORMAT(END_DATE,'%Y-%m') 
)
AND D.DURATION_TYPE LIKE '30%' 
AND C.CAR_TYPE REGEXP '세단|SUV'
GROUP BY C.CAR_ID
HAVING FEE BETWEEN 500000 AND 2000000
ORDER BY FEE DESC, C.CAR_TYPE, C.CAR_ID DESC