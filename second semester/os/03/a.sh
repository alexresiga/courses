#!/bin/bash
#monitor all changes in a directory and subdirectories and display the changes detected
#Shell scrips special variable:
# $0 - command name
# $1, ...., $9 - each command line argument
# $* or $@ - all comand line arguments

function dirimg {
	DIR=$1
	DEST=$2
	find $DIR -exec ls -l {} \; > $DEST	
}

dirimg /Users/alex/SO a
