BEGIN {FS=":"}
{if ($1 ~ /88$/) print $5}
