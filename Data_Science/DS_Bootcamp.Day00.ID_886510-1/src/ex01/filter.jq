["id", "created_at", "name", "has_test", "alternate_url"] as $headers |
$headers,
(
    .items[] | [
        .id,
        .created_at,
        .name,
        .has_test,
        .alternate_url
    ]
) |
@csv
