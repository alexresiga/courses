{
 for (i= 0; i < NF; ++i)
	{
		if ($i ~ /^Tudor$/) print $0
	}
}
