#!/bin/sh

input="../ex03/hh_positions.csv"
output="hh_uniq_positions.csv"

echo '"name","count"' > "$output"

awk -F, 'NR>1 {
    gsub(/"/, "", $3)
    print $3
}' "$input" | sort | uniq -c | sort -nr | \
awk '{
    count = $1
    name = $2
    for (i=3; i<=NF; i++) {
        name = name " " $i
    }
    printf "\"%s\",%d\n", name, count
}' >> "$output"
