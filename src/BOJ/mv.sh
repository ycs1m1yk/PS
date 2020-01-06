#!/bin/bash

find ./DP | while read input 
do 
    name=`basename $input`
    filename="${name%.*}"
    if [ $filename -ge 1000 -a $filename -lt 20000 ]
    then
        in_range()
        {
            thousand_times=`expr $1 / 1000`
            return $thousand_times
        }
        in_range $filename
        result=$?

        move_dir()
        {
            file=$1
            dst_name=`expr $2 \* 1000`
            dst=$dst_name'/'
            mv $file $dst
        }
        move_dir $input $result
    fi
done