#!/bin/bash

if [[ $(uname) == Linux  ]]
then
		  if [[ -d "/usr/include/readline" ]]
		  then
					 :
		  else
					 sudo apt-get install libreadline-dev -y
		  fi
fi
