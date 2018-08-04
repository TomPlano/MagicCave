#!/usr/bin/env bash
#call generator

if [ "$4" == "" ]; then
    echo "Usage: ./MagicCave.sh <xSize> <ySize> <playerlvl> <playercount>"
    exit
fi
printf "Digging the Dungeon: ";
printf "▇";
./Gen.app $1 $2 $3 $4
printf "▇";
#call pdftk

for filename in ./pdf/*.fdf; do
    pdftk ./pdf/TEMPLATE.pdf fill_form "$filename" output "${filename%.*}".pdf
done

#clean up fdfs
for i in `seq 1 10`;
do
        printf "▇";
        sleep 0.1
done

rm ./pdf/*.fdf
printf "▇ : Ding! Adventure Awaits! ";
printf "\n"

