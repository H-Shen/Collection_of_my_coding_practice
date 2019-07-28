while read string
    do
        echo "$string" | cut -c 2-7
    done