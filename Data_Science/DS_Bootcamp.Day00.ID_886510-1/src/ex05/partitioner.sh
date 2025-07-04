#!/bin/sh

input="../ex03/hh_positions.csv"

if [ ! -f "$input" ]; then
    echo "Ошибка: Файл $input не найден"
    exit 1
fi

line_number=0
while IFS= read -r line; do
    line_number=$((line_number + 1))
    
    if [ "$line_number" -eq 1 ]; then
        header="$line"
        continue
    fi

    date=$(echo "$line" | awk -F, '{
        gsub(/"/, "", $2)
        print substr($2, 1, 10)
    }')
    
    if [ -z "$date" ]; then
        continue
    fi
    
    output_file="${date}.csv"
    
    if [ ! -f "$output_file" ]; then
        echo "$header" > "$output_file"
    fi
    
    echo "$line" >> "$output_file"
done < "$input"
