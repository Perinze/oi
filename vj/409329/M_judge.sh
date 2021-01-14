for i in {1..200}; do
	for j in {1..200}; do
		echo "1 $i $j" | ./M > M.out
		echo "1 $i $j" | ./M_re > M_re.out
		different=`diff M.out M_re.out`
		if [ different ]; then
			echo "different found at i, j = $i, $j"
			echo $different
		fi
	done
done
printf "no different found\n"
