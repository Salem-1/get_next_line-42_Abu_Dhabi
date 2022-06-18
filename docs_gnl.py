                                                 #Bism Ellah Elra7man El Ra7eem
18th June 2022

It's really strange issue, why do I feel disappointed if I don't know the answer, 
read() seems straight forward, but it's not working as expected, 
Using statistics to malloc the result string seems not to work, 
I will try to realloc the resutl string manually instead of knowing the result upfront.

inshalla
GrowthHacking mindset:
 ---------------------------------------------------------------------------- 
|1-Handle the case of EOF file.                                      | check |
|2-Handle the case of the line_len == Buffer_size -1                 |       |
|3-HAndle the case where the line_len < Buffer_size                  |       |
|4-Face the Villian, and handle the line_len < Buffer_size inshalla. |       |
 ----------------------------------------------------------------------------
