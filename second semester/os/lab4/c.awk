BEGIN {suma=0}
{suma = suma + NF}
END {print suma}
