#!/usr/bin/bash

PLAYER1=$2
PLAYER2=$3
P1WINS=0
P2WINS=0
I=0

while ((I < $1))
do
	ruby filler_vm -r -p1 ${PLAYER1} -p2 ${PLAYER2} -q > /dev/null 2>&1
	winner=`grep won filler.trace`
	if [[ $winner == *${PLAYER1}* ]];
	then
		((P1WINS=P1WINS + 1))
  		printf "%s won!" `basename ${PLAYER1} | cut -d . -f 1`
	else
		((P2WINS=P2WINS + 1))
  		printf "%s won!" `basename ${PLAYER2} | cut -d . -f 1`
	fi
	((I=I + 1))
	sleep 1
	printf "\r%b" "\033[2K"
done

if ((P1WINS>P2WINS));
then
	echo "`basename ${PLAYER1} | cut -d . -f 1` won with score ${P1WINS}:${P2WINS}!"
elif ((P1WINS<P2WINS))
then
	echo "`basename ${PLAYER2} | cut -d . -f 1` won with score ${P2WINS}:${P1WINS}!"
else
	echo "It's a tie ${P2WINS}:${P1WINS}!"
fi
