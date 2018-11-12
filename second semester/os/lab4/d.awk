{if (NR%2==0)
 {suma = 0;
 for(i=1;i<=NF;i++)
 {suma += $i} 
 print suma
 } 
 else 
 {
 suma = 0;
 cate = 0;
 for(i=1;i<=NF;i++)
 {
 suma += $i;
 if ($i ~ "^[0-9]+$")
 {cate++;}
 }
if (cate!=0)
 print suma/cate
else print 0
 }
}
