#!/bin/sh

SIrun=$1
mergedfile=run${SIrun}.dat
rm $mergedfile
for file in $(ls -1 ~/Documents/Cherenkov_Analysis/ascii/run${SIrun}_ascii_*.dat); do cat $file >> $mergedfile; done
