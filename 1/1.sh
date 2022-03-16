#!/bin/bash

echo "Made by Sakharbekov Ruslan, from Kazakhstan."
echo "Programm name 'Change password'."
echo "The program is needed to set the user password."

while true; do
	echo "Enter username:"
	read username

	if grep $username /etc/passwd
	then
	  while true; do 
	    echo "Enter minimum password age"
	    read min
	    if [[ $min -ge 0 ]] && [[ $min -le 99999 ]] && [[ $min =~ ^[0-9]+$ ]]
	    then
	      break
	    else 
	      echo "min incorrect"
	    fi
	  done
          passwd -n $min $username
	  while true; do
	    echo "Enter maximum password age"
	    read max
	    if [[ $max -ge 0 ]] && [[ $max -le 99999 ]] && [[ $max =~ ^[0-9]+$ ]]
	    then
	      break
	    else
	      echo "max incorrect"
	    fi
	  done
	  passwd -x $max $username

	  echo "Enter new password"
	  read password
	  echo -e "$password\n$password\n" | passwd $username
	  echo "Succefull. Try again (Y/N)"
	  read yn
	  if [ $yn = Y ]
 	  then
	    continue
	  else
	    echo "GoodBye!!!"
	    break
	  fi
	else
	  echo "User not found. Try afain? (Y/N)"
	  read yn
	  if [ $yn = Y ]
	  then
	    continue
	  else
	    echo "Goodbye!!!"
	    break
	  fi
	fi
done

