BEGIN{FS=":"}
{if ($1 ~ /^m/ && $3 %7 == 0) print $5 }
