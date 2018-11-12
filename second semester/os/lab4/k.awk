BEGIN {FS=":"}
{ if ( $3 ~ /^23[0-9]$/) print $5}
