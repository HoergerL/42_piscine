#FT_NBR1=\\\'\?\"\\\"\'\\
#FT_NBR1=\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"
#FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo
#FT_NBR2=rcrdmddd
#echo $FT_NBR1
#echo $FT_NBR2
basedFT1=$( echo $FT_NBR1 | tr "\'\\\\\"?\!" "01234")
basedFT2=$( echo $FT_NBR2 | tr "mrdoc" "01234")
#echo $basedFT1
#echo $basedFT2
sum=$( echo "obase=13;ibase=5; $basedFT1+$basedFT2" | bc)

#echo $sum

result=$(echo $sum | tr "0123456789ABC" "gtaio luSnemf")

echo "$result"
