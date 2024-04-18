#!/bin/bash
file1="1"
file2="2"
file3="3"

./s21_cat -n file1.txt file.txt  file2.txt > $file1
cat -n file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-n" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-n" пройден."
    fi
fi    

./s21_cat -b file1.txt file.txt  file2.txt > $file1
cat -b file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-b" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-b" пройден."
    fi
fi  

./s21_cat -s file1.txt file.txt  file2.txt > $file1
cat -s file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-s" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-s" пройден."
    fi
fi  

./s21_cat -E file1.txt file.txt  file2.txt > $file1
cat -E file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-E" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-E" пройден."
    fi
fi  

./s21_cat -T file1.txt file.txt  file2.txt > $file1
cat -T file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-T" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-T" пройден."
    fi
fi  

./s21_cat -t file1.txt file.txt  file2.txt > $file1
cat -t file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-t" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-t" пройден."
    fi
fi  

./s21_cat -e file1.txt file.txt  file2.txt > $file1
cat -e file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-e" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-e" пройден."
    fi
fi  

./s21_cat --number-nonblank file1.txt file.txt  file2.txt > $file1
cat --number-nonblank file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "--number-nonblank" не пройден."
        cat $file3
    else
        echo "Тест на флаг "--number-nonblank" пройден."
    fi
fi  

./s21_cat --number file1.txt file.txt  file2.txt > $file1
cat --number file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "--number" не пройден."
        cat $file3
    else
        echo "Тест на флаг "--number" пройден."
    fi
fi  

./s21_cat --squeeze-blank file1.txt file.txt  file2.txt > $file1
cat --squeeze-blank file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "--squeeze-blank" не пройден."
        cat $file3
    else
        echo "Тест на флаг "--squeeze-blank" пройден."
    fi
fi  

./s21_cat -n -e file1.txt file.txt  file2.txt > $file1
cat -n -e file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -n -e не пройден."
        cat $file3
    else
        echo "Тест на флаги -n -e пройден."
    fi
fi  

./s21_cat -n -s file1.txt file.txt  file2.txt > $file1
cat -n -s file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -n -s не пройден."
        cat $file3
    else
        echo "Тест на флаги -n -s пройден."
    fi
fi  

./s21_cat -n -T file1.txt file.txt  file2.txt > $file1
cat -n -T file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -n -T не пройден."
        cat $file3
    else
        echo "Тест на флаги -n -T пройден."
    fi
fi  

./s21_cat -n -t file1.txt file.txt  file2.txt > $file1
cat -n -t file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -n -t не пройден."
        cat $file3
    else
        echo "Тест на флаги -n -t пройден."
    fi
fi  

./s21_cat -n -E file1.txt file.txt  file2.txt > $file1
cat -n -E file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -n -E не пройден."
        cat $file3
    else
        echo "Тест на флаги -n -E пройден."
    fi
fi  

./s21_cat -b -e file1.txt file.txt  file2.txt > $file1
cat -b -e file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -b -e не пройден."
        cat $file3
    else
        echo "Тест на флаги -b -e пройден."
    fi
fi  

./s21_cat -b -s file1.txt file.txt  file2.txt > $file1
cat -b -s file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -b -s не пройден."
        cat $file3
    else
        echo "Тест на флаги -b -s пройден."
    fi
fi  

./s21_cat -b -T file1.txt file.txt  file2.txt > $file1
cat -b -T file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -b -T не пройден."
        cat $file3
    else
        echo "Тест на флаги -b -T пройден."
    fi
fi  

./s21_cat -b -t file1.txt file.txt  file2.txt > $file1
cat -b -t file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -b -t не пройден."
        cat $file3
    else
        echo "Тест на флаги -b -t пройден."
    fi
fi  

./s21_cat -b -E file1.txt file.txt  file2.txt > $file1
cat -b -E file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -b -E не пройден."
        cat $file3
    else
        echo "Тест на флаги -b -E пройден."
    fi
fi  

./s21_cat -b -s -E file1.txt file.txt  file2.txt > $file1
cat -b -s -E file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -b -s -E не пройден."
        cat $file3
    else
        echo "Тест на флаги -b -s -E пройден."
    fi
fi  

./s21_cat -b -s -T file1.txt file.txt  file2.txt > $file1
cat -b -s -T file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -b -s -T не пройден."
        cat $file3
    else
        echo "Тест на флаги -b -s -T пройден."
    fi
fi

./s21_cat -b -s -e file1.txt file.txt  file2.txt > $file1
cat -b -s -e file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -b -s -e не пройден."
        cat $file3
    else
        echo "Тест на флаги -b -s -e пройден."
    fi
fi

./s21_cat -b -s -t file1.txt file.txt  file2.txt > $file1
cat -b -s -t file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -b -s -t не пройден."
        cat $file3
    else
        echo "Тест на флаги -b -s -t пройден."
    fi
fi

./s21_cat -n -s -E file1.txt file.txt  file2.txt > $file1
cat -n -s -E file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -n -s -E не пройден."
        cat $file3
    else
        echo "Тест на флаги -n -s -E пройден."
    fi
fi  

./s21_cat -n -s -T file1.txt file.txt  file2.txt > $file1
cat -n -s -T file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -n -s -T не пройден."
        cat $file3
    else
        echo "Тест на флаги -n -s -T пройден."
    fi
fi

./s21_cat -n -s -e file1.txt file.txt  file2.txt > $file1
cat -n -s -e file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -n -s -e не пройден."
        cat $file3
    else
        echo "Тест на флаги -n -s -e пройден."
    fi
fi

./s21_cat -n -s -t file1.txt file.txt  file2.txt > $file1
cat -n -s -t file1.txt file.txt  file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаги -n -s -t не пройден."
        cat $file3
    else
        echo "Тест на флаги -n -s -t пройден."
    fi
fi