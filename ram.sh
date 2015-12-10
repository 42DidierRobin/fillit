while :
	do
		ps aux | grep a.out | grep -v grep | grep -v application
	done
