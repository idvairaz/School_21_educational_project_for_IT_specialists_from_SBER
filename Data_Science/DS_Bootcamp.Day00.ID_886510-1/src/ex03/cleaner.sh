#!/bin/sh

echo '"id","created_at","name","has_test","alternate_url"' > hh_positions.csv

tail -n +2 ../ex02/hh_sorted.csv | \
awk -F, '
function extract_level(name) {
    level = ""
    
    if (match(tolower(name), /junior/)) {
        level = "Junior"
    }
    
    if (match(tolower(name), /middle/)) {
        if (level != "") level = level "/"
        level = level "Middle"
    }
    
    if (match(tolower(name), /senior/)) {
        if (level != "") level = level "/"
        level = level "Senior"
    }
    
    if (level == "") {
        level = "-"
    }
    
    return level
}

{
    gsub(/^"|"$/, "", $1)  # id
    gsub(/^"|"$/, "", $2)  # created_at
    gsub(/^"|"$/, "", $3)  # name
    gsub(/^"|"$/, "", $5)  # alternate_url
    
    level = extract_level($3)
    

    printf "\"%s\",\"%s\",\"%s\",%s,\"%s\"\n", $1, $2, level, $4, $5
}' >> hh_positions.csv
