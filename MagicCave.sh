#!/usr/bin/env bash
#call generator

if [ "$4" == "" ]; then
    echo "Usage: ./MagicCave.sh <xSize> <ySize> <playerlvl> <playercount>"
    exit
fi

./Gen.app $1 $2 $3 $4

#call pdftk

for filename in ./pdf/*.fdf; do
    pdftk ./pdf/TEMPLATE.pdf fill_form "$filename" output "${filename%.*}".pdf
done

#clean up fdfs

rm ./pdf/*.fdf



