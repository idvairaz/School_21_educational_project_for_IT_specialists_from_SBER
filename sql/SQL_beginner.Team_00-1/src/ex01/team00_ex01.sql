WITH RECURSIVE tour_paths AS (
    SELECT
        CAST('a' AS CHAR(1)) AS current_node,
        ARRAY ['a'] AS tour,
        0 AS total_cost,
        0 AS count
    UNION
    ALL
    SELECT
        tc.point2,
        tour_paths.tour || ARRAY [tc.point2],
        tour_paths.total_cost + tc.cost,
        count + 1
    FROM
        tour_paths
        JOIN travel_costs tc ON tour_paths.current_node = tc.point1
    WHERE
        (NOT tc.point2 = ANY(tour_paths.tour))
        OR tc.point2 = 'a'
),
answer AS (
    SELECT
        total_cost,
        '{' || ARRAY_TO_STRING(tour, ',') || '}' AS tour
    FROM
        tour_paths
    WHERE
        current_node = 'a'
        AND count = 4
        AND tour [3] <> 'a'
    ORDER BY
        total_cost,
        tour
)

SELECT
    *
FROM
    answer
WHERE
    total_cost = (
        SELECT
            MIN(total_cost)
        FROM
            answer
    )
    OR total_cost = (
        SELECT
            MAX(total_cost)
        FROM
            answer
    );