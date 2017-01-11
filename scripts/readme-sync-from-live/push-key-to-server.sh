#!/bin/bash

#
# pushkey
#
# usage:
#
#	pushkey username@remotemachine.domain.com
#
# This script was originally written by Greg Anderson
# http://drupal.org/user/438598
#
# Permission is granted to use, redistribute and 
# make derived works without restriction.
#

localMachine=`uname -n`
localUser=$USER
localHome=$HOME
if [ "X$localUser" = "Xroot" ] ; then
	localHome=/root
fi

#
# Parse parameters
#
while [ $# -gt 0 ] ; do

	option=$1
	shift
	
	case "$option" in
		--remotehome )
			remotehome=$1
			shift
			;;
			
		-* )
			echo "Unknown option $option" 1>&2
			exit 1
			;;
		
		* )
			targetMachine=$option
			;;
	esac
done

echo
echo "This machine will push your SSH public key to the"
echo "target machine specified on the command line."
echo
echo "If you do not have an SSH key pair, then this"
echo "script will generate one.  You will be prompted"
echo "for a password to protect your private key.  You"
echo "should leave the password empty if you plan on"
echo "using the key from a script (e.g. a cron backup"
echo "script)--but be sure you are aware of the security"
echo "implications if you do so."
echo
echo "You will need to enter your password for the"
echo "remote machine in order to copy over your"
echo "public key and add it to the list of allowed keys."
echo

#
# Error out if a target machine is not specified
#
if [ "X$targetMachine" = "X" ] ; then
	echo "Target machine not specified." 1>&2
	exit 1
fi

#
# Try to determine who the remote user is by looking at
# the target machine.  If a user was not specified in
# the target, then assume that the remote user will be
# the same as the local user.
#
if [ X`echo "$targetMachine" | grep "@"` \!= "X" ] ; then
	remoteuser=${targetMachine/@*/}
	targetMachineWithUser=$targetMachine
else
	remoteuser=$localUser
	targetMachineWithUser=$localUser"@"$targetMachine
fi

if [ "x$remotehome" == "x" ] ; then

remotehome=/home/$remoteuser
if [ "X$remoteuser" = "Xroot" ] ; then
	remotehome=/root
fi

fi

#
# Before we can push a key, we need to
# have one.  Make one if it's not already there.
#
if [ ! -f $localHome/.ssh/id_rsa ] ; then
	ssh-keygen -t rsa -f $localHome/.ssh/id_rsa
fi

pubkey=`cat $localHome/.ssh/id_rsa.pub`

echo "Please enter password for $targetMachineWithUser to add $localMachine to authorized keys."
echo "(echo $pubkey > $remotehome/.ssh/${localMachine}_id_rsa.pub) && (cat $remotehome/.ssh/${localMachine}_id_rsa.pub >> $remotehome/.ssh/authorized_keys) && chmod 600 $remotehome/.ssh/authorized_keys"
ssh $targetMachineWithUser /bin/sh -c "'(echo $pubkey > $remotehome/.ssh/${localMachine}_id_rsa.pub) && (cat $remotehome/.ssh/${localMachine}_id_rsa.pub >> $remotehome/.ssh/authorized_keys) && chmod 600 $remotehome/.ssh/authorized_keys'"
