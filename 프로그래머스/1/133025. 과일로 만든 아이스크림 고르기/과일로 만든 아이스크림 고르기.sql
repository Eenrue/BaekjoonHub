-- 코드를 입력하세요
SELECT FLAVOR
FROM FIRST_HALF AS F
WHERE TOTAL_ORDER > 3000 and
EXISTS (SELECT FLAVOR
       FROM ICECREAM_INFO AS I
        WHERE F.FLAVOR=I.FLAVOR and INGREDIENT_TYPE='fruit_based'
       )
ORDER BY TOTAL_ORDER desc