ARRAY=(a b e k)
cat ${ARRAY[$(($RANDOM % ${#ARRAY[*]}))]}.txt | diff -y j.txt -
