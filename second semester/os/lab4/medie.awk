BEGIN{sum =0;}
{sum+=$0}
END{print sum/NR}
