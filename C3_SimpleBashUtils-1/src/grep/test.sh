#!/bin/bash
file1="1"
file2="2"
file3="3"

./s21_grep  Ira *.txt > $file1
grep  Ira *.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест без флага и *.txt не пройден."
        cat $file3
    else
        echo "Тест без флага и *.txt пройден."
    fi
fi

./s21_grep  ira file2.txt file1.txt > $file1
grep  ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест без флага не пройден."
        cat $file3
    else
        echo "Тест без флага пройден."
    fi
fi

./s21_grep  ira file2.txt > $file1
grep  ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест без флага с одним файлом не пройден."
        cat $file3
    else
        echo "Тест без флага с одним файлом пройден."
    fi
fi

./s21_grep -n ira file2.txt file1.txt > $file1
grep -n ira file2.txt file1.txt > $file2
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

./s21_grep -c ira file2.txt file1.txt > $file1
grep -c ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-c" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-c" пройден."
    fi
fi

./s21_grep -v ira file2.txt file1.txt > $file1
grep -v ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-v" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-v" пройден."
    fi
fi

./s21_grep -e ira file2.txt file1.txt > $file1
grep -e ira file2.txt file1.txt > $file2
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

./s21_grep -l ira file2.txt file1.txt > $file1
grep -l ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-l" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-l" пройден."
    fi
fi

./s21_grep -i Ira file2.txt file1.txt > $file1
grep -i Ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-i" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-i" пройден."
    fi
fi

./s21_grep -s ira file2.txt file1.tx > $file1
grep -s ira file2.txt file1.tx > $file2
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

./s21_grep -h ira file2.txt file1.txt > $file1
grep -h ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-h" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-h" пройден."
    fi
fi

./s21_grep -o ira file2.txt file1.txt > $file1
grep -o ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-o" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-o" пройден."
    fi
fi


./s21_grep -n ira file2.txt > $file1
grep -n ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-n"  одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-n" одним файлом пройден."
    fi
fi

./s21_grep -c ira file2.txt > $file1
grep -c ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-c" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-c" одним файлом пройден."
    fi
fi

./s21_grep -v ira file2.txt > $file1
grep -v ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-v" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-v" одним файлом пройден."
    fi
fi

./s21_grep -e ira file2.txt > $file1
grep -e ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-e" одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-e" одним файлом пройден."
    fi
fi

./s21_grep -l ira file2.txt > $file1
grep -l ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-l"  одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-l" одним файлом пройден."
    fi
fi

./s21_grep -i Ira file2.txt > $file1
grep -i Ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-i" одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-i" одним файлом пройден."
    fi
fi

./s21_grep -s ira file2.tx > $file1
grep -s ira file2.tx > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-s" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-s" одним файлом пройден."
    fi
fi

./s21_grep -h ira file2.txt > $file1
grep -h ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-h" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-h" одним файлом пройден."
    fi
fi

./s21_grep -o ira file2.txt > $file1
grep -o ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-o" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-o" одним файлом пройден."
    fi
fi

./s21_grep -n ira *.txt > $file1
grep -n ira *.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-n" и *.txt не пройден."
        cat $file3
    else
        echo "Тест на флаг "-n" и *.txt пройден."
    fi
fi

./s21_grep -c ira *.txt > $file1
grep -c ira *.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-c" и *.txt не пройден."
        cat $file3
    else
        echo "Тест на флаг "-c" и *.txt пройден."
    fi
fi

./s21_grep -v ira *.txt > $file1
grep -v ira *.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-v" и *.txt не пройден."
        cat $file3
    else
        echo "Тест на флаг "-v" и *.txt пройден."
    fi
fi

./s21_grep -e ira *.txt > $file1
grep -e ira *.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-e" и *.txt не пройден."
        cat $file3
    else
        echo "Тест на флаг "-e" и *.txt пройден."
    fi
fi

./s21_grep -l ira *.txt > $file1
grep -l ira *.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-l" и *.txt не пройден."
        cat $file3
    else
        echo "Тест на флаг "-l" и *.txt пройден."
    fi
fi

./s21_grep -i Ira *.txt > $file1
grep -i Ira *.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-i" и *.txt не пройден."
        cat $file3
    else
        echo "Тест на флаг "-i" и *.txt пройден."
    fi
fi

./s21_grep -s ira *.txt > $file1
grep -s ira *.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-s" и *.txt не пройден."
        cat $file3
    else
        echo "Тест на флаг "-s" и *.txt пройден."
    fi
fi
./s21_grep -h ira *.txt > $file1
grep -h ira *.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-h" и *.txt не пройден."
        cat $file3
    else
        echo "Тест на флаг "-h" и *.txt пройден."
    fi
fi

./s21_grep -o ira *.txt > $file1
grep -o ira *.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-o" и *.txt не пройден."
        cat $file3
    else
        echo "Тест на флаг "-o" и *.txt пройден."
    fi
fi

./s21_grep -iv ira file2.txt > $file1
grep -iv ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-iv" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-iv" одним файлом пройден."
    fi
fi

./s21_grep -iv Ira file2.txt file1.txt > $file1
grep -iv Ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-iv" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-iv" пройден."
    fi
fi

./s21_grep -in ira file2.txt > $file1
grep -in ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-in" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-in" одним файлом пройден."
    fi
fi

./s21_grep -in Ira file2.txt file1.txt > $file1
grep -in Ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-in" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-in" пройден."
    fi
fi

./s21_grep -il ira file2.txt > $file1
grep -il ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-il" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-il" одним файлом пройден."
    fi
fi

./s21_grep -il Ira file2.txt file1.txt > $file1
grep -il Ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-il" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-il" пройден."
    fi
fi

./s21_grep -is ira file2.txt > $file1
grep -is ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-is" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-is" одним файлом пройден."
    fi
fi

./s21_grep -is Ira file2.txt file1.txt > $file1
grep -is Ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-is" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-is" пройден."
    fi
fi

./s21_grep -ih ira file2.txt > $file1
grep -ih ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-ih" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-ih" одним файлом пройден."
    fi
fi

./s21_grep -ih Ira file2.txt file1.txt > $file1
grep -ih Ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-ih" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-ih" пройден."
    fi
fi

./s21_grep -ic ira file2.txt > $file1
grep -ic ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-ic" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-ic" одним файлом пройден."
    fi
fi

./s21_grep -ic Ira file2.txt file1.txt > $file1
grep -ic Ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-ic" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-ic" пройден."
    fi
fi

./s21_grep -io ira file2.txt > $file1
grep -io ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-io" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-io" одним файлом пройден."
    fi
fi

./s21_grep -io Ira file2.txt file1.txt > $file1
grep -io Ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-io" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-io" пройден."
    fi
fi

./s21_grep -ie ira file2.txt > $file1
grep -ie ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-ie" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-ie" одним файлом пройден."
    fi
fi

./s21_grep -ie Ira file2.txt file1.txt > $file1
grep -ie Ira file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-ie" не пройден."
        cat $file3
    else
        echo "Тест на флаг "-ie" пройден."
    fi
fi

./s21_grep -ne ira file2.txt > $file1
grep -ne ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-ne" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-ne" одним файлом пройден."
    fi
fi

./s21_grep -ce ira file2.txt > $file1
grep -ce ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-ce" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-ce" одним файлом пройден."
    fi
fi
./s21_grep -ln ira file2.txt > $file1
grep -ln ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-ln" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-ln" одним файлом пройден."
    fi
fi

./s21_grep -cne ira file2.txt > $file1
grep -cne ira file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-cne" с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-cne" одним файлом пройден."
    fi
fi

./s21_grep -o i* file2.txt file1.txt > $file1
grep -o i* file2.txt file1.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-o"  и i* не пройден."
        cat $file3
    else
        echo "Тест на флаг "-o"  и i* пройден."
    fi
fi

./s21_grep -o i* file2.txt > $file1
grep -o i* file2.txt > $file2
diff -a $file1 $file2 > $file3
if [ -f "$file3" ]; then
    filesize=$(wc -c < "$file3")
    if [ $filesize -gt 0 ]; then
        echo "Тест на флаг "-o" и i с одним файлом не пройден."
        cat $file3
    else
        echo "Тест на флаг "-o" и i c одним файлом пройден."
    fi
fi










