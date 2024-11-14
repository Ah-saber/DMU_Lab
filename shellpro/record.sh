#!/bin/bash
# 输出学生考勤情况

filename="./01-cnet/"
echo $filename

list=($(ls ${filename} | sort))

#echo ${list[1]}

length=${#list[@]}
#set length
echo "Total：$length, class: $(expr $length / 2)"

student_cnet=()
for i in $(seq 0 9999)
do
    student_cnet[$i]=0
done


student_soft=()
for i in $(seq 0 9999)
do
    student_soft[$i]=0
done

class=1

for i in $(seq 0 2 ${length-1})
do
    while read -r studentname
    do
        if [[ -z "$studentname" ]] #双括号，支持更多正则等匹配
        then
            continue
        fi
        if [ "$studentname" = "buyhorse" ] #去掉老师的考勤
        then
            continue
        fi
        
        if [[ "$studentname" == *"cnet"* ]] #正则匹配cnet
        then
            id_cnet=$(echo "$studentname" | sed 's/^cnet0*//') #sed去除cnet和前缀0,服务于数组计数
            index=$(expr "$id_cnet")
            if [ "$index" -ge 0 -a "$index" -le 10000 ]
            then
                new=$(expr ${student_cnet[$index]} + 1)
                student_cnet[$index]=$new
            fi
        else
            id_soft=$(echo "$studentname" | sed 's/^soft0*//')
            index=$(expr "$id_soft")
            if [ "$index" -ge 0 -a "$index" -le 10000 ]
            then
                new=$(expr ${student_cnet[$index]} + 1)
                student_soft[$index]=$new
            fi
        fi
        
    done < <(tail -n +3 "${filename}${list[$i]}" "${filename}${list[$i+1]}" | sort | tail -n +6 | awk '{print $1}' | uniq)
    # 原本使用管道，但是会开启一个新的子shell，在子shell更新数组对父shell数据无影响，导致数组一直不更新
    
    echo "${filename}${list[$i]} ${filename}${list[$i+1]}"
done

for i in $(seq 0 9999)
do
    if [ $i -ne 2948 -a ${student_cnet[$i]} -gt 0 ]
    then
        echo "cnet_student:$i  attendance: $(expr ${student_cnet[$i]})"
    fi
done

for i in $(seq 0 9999)
do
    if [ ${student_soft[$i]} -gt 0 ]
    then
        echo "soft_student:$i  attendance: $(expr ${student_soft[$i]})"
    fi
done

echo "My attendance: $(expr ${student_cnet[2948]})"




