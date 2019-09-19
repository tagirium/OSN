flag=1
while [[ flag -eq 1 ]]; do
	ls > ls.txt
	if [[ `test flag.txt ls.txt` -eq 0 ]]; then
		touch flag.txt
		for (( i = 0; i < 100; i++ )); do
			a=`tail -1 ./ex2.txt`
			a=`echo "$a+1" | bc`
			b=`cat ./ex2.txt`
			echo -e "$b\n$a" > ./ex2.txt
		done
		rm flag.txt
		flag=0
	fi
done
rm ls.txt