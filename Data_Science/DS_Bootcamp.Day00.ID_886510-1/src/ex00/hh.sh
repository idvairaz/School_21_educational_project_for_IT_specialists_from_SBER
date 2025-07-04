#!/bin/sh

if [ $# -eq 0 ]; then
    echo "Ошибка: Не указана поисковая фраза - название вакансии" >&2
    echo "Как надо: $0 \"название вакансии\"" >&2
    exit 1
fi

SEARCH_TEXT="$*"

SEARCH_STRING="\"$SEARCH_TEXT\""


ENCODED_TEXT=$(echo "$SEARCH_STRING" | jq -Rr @uri)


URL="https://api.hh.ru/vacancies?text=name:($ENCODED_TEXT)&per_page=20"

curl -k -H "User-Agent: hh-searcher-pennytrg/1.0" "$URL" | jq '.' > hh.json
