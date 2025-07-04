#!/bin/sh

output="hh_concatenated.csv"

rm -f "$output"

files=$(ls -1v *.csv)

if [ -z "$files" ]; then
    echo "Ошибка: Нет файлов для объединения"
    exit 1
fi

first_file=$(echo "$files" | head -n 1)
cat "$first_file" > "$output"

for file in $files; do
    if [ "$file" = "$first_file" ]; then
        continue
    fi
    
    tail -n +2 "$file" >> "$output"
done
