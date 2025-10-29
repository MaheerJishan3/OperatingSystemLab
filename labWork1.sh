#!/bin/bash

echo "Welcome to grade finder!"

echo "Please, enter your score: "
read grade

if [ "$grade" -ge 0 ] && [ "$grade" -le 100 ]; then
	if [ "$grade" -le 100 ] && [ "$grade" -ge 80 ]; then
		echo "You've got an A+. Your grade is 4.0."
	elif [ "$grade" -lt 80 ] && [ "$grade" -ge 75 ]; then
		echo "You've got an A. Your grade is 3.75."
	elif [ "$grade" -lt 75 ] && [ "$grade" -ge 70 ]; then
		echo "You've got an A-. Your grade is 3.5."
	elif [ "$grade" -lt 70 ] && [ "$grade" -ge 65 ]; then
		echo "You've got an B+. Your grade is 3.25."
	elif [ "$grade" -lt 65 ] && [ "$grade" -ge 60 ]; then
		echo "You've got an B. Your grade is 3.0."
	elif [ "$grade" -lt 60 ] && [ "$grade" -ge 55 ]; then
		echo "You've got an B-. Your grade is 2.75."
	elif [ "$grade" -lt 55 ] && [ "$grade" -ge 50 ]; then
		echo "You've got an C+. Your grade is 2.5."
	elif [ "$grade" -lt 50 ] && [ "$grade" -ge 45 ]; then
		echo "You've got an C. Your grade is 2.25."
	elif [ "$grade" -lt 45 ] && [ "$grade" -ge 40 ]; then
		echo "You've got an D. Your grade is 2.0."
	else
		echo "You've got an F. Your grade is 0.0."
	fi
else
	echo "Invalid input. Please, input some number between 0 and 100."
fi
