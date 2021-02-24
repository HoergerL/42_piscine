#FT_LINE1=3
#FT_LINE2=7
cat /etc/passwd | grep -v '^#.*' |cut --complement -d':' -f5 | sed -n '2~2p' | cut -d':' -f1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | paste -sd, | sed 's/,/, /g' | sed 's/$/./' | tr -d '\n'