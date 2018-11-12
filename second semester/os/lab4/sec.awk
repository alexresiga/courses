BEGIN{FS=":"}
{print $1*3600+$2*60 + $3}
