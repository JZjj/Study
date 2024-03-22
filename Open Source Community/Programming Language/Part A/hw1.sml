(*1*)	     
    
fun is_older (x:int*int*int, y:int*int*int) =
    if(#1 x) < (#1 y)
    then true
    else if (#1 x) = (#1 y) andalso (#2 x) < (#2 y)
    then true
    else if (#1 x) = (#1 y) andalso (#2 x) = (#2 y) andalso (#3 x) < (#3 y)
    then true
    else
	false

(*2*)

fun number_in_month (x:(int*int*int) list, y:int) =
    if null x
    then 0
    else if #2 (hd x) = y
    then 1 + number_in_month(tl x,y)
    else number_in_month(tl x,y)

(*3*)			
	     
fun number_in_months (x:(int*int*int) list, y:int list) =
    if null y
    then 0
    else number_in_month(x, hd y) + number_in_months(x, tl y)
						    
(*4*)

fun dates_in_month (x:(int*int*int) list, y:int) =
    if null x
    then []
    else if #2 (hd x) = y
    then (hd x) :: dates_in_month(tl x,y)
    else dates_in_month (tl x,y)

(*5*)
fun dates_in_months (x:(int*int*int) list, y:int list) =
    if null y
    then []
    else dates_in_month (x,hd y) @ dates_in_months(x,tl y)

(*6*)        
fun get_nth (x:string list,y:int) =
    if y = 1
    then hd x
    else get_nth(tl x, y-1)

(*7*)  
fun date_to_string (x:int*int*int) =
    get_nth(["January", "February", "March", "April",
	     "May", "June", "July",
	     "August", "September", "October", "November", "December"],
	    #2 x)^" "^Int.toString(#3 x)^", "^Int.toString(#1 x)														      
	       
fun number_before_reaching_sum (sum:int, x:int list) =
    if sum <= hd x
    then 0
    else 1 + number_before_reaching_sum(sum-(hd x), tl x)

				       
fun what_month (x:int) =
    let
	val month_days = [31,28,31,30,31,30,31,31,30,31,30,31]
    in
	number_before_reaching_sum(x, month_days)+1
    end

fun month_range (day1:int,day2:int) =
    if day1 > day2
    then []
    else if day1 = day2+1
    then [what_month(day2)]
    else what_month(day1) :: month_range(day1+1,day2)
					
