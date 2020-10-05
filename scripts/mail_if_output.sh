#!/bin/bash

# 
##############
#   HOWTO
##############
# call:
# :~$ <script>  | bash  mail_if_output.sh RECIPIENT@HOST.com
# :~$ echo "TESTINHALT" | bash  mail_if_output.sh RECIPIENT@HOST.com
#
# versendet eine Mail an RECIPIENT@HOST.com wenn durch PIPE erhaltener Text nicht leer ist.
# Man kann auch nur STDERR als Input umleiten, dann wird im Successfall keine Mail verschickt: <script> 2>&1 > /dev/null | bash  mail_if_output.sh RECIPIENT@HOST.com
# Beispiele:
# a)  ping goojjjjgle.de  -c 3 2>&1 > /dev/null  | bash  mail_if_output.sh RECIPIENT@HOST.com
# b)  bash dev2.div.onlinekurslabor.de/web/scripts/drupalgeddon_react.sh   2>&1 > /dev/null  | bash dev2.div.onlinekurslabor.de/web/scripts/mail_if_output.sh RECIPIENT@HOST.com


# input_from_pipe: this is what we get from$: ping goojjjjgle.de  -c 3 2>&1 > /dev/null  | bash  mail_if_output.sh RECIPIENT@HOST.com
# "read" stops at first \n
input_from_pipe=$(</dev/stdin)

#echo "You entered '$input_from_pipe'"

#echo "ALL ARGUMENTS"
#for arg in "$@"
#do
#    echo "$arg"
#done

if [ "$input_from_pipe" = ""  ] ;
then
 echo "No Mail to send. No error received."
 exit 0;
fi

echo  "$input_from_pipe" | mail -s 'OKL Emergency' -a 'From: Onlinekurslabor CRON <onlinekurslabor@medienlabor-uni-augsburg.de>' $1 

echo "Mail was sent to recipients: $1"
echo "Mail-body: $input_from_pipe"
exit 0;

# parameter 1: emailadressen; splitte bei ","
IFS=',' read -ra ADDR <<< "$1"
for mailaddi in "${ADDR[@]}"; do
   echo "$mailaddi"
done 