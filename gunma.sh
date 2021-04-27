arr[1]=" daruma-san ga... ; koronda! ; you moved! "
arr[2]=" だるまさんが... ; ころんだ! ; うごいた! "
arr[3]=" un, deux, trois... ; soleil! ; tu as bougé! "
loc=0
i=0

read -p "language [1.en, 2.ja, 3.fr]: " lang
((lang=(1<=lang && lang<=3 ? lang : 1)))
IFS=";" str=(${arr[$lang]})
read -p "goal distance : " goal
while [ "$goal" -gt "$loc" ]; do
	echo $i $loc ${str[0]}
	read -t 2 l
	((loc+=${#l}))
	l=""
	echo ${str[1]}
	sleep 1
	read -t 1 l
	if [ "${#l}" -gt 0 ]; then
		echo ${str[2]}
		loc=0
	fi
	((++i))
done
echo "you won!"
